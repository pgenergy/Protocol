#ifndef ENERGYLEAF_V1_DETECTOR
#define ENERGYLEAF_V1_DETECTOR

#include <esp_camera.h>
#include <fb_gfx.h>

#include "Arduino.h"
#include "Calculator.hpp"
#include "Camera.hpp"
#include "CameraLED.hpp"
#include "Crop.hpp"
#include "RGBtoHSV.hpp"
#include "Sender.hpp"
#include "State.hpp"
#include "StatusLED.hpp"
#include "Window.hpp"

namespace Energyleaf::V1 {
class Detector {
   public:
    explicit Detector()
        : vInitialized(false),
          vAfterPushCall(false),
          vGenerateJpegCall(false),
          vCameraLED(4, 2, 15),
          vStatusLED(33),
          vCrop(120, 0, 60, 0),
          vCamera(),
          vSender(),
          vUseWithWebServer(false) {
        vState.setFunction(stateEvaluateFunction);
        vCalculator.setRotationPerkWh(375);
        vSender.setHost("google.de");
        vSender.setPort(443);
        vSender.setEndpoint("/");
        vSender.setSensorId(WiFi.macAddress().c_str());
    }

    virtual ~Detector() { this->deinitialize(); }

    void setAfterPushCall(bool afterPushCall) {
        this->vAfterPushCall = afterPushCall;
    }

    void setGenerateJpegCall(bool generateJpegCall) {
        this->vGenerateJpegCall = generateJpegCall;
    }

    void push() {
        if (!this->vInitialized) {
            throw std::runtime_error("Detector is not initialized!");
        }
        fb = this->vCamera.getFramebuffer();
        if (!fb) {
            Serial.println("Camera capture failed");
            throw std::runtime_error("Camera capture failed!");
        } else {
            bool validJpeg = false;
            if (fb->len >= 2 && fb->buf[0] == 0xFF && fb->buf[1] == 0xD8) {
                if (fb->buf[fb->len - 2] == 0xFF &&
                    fb->buf[fb->len - 1] == 0xD9) {
                    validJpeg = true;
                } else {
                    Serial.println("JPEG EOI marker not found (End of Image)");
                    validJpeg = false;
                }
            } else {
                Serial.println("JPEG SOI marker not found (Start of Image)");
                validJpeg = false;
            }
            if (!validJpeg) {
                this->vCamera.returnFramebuffer(fb);
                fb = this->vCamera.getFramebuffer();
                log_d("Camera capture failed in first try. Using second try!");
                if (!fb) {
                    throw std::runtime_error(
                        "Camera capture failed in second try!");
                }
            }
            bool s = fmt2rgb888(fb->buf, fb->len, fb->format, out_buf);
            if (fb) {
                this->vCamera.returnFramebuffer(fb);
                fb = nullptr;
            }
            if (!s) {
                throw std::runtime_error("Could not convert frame to rgb888!");
            }

            fb_data_t rfb;
            rfb.width = out_width;
            rfb.height = out_height;
            rfb.data = out_buf;
            rfb.bytes_per_pixel = 3;
            rfb.format = FB_BGR888;
            if (rfbcrop.data) {
                free(rfbcrop.data);
                rfbcrop.data = nullptr;
            }

            this->vCrop.crop(rfb, rfbcrop);
            int foundPixel = 0;
            for (int i = 0; i < (rfbcrop.width * rfbcrop.height); ++i) {
                int index = i * rfbcrop.bytes_per_pixel;
                // Convert RGB to HSV
                Energyleaf::V1::Visual::RGBPixel rgbPixel;
                rgbPixel.r = rfbcrop.data[index];
                rgbPixel.g = rfbcrop.data[index + 1];
                rgbPixel.b = rfbcrop.data[index + 2];
                Energyleaf::V1::Visual::HSVPixel hsvPixel;
                vRGBtoHSV.convert(rgbPixel, hsvPixel);
                if (vGenerateJpegCall) {
                    rfbcrop.data[index] = hsvPixel.h;
                    rfbcrop.data[index + 1] = hsvPixel.s;
                    rfbcrop.data[index + 2] = hsvPixel.v;
                }

                // Check if the pixel is in the red color range in HSV space
                if ((hsvPixel.h >= HMIN && hsvPixel.h <= HMAX) &&
                    (hsvPixel.s >= SMIN && hsvPixel.s <= SMAX) &&
                    (hsvPixel.v >= VMIN && hsvPixel.v <= VMAX)) {
                    ++foundPixel;
                }
            }

            bool internalState = foundPixel > THRESHOLD_RED_STRIPE;

            if (vState.isReady()) {
                vState.push(internalState);
                if (internalState && vState.getOutput()) {
                    Serial.println("Red stripe found.");
                    this->vStatusLED.enable();
                    vCalculator.push();
                } else if (!internalState && vState.getOutput()) {
                    Serial.println("No Red stripe found.");
                    this->vStatusLED.disable();
                }
            } else {
                vState.setState(internalState);
                if (internalState) {
                    Serial.println("Red stripe found.");
                    this->vStatusLED.enable();
                    vCalculator.push();
                } else {
                    Serial.println("No Red stripe found.");
                    this->vStatusLED.disable();
                }
            }

            if (vCalculator.isProcessed()) {
                Serial.print("Power:");
                Serial.print(vCalculator.getPower(vUseWithWebServer));
                Serial.println(" Watt per MS");
                if (!vUseWithWebServer) {
                    try {
                        vSender.push(vCalculator.getPower(true));
                    } catch (std::runtime_error &er) {
                        Serial.println(er.what());
                    }
                }
            }

            if (vGenerateJpegCall) {
                generateJpeg();
            }
        }
        if (vAfterPushCall) {
            this->afterPush();
        }
    }

    void generateJpeg() {
        if (!fmt2jpg(rfbcrop.data,
                     rfbcrop.width * rfbcrop.height * rfbcrop.bytes_per_pixel,
                     rfbcrop.width, rfbcrop.height, PIXFORMAT_RGB888, 80,
                     &_jpg_buf, &_jpg_buf_len)) {
            Serial.println("JPEG conversion failed");
            throw std::runtime_error("JPEG conversion failed");
        }
    }

    void setUseWithWebServer(bool value) {
        this->vUseWithWebServer = value;
    }

    void deinitialize() {
        if (out_buf) {
            free(out_buf);
            out_buf = nullptr;
        }

        if (rfbcrop.data) {
            free(rfbcrop.data);
            rfbcrop.data = nullptr;
        }

        if (fb) {
            this->vCamera.returnFramebuffer(fb);
            fb = nullptr;
        }

        if (_jpg_buf) {
            free(_jpg_buf);
            _jpg_buf = nullptr;
        }

        this->vCameraLED.disable();
        this->vStatusLED.disable();

        this->vInitialized = false;
    }

    void initialize() {
        if (this->vInitialized) {
            throw std::runtime_error("Detector already initialized");
        }
        if (!this->vCamera.isInitialized()) {
            this->vCamera.initialize();
        }
        fb = NULL;
        _jpg_buf_len = 0;
        _jpg_buf = NULL;
        out_len = 320 * 240 * 3;
        out_width = 320;
        out_height = 240;
        rfbcrop.data = nullptr;
        out_buf = nullptr;
        if (!out_buf) {
            out_buf = (uint8_t *)malloc(out_len);
            if (!out_buf) {
                log_e("Failed to allocate memory for out_buf");
                throw std::runtime_error(
                    "Failed to allocate memory for out_buf");
            }
        }
        this->vCameraLED.enable();
        vTaskDelay(150 / portTICK_PERIOD_MS);
        this->vInitialized = true;
    }

    void afterPush() {
        if (fb) {
            esp_camera_fb_return(fb);
            fb = nullptr;
            free(_jpg_buf);
            _jpg_buf = nullptr;

        } else if (_jpg_buf) {
            free(_jpg_buf);
            _jpg_buf = nullptr;
        }
    }

    uint8_t *getJpgBuf() { return this->_jpg_buf; }

    size_t getJpgBufLen() { return this->_jpg_buf_len; }

   private:
    bool vUseWithWebServer;
    bool vGenerateJpegCall;
    bool vAfterPushCall;
    bool vInitialized;

    static constexpr int HMIN = 90;
    static constexpr int HMAX = 128;
    static constexpr int SMIN = 50;
    static constexpr int SMAX = 255;
    static constexpr int VMIN = 70;
    static constexpr int VMAX = 255;

    static constexpr int THRESHOLD_RED_STRIPE = 300;

    // Energyleaf::V1::Window<int, bool> window;
    Energyleaf::V1::State<bool, bool, bool> vState;
    Energyleaf::V1::Calculator vCalculator;
    Energyleaf::V1::Sink::Sender vSender;
    Energyleaf::V1::LED::StatusLED vStatusLED;
    Energyleaf::V1::LED::CameraLED vCameraLED;
    Energyleaf::V1::Visual::Crop vCrop;
    Energyleaf::V1::Visual::RGBtoHSV vRGBtoHSV;
    Energyleaf::V1::Source::Camera vCamera;

    camera_fb_t *fb;
    size_t _jpg_buf_len;
    uint8_t *_jpg_buf;
    size_t out_len = 320 * 240 * 3;
    size_t out_width = 320;
    size_t out_height = 240;
    fb_data_t rfbcrop;
    uint8_t *out_buf;

    static bool stateEvaluateFunction(bool &state, const bool &input) {
        // no change = false; change = true;
        if (state != input) {
            state = input;
            return true;
        } else {
            return false;
        }
    }

   protected:
};
}  // namespace Energyleaf::V1

#endif
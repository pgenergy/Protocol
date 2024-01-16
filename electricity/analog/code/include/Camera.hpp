#ifndef ENERGYLEAF_V1_SOURCE_CAMERA
#define ENERGYLEAF_V1_SOURCE_CAMERA

#include <esp32-hal-psram.h>
#include <esp_camera.h>

#include <stdexcept>

namespace Energyleaf::V1::Source {
class Camera {
   public:
    Camera()
        : vInitialized(false),
          vPWDN_GPIO_NUM(32),
          vRESET_GPIO_NUM(-1),
          vXCLK_GPIO_NUM(0),
          vSIOD_GPIO_NUM(26),
          vSIOC_GPIO_NUM(27),
          vY9_GPIO_NUM(35),
          vY8_GPIO_NUM(34),
          vY7_GPIO_NUM(39),
          vY6_GPIO_NUM(36),
          vY5_GPIO_NUM(21),
          vY4_GPIO_NUM(19),
          vY3_GPIO_NUM(18),
          vY2_GPIO_NUM(5),
          vVSYNC_GPIO_NUM(25),
          vHREF_GPIO_NUM(23),
          vPCLK_GPIO_NUM(22),
          vXCLK_FREQ_HZ(10000000),
          vPIXEL_FORMAT(PIXFORMAT_JPEG),
          vGRAB_MODE(CAMERA_GRAB_LATEST),
          vFRAMESIZE_PS(FRAMESIZE_QVGA),
          vJPEG_QUALITY_PS(10),
          vFB_COUNT_PS(2),
          vFRAMESIZE_NPS(FRAMESIZE_QVGA),
          vJPEG_QUALITY_NPS(12),
          vFB_COUNT_NPS(1),
          vFB_LOCATION_NPS(CAMERA_FB_IN_DRAM),
          vAutoGain(1),
          vAutoExposure(1),
          vAutoAWB(1),
          vBrightness(0) {}

    virtual ~Camera() {
        deinitialize();
    };

    void deinitialize() {
        if(this->vInitialized) {
            if(vSensor != nullptr) {
                free(this->vSensor);
                this->vSensor = nullptr;
            }
        }
    }

    camera_config_t getConfig() { return this->vConfig; }

    void setPWDN_GPIO_NUM(int value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vPWDN_GPIO_NUM = value;
    }
    void setRESET_GPIO_NUM(int value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vRESET_GPIO_NUM = value;
    }
    void setXCLK_GPIO_NUM(int value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vXCLK_GPIO_NUM = value;
    }
    void setSIOD_GPIO_NUM(int value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vSIOD_GPIO_NUM = value;
    }
    void setSIOC_GPIO_NUM(int value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vSIOC_GPIO_NUM = value;
    }
    void setY9_GPIO_NUM(int value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vY9_GPIO_NUM = value;
    }
    void setY8_GPIO_NUM(int value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vY8_GPIO_NUM = value;
    }
    void setY7_GPIO_NUM(int value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vY7_GPIO_NUM = value;
    }
    void setY6_GPIO_NUM(int value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vY6_GPIO_NUM = value;
    }
    void setY5_GPIO_NUM(int value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vY5_GPIO_NUM = value;
    }
    void setY4_GPIO_NUM(int value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vY4_GPIO_NUM = value;
    }
    void setY3_GPIO_NUM(int value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vY3_GPIO_NUM = value;
    }
    void setY2_GPIO_NUM(int value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vY2_GPIO_NUM = value;
    }
    void setVSYNC_GPIO_NUM(int value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vVSYNC_GPIO_NUM = value;
    }
    void setHREF_GPIO_NUM(int value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vHREF_GPIO_NUM = value;
    }
    void setPCLK_GPIO_NUM(int value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vPCLK_GPIO_NUM = value;
    }
    void setXCLK_FREQ_HZ(int value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vXCLK_FREQ_HZ = value;
    }
    void setPIXEL_FORMAT(pixformat_t value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vPIXEL_FORMAT = value;
    }
    void setGRAB_MODE(camera_grab_mode_t value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vGRAB_MODE = value;
    }
    void setFRAMESIZE_PS(framesize_t value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vFRAMESIZE_PS = value;
    }
    void setJPEG_QUALITY_PS(int value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vJPEG_QUALITY_PS = value;
    }
    void setFB_COUNT_PS(size_t value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vFB_COUNT_PS = value;
    }
    void setFRAMESIZE_NPS(framesize_t value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vFRAMESIZE_NPS = value;
    }
    void setJPEG_QUALITY_NPS(int value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vJPEG_QUALITY_NPS = value;
    }
    void setFB_COUNT_NPS(size_t value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vFB_COUNT_NPS = value;
    }
    void setFB_LOCATION_NPS(camera_fb_location_t value) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vFB_LOCATION_NPS = value;
    }
    void setAutoGain(int value) { this->vAutoGain = value; }
    void setAutoExposure(int value) { this->vAutoExposure = value; }
    void setAutoAWB(int value) { this->vAutoAWB = value; }
    void setBrightness(int value) { this->vBrightness = value; }
    void setConfig(camera_config_t config) {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }
        this->vConfig = config;
    }

    camera_fb_t* getFramebuffer() {
        if (!this->vInitialized) {
            throw std::runtime_error("Camera is not initialized!");
        }
        return esp_camera_fb_get();
    }

    void returnFramebuffer(camera_fb_t* framebuffer) {
        if (framebuffer == nullptr) {
            throw std::runtime_error("Framebuffer is already empty");
        }
        esp_camera_fb_return(framebuffer);
    }

    sensor_t* getSensor() {
        if (!this->vInitialized) {
            throw std::runtime_error("Sensor is not initialized!");
        }
        return this->vSensor;
    }

    void initialize() {
        if (this->vInitialized) {
            throw std::runtime_error("Camera is already initialized!");
        }

        this->vConfig.ledc_channel = LEDC_CHANNEL_0;
        this->vConfig.ledc_timer = LEDC_TIMER_0;
        this->vConfig.pin_d0 = this->vY2_GPIO_NUM;
        this->vConfig.pin_d1 = this->vY3_GPIO_NUM;
        this->vConfig.pin_d2 = this->vY4_GPIO_NUM;
        this->vConfig.pin_d3 = this->vY5_GPIO_NUM;
        this->vConfig.pin_d4 = this->vY6_GPIO_NUM;
        this->vConfig.pin_d5 = this->vY7_GPIO_NUM;
        this->vConfig.pin_d6 = this->vY8_GPIO_NUM;
        this->vConfig.pin_d7 = this->vY9_GPIO_NUM;
        this->vConfig.pin_xclk = this->vXCLK_GPIO_NUM;
        this->vConfig.pin_pclk = this->vPCLK_GPIO_NUM;
        this->vConfig.pin_vsync = this->vVSYNC_GPIO_NUM;
        this->vConfig.pin_href = this->vHREF_GPIO_NUM;
        this->vConfig.pin_sccb_sda = this->vSIOD_GPIO_NUM;
        this->vConfig.pin_sccb_scl = this->vSIOC_GPIO_NUM;
        this->vConfig.pin_pwdn = this->vPWDN_GPIO_NUM;
        this->vConfig.pin_reset = this->vRESET_GPIO_NUM;
        this->vConfig.xclk_freq_hz = this->vXCLK_FREQ_HZ;
        this->vConfig.pixel_format = this->vPIXEL_FORMAT;
        this->vConfig.grab_mode = this->vGRAB_MODE;

        if (psramFound()) {
            this->vConfig.frame_size = this->vFRAMESIZE_PS;
            this->vConfig.jpeg_quality = this->vJPEG_QUALITY_PS;
            this->vConfig.fb_count = this->vFB_COUNT_PS;
            this->vConfig.fb_location = CAMERA_FB_IN_PSRAM;
        } else {
            this->vConfig.frame_size = this->vFRAMESIZE_NPS;
            this->vConfig.jpeg_quality = this->vJPEG_QUALITY_NPS;
            this->vConfig.fb_count = this->vFB_COUNT_NPS;
            this->vConfig.fb_location = this->vFB_LOCATION_NPS;
        }

        esp_err_t err = esp_camera_init(&this->vConfig);
        if (err != ESP_OK) {
            throw std::runtime_error("Could not initialize the Camera!");
        }

        this->vSensor = esp_camera_sensor_get();
        if (this->vSensor == nullptr) {
            throw std::runtime_error("Problem reading camera sensor settings!");
        }
        this->vSensor->set_framesize(this->vSensor, this->vConfig.frame_size);
        this->vSensor->set_gain_ctrl(this->vSensor,
                                     this->vAutoGain);  // auto gain on
        this->vSensor->set_exposure_ctrl(
            this->vSensor, this->vAutoExposure);  // auto exposure on
        this->vSensor->set_awb_gain(
            this->vSensor,
            this->vAutoAWB);  // Auto White Balance enable (0 or 1)
        this->vSensor->set_brightness(
            this->vSensor, this->vBrightness);  // (-2 to 2) - set brightness

        this->vInitialized = true;
    }

    bool isInitialized() {
        return this->vInitialized;
    }

   private:
    camera_config_t vConfig;
    sensor_t* vSensor;
    bool vInitialized;

    int vPWDN_GPIO_NUM;                     // 32
    int vRESET_GPIO_NUM;                    //-1
    int vXCLK_GPIO_NUM;                     // 0
    int vSIOD_GPIO_NUM;                     // 26
    int vSIOC_GPIO_NUM;                     // 27
    int vY9_GPIO_NUM;                       // 35
    int vY8_GPIO_NUM;                       // 34
    int vY7_GPIO_NUM;                       // 39
    int vY6_GPIO_NUM;                       // 36
    int vY5_GPIO_NUM;                       // 21
    int vY4_GPIO_NUM;                       // 19
    int vY3_GPIO_NUM;                       // 18
    int vY2_GPIO_NUM;                       // 5
    int vVSYNC_GPIO_NUM;                    // 25
    int vHREF_GPIO_NUM;                     // 23
    int vPCLK_GPIO_NUM;                     // 22
    int vXCLK_FREQ_HZ;                      // 10000000
    pixformat_t vPIXEL_FORMAT;              // PIXFORMAT_JPEG
    camera_grab_mode_t vGRAB_MODE;          // CAMERA_GRAB_LATEST
    framesize_t vFRAMESIZE_PS;              // FRAMESIZE_QVGA
    int vJPEG_QUALITY_PS;                   // 10
    size_t vFB_COUNT_PS;                    // 2
    framesize_t vFRAMESIZE_NPS;             // FRAMESIZE_QVGA
    int vJPEG_QUALITY_NPS;                  // 12
    size_t vFB_COUNT_NPS;                   // 1
    camera_fb_location_t vFB_LOCATION_NPS;  // CAMERA_FB_IN_DRAM

    int vAutoGain;      // 1
    int vAutoExposure;  // 1
    int vAutoAWB;       // 1
    int vBrightness;    // 0
   protected:
};
}  // namespace Energyleaf::V1::Input

#endif
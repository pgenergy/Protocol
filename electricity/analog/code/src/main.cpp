#include <Arduino.h>
#include <ArduinoOTA.h>
#include <FS.h>  // SD Card ESP32
#include <SPIFFS.h>
#include <WiFi.h>
#include <fb_gfx.h>

#include <cstring>
#include <deque>

#include "Calculator.hpp"
#include "Detector.hpp"
#include "State.hpp"
#include "Window.hpp"
#include "esp_camera.h"
#include "esp_http_server.h"
#include "esp_log.h"
#include "img_converters.h"
#include "soc/rtc_cntl_reg.h"  //disable brownout problems
#include "soc/soc.h"           //disable brownout problems
#include "time.h"

SET_LOOP_TASK_STACK_SIZE(16 * 1024);  // 16KB

constexpr bool USE_WEBSERVER = false;

const char *ssid = "SSID";
const char *password = "PASS";
const char *otaPassword = "energyleaf";  // For Testing only actual

static const uint32_t UPDATE_INTERVAL = 50;

const char *ntpServer = "pool.ntp.org";  // Recode to use TZ
const long gmtOffset_sec = 3600;
const int daylightOffset_sec = 0;

Energyleaf::V1::Detector detector;

#define PART_BOUNDARY "123456789000000000000987654321"
static const char *_STREAM_CONTENT_TYPE =
    "multipart/x-mixed-replace;boundary=" PART_BOUNDARY;
static const char *_STREAM_BOUNDARY = "\r\n--" PART_BOUNDARY "\r\n";
static const char *_STREAM_PART =
    "Content-Type: image/jpeg\r\nContent-Length: %u\r\n\r\n";

httpd_handle_t stream_httpd = NULL;

static esp_err_t stream_handler(httpd_req_t *req) {
    char *part_buf[64];
    esp_err_t res = ESP_OK;
    detector.initialize();

    Serial.println("Stream requested");
    res = httpd_resp_set_type(req, _STREAM_CONTENT_TYPE);
    if (res != ESP_OK) {
        Serial.println("STREAM: failed to set HTTP response type");
        return res;
    }
    httpd_resp_set_hdr(req, "Access-Control-Allow-Origin", "*");

    if (res == ESP_OK) {
        res = httpd_resp_send_chunk(req, _STREAM_BOUNDARY,
                                    strlen(_STREAM_BOUNDARY));
    }

    while (true) {
        try {
            detector.push();
        } catch (std::runtime_error &err) {
            Serial.println(err.what());
            return ESP_FAIL;
        }

        if (res == ESP_OK) {
            size_t hlen = snprintf((char *)part_buf, 64, _STREAM_PART,
                                   detector.getJpgBufLen());
            res = httpd_resp_send_chunk(req, (const char *)part_buf, hlen);
        }
        if (res == ESP_OK) {
            res = httpd_resp_send_chunk(req, (const char *)detector.getJpgBuf(),
                                        detector.getJpgBufLen());
        }
        if (res == ESP_OK) {
            res = httpd_resp_send_chunk(req, _STREAM_BOUNDARY,
                                        strlen(_STREAM_BOUNDARY));
        }
        detector.afterPush();

        if (res != ESP_OK) {
            break;
        }
        vTaskDelay(UPDATE_INTERVAL / portTICK_PERIOD_MS);
    }

    detector.deinialize();

    return res;
}

void startCameraServer() {
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    config.server_port = 80;

    httpd_uri_t index_uri = {.uri = "/",
                             .method = HTTP_GET,
                             .handler = stream_handler,
                             .user_ctx = NULL};

    if (httpd_start(&stream_httpd, &config) == ESP_OK) {
        httpd_register_uri_handler(stream_httpd, &index_uri);
    }
}

void setup() {
    WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);  // disable brownout detector

    Serial.begin(115200);
    Serial.setDebugOutput(true);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.println("Connection Failed! Rebooting...");
        delay(5000);
        ESP.restart();
    }
    Serial.println("Connected to WiFi!");

    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

    ArduinoOTA
        .onStart([]() {
            String type;
            if (ArduinoOTA.getCommand() == U_FLASH)
                type = "sketch";
            else  // U_SPIFFS
                type = "filesystem";

            // NOTE: if updating SPIFFS this would be the place to unmount
            Serial.println("Start updating " + type);
            SPIFFS.end();
            esp_camera_deinit();
        })
        .onEnd([]() { Serial.println("\nEnd"); })
        .onProgress([](unsigned int progress, unsigned int total) {
            Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
        })
        .onError([](ota_error_t error) {
            Serial.printf("Error[%u]: ", error);
            if (error == OTA_AUTH_ERROR)
                Serial.println("Auth Failed");
            else if (error == OTA_BEGIN_ERROR)
                Serial.println("Begin Failed");
            else if (error == OTA_CONNECT_ERROR)
                Serial.println("Connect Failed");
            else if (error == OTA_RECEIVE_ERROR)
                Serial.println("Receive Failed");
            else if (error == OTA_END_ERROR)
                Serial.println("End Failed");
        });

    ArduinoOTA.setPassword(otaPassword);
    ArduinoOTA.begin();

    Serial.println("Ready");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    if (USE_WEBSERVER) {
        detector.setUseWithWebServer(true);
        startCameraServer();
        detector.setGenerateJpegCall(true);
    } else {
        detector.initialize();
        detector.setAfterPushCall(true);
    }
}

void loop() {
    ArduinoOTA.handle();

    if (!USE_WEBSERVER) {
        try {
            detector.push();
        } catch (std::runtime_error &err) {
            log_d("Error: %s", err.what());
        }
    }
}

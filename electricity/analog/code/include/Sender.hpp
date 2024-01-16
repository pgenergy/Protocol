#ifndef ENERGYLEAF_V1_SINK_SENDER
#define ENERGYLEAF_V1_SINK_SENDER

#include <WString.h>
#include <WiFiClientSecure.h>

#include <algorithm>
#include <cstring>
#include <string>

#include "ELData.pb.h"
#include "pb_encode.h"

extern const uint8_t rootca_crt_bundle_start[] asm("_binary_data_cert_x509_crt_bundle_bin_start");

namespace Energyleaf::V1::Sink {
class Sender {
   public:
    explicit Sender() : client(), portSet(false) {
        client.setCACertBundle(rootca_crt_bundle_start);
    }

    explicit Sender(char sensorId[128], std::string host, int port,
                    std::string endpoint)
        : client(), host(host), port(port), endpoint(endpoint), portSet(true) {
        std::copy(sensorId, sensorId + std::strlen(sensorId), this->sensorId);
        client.setCACertBundle(rootca_crt_bundle_start);
    }

    virtual ~Sender() = default;

    void setSensorId(char sensorId[128]) {
        std::copy(sensorId, sensorId + std::strlen(sensorId), this->sensorId);
    }

    void setSensorId(std::string sensorId) {
        if (sensorId.length() > 120) {
            throw std::runtime_error("SensorId to big to store!");
        }
        strcpy(this->sensorId, sensorId.c_str());
    }

    void setHost(std::string host) { this->host = host; }

    void setPort(int port) {
        this->port = port;
        this->portSet = true;
    }

    void setEndpoint(std::string endpoint) { this->endpoint = endpoint; }

    void push(float sensorValue) {
        if (!this->sensorId && this->host.empty() && this->endpoint.empty() &&
            !this->portSet) {
            throw new std::runtime_error("Endpointdata not set!");
        }
        ELData message = ELData_init_default;
        std::copy(std::begin(this->sensorId), std::end(this->sensorId), message.sensorId);
        message.sensorValue = sensorValue;

        pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));
        if (!pb_encode(&stream, ELData_fields, &message)) {
            Serial.println("Encoding failed!");
            return;
        }

        log_d("Connecting to %s:%d",host.c_str(),port);
        client.connect(host.c_str(), port);
        if (client.connected()) {
            log_d("Connected and data is now transmitting");
            client.print("POST ");
            client.print(this->endpoint.c_str());
            client.println(" HTTP/1.1");
            client.print("Host: ");
            client.println(host.c_str());
            client.println("Content-Type: application/x-protobuf");
            client.println("Content-Length: " + String(stream.bytes_written));
            client.println();

            client.write(buffer, stream.bytes_written);

            client.stop();
        } else {
            throw std::runtime_error("Connection failed");
        }
    }

   private:
    uint8_t buffer[ELData_size];
    char sensorId[128];
    std::string host;
    std::string endpoint;
    int port;
    bool portSet;
    WiFiClientSecure client;


   protected:
};
}  // namespace Energyleaf::V1::Sink

#endif
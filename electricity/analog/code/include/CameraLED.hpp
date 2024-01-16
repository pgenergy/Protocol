#ifndef ENERGYLEAF_V1_LED_CAMERALED
#define ENERGYLEAF_V1_LED_CAMERALED

#include <esp32-hal-gpio.h>
#include "LED.hpp"

namespace Energyleaf::V1::LED {
class CameraLED : public LED {
   public:
    CameraLED(uint8_t pin, uint8_t channel, uint32_t duty)
        : LED(pin), vChannel(channel), vDuty(duty) {
        ledcSetup(this->vChannel, 5000, 8);
        ledcAttachPin(this->vPin, this->vChannel);
    }

    virtual ~CameraLED() = default;

   private:
    const uint8_t vChannel;
    const uint32_t vDuty;
    static constexpr int CONFIG_LED_MAX_INTENSITY = 255;

   protected:
    void update() {
        int duty = this->vEnable ? this->vDuty : 0;
        if (this->vEnable && (this->vDuty > CONFIG_LED_MAX_INTENSITY)) {
            duty = CONFIG_LED_MAX_INTENSITY;
        }
        ledcWrite(this->vChannel, duty);
    }
};
}  // namespace Energyleaf::V1::LED

#endif
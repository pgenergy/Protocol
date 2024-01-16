#ifndef ENERGYLEAF_V1_LED_STATUSLED
#define ENERGYLEAF_V1_LED_STATUSLED

#include <esp32-hal-gpio.h>

#include "LED.hpp"

namespace Energyleaf::V1::LED {
class StatusLED : public LED {
   public:
    StatusLED(int pin) : LED(pin) { pinMode(this->vPin, OUTPUT); }

    virtual ~StatusLED() = default;

   private:
   protected:
    void update() { digitalWrite(this->vPin, this->vEnable ? LOW : HIGH); }
};
}  // namespace Energyleaf::V1::LED

#endif
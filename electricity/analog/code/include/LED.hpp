#ifndef ENERGYLEAF_V1_LED_LED
#define ENERGYLEAF_V1_LED_LED

namespace Energyleaf::V1::LED {
class LED {
   public:
    LED(uint8_t vPin) : vPin(vPin), vEnable(false) {
    }

    virtual ~LED() { this->disable(); }

    void enable() { 
        this->vEnable = true;
        this->update();
    }

    void disable() { 
        this->vEnable = false;
        this->update();
    }

    bool isEnabled() { return this->vEnable; }

   private:
   protected:
    const uint8_t vPin;
    bool vEnable;

    virtual void update() = 0;
};
}  // namespace Energyleaf::V1::LED

#endif
#ifndef ENERGYLEAF_V1_CALCULATOR
#define ENERGYLEAF_V1_CALCULATOR

#include <ctime>
#include <functional>
#include <stdexcept>
#include "time.h"
#include <Arduino.h>

namespace Energyleaf::V1 {
    class Calculator {
        public:
            explicit Calculator()
                : rotationPerkWh(0), last(0), processed(false), wattPerMilliseconds(true) {
            }

            explicit Calculator(int rotationPerkWh)
                : rotationPerkWh(rotationPerkWh), last(0), processed(false), wattPerMilliseconds(true) {
            }

            virtual ~Calculator() = default;

            void setRotationPerkWh(int rotationPerkWh) {
                this->rotationPerkWh = rotationPerkWh;
            }

            void setWattPerMilliseconds(bool wattPerMilliseconds) {
                this->wattPerMilliseconds = wattPerMilliseconds;
            }

            void push() {
                if (this->processed) this->processed = !this->processed;
                if(rotationPerkWh == 0) {
                    throw std::runtime_error("Rotation per kWh is not set!");
                }
                if(last > 0) {
                    //Normal process, min. 1 red mark was detected before this event.
                    unsigned long current = getCurrentTime();
                    unsigned long rotationTime = current - this->last;
                    if(rotationTime > 30) {
                        this->power = ((this->wattPerMilliseconds ? this->wpms : this->wps)/ rotationTime / this->rotationPerkWh) * 1000.0f;
                        this->processed = true;
                        this->last = current;
                    } else {
                        //Error, could not calculate the power
                        this->power = 0.0f;
                    }
                } else {
                    //initial process, no red mark was detected before this event.
                    last = getCurrentTime();
                }
            }

            bool isProcessed() {
                return this->processed;
            }

            float getPower(bool resetProcessed = false) {
                if(resetProcessed) this->processed = false;
                return this->power;
            }

        private:
            int rotationPerkWh;
            unsigned long last;
            float power;
            bool processed;
            unsigned long getCurrentTime() {
                return millis();
            }

            bool wattPerMilliseconds;

            const float wpms = 3600000.0f;
            const float wps = 3600.0f;

        protected:
    };
}

#endif
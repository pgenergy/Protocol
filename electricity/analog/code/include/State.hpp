#ifndef ENERGYLEAF_V1_STATE
#define ENERGYLEAF_V1_STATE

#include <functional>
#include <stdexcept>

namespace Energyleaf::V1 {
    template <typename T0, typename T1, typename T2>
    class State {
        public:
            explicit State() : ready(false) {
            }

            explicit State(std::function<T0(T1&, const T2&)> function) 
                : ready(false), function(function) {
            }

            virtual ~State() = default;

            void setFunction(std::function<T0(T1&, const T2&)> function) {
                this->function = function;
            }  

            void setState(T1 state) {
                if(!this->ready) {
                    this->state = state;
                    this->ready = true;
                }
            }

            void push(T2 value) {
                if (!this->function) {
                    throw std::runtime_error(
                    "Could not call function to evaluate window!");
                }
                if (!this->ready) {
                    throw std::runtime_error(
                    "Operator is not ready!");
                }
                this->output = function(this->state,value);
            }

            T1 getState() { return this->state; }

            T0 getOutput() { return this->output; }

            T0 pushAndGet(T2 value) {
                this->push(value);
                return this->getState;
            }

            bool isReady() {
                return this->ready;
            }
        private:
            T0 output;
            T1 state;
            std::function<T1(T1&, const T2&)> function;
            bool ready;
        protected:
    };
}

#endif
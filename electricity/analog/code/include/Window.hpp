#ifndef ENERGYLEAF_V1_WINDOW
#define ENERGYLEAF_V1_WINDOW

/**
 * Example usage:
 *
 * bool windowEvaluateFunction(const std::vector<int> &window, const bool
 *&state) { int windowSize = window.size(); int requiredChanges = (windowSize +
 *1) / 2; int changesCount = 0; bool last = window[0] > THRESHOLD_RED_STRIPE;
 *    // true = red; false = not red;
 *    for (int i = 1; i < windowSize; ++i) {
 *        bool current = window[i] > THRESHOLD_RED_STRIPE;
 *
 *        if (last == current && current != state) {
 *            ++changesCount;
 *            if (changesCount == requiredChanges) {
 *                return !state;
 *            }
 *        } else {
 *            changesCount = 0;
 *        }
 *
 *        last = current;
 *    }
 *
 *    return state;
 *}
 * and use it with
 *window.setSize(2);
 *window.setFunction(windowEvaluateFunction);
 */

#include <functional>
#include <stdexcept>
#include <vector>

namespace Energyleaf::V1 {
template <typename T1, typename T2>
class Window {
   public:
    explicit Window(int size = 3) : size(size), processed(false) {}
    explicit Window(
        std::function<T2(const std::vector<T1>&, const T2&)> function,
        int size = 3)
        : size(size), processed(false), function(function) {}

    virtual ~Window() = default;

    void setFunction(
        std::function<T2(const std::vector<T1>&, const T2&)> function) {
        this->function = function;
    }

    void setSize(int size) { this->size = size; }

    void push(T1 i) {
        if (this->processed) this->processed = !this->processed;
        this->elements.push_back(i);
        if (this->elements.size() == this->size) {
            if (!this->function) {
                this->processed = false;
                throw std::runtime_error(
                    "Could not call function to evaluate window!");
            }
            this->state = function(this->elements, this->state);
            this->processed = true;
            this->elements.erase(this->elements.begin());
        }
    }

    bool isProcessed() { return this->processed; }

    T2 getState() { return this->state; }

   private:
    T2 state;
    std::vector<T1> elements;
    int size;
    std::function<T2(const std::vector<T1>&, const T2&)> function;
    bool processed;

   protected:
};
}  // namespace Energyleaf::V1

#endif
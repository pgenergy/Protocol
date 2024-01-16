#ifndef ENERGYLEAF_V1_VISUAL_RGBTOHSV
#define ENERGYLEAF_V1_VISUAL_RGBTOHSV

#include <algorithm>

namespace Energyleaf::V1::Visual {
struct RGBPixel {
    int r;
    int g;
    int b;
};
struct HSVPixel{
    float h;
    float s;
    float v;
};
class RGBtoHSV {
   public:
    RGBtoHSV() {}

    virtual ~RGBtoHSV() = default;

    void convert(RGBPixel rgb, HSVPixel& hsv) {
        float maxColor = std::max(std::max(rgb.r, rgb.g), rgb.b);
        float minColor = std::min(std::min(rgb.r, rgb.g), rgb.b);
        float delta = maxColor - minColor;

        hsv.v = maxColor;

        if (maxColor != 0) {
            hsv.s = delta / maxColor;
        } else {
            hsv.s = 0;
        }

        if (hsv.s == 0) {
            hsv.h = 0;
        } else {
            if (rgb.r == maxColor) {
                hsv.h = (rgb.g - rgb.b) / delta + (rgb.g < rgb.b ? 6 : 0);
            } else if (rgb.g == maxColor) {
                hsv.h = (rgb.b - rgb.r) / delta + 2;
            } else if (rgb.b == maxColor) {
                hsv.h = (rgb.r - rgb.g) / delta + 4;
            }
            hsv.h /= 6;
            hsv.h *= 179.0;
        }
        hsv.s *= 255;
    }

   private:
   protected:
};
};  // namespace Energyleaf::V1::Visual

#endif
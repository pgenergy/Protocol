#ifndef ENERGYLEAF_V1_VISUAL_CROP
#define ENERGYLEAF_V1_VISUAL_CROP

#include <fb_gfx.h>
#include "Arduino.h"

namespace Energyleaf::V1::Visual {
class Crop {
   public:
    Crop(int x, int y, int width, int height)
        : vX(x), vY(y), vWidth(width), vHeight(height) {}

    virtual ~Crop() = default;

    void crop(const fb_data_t &in, fb_data_t &out) {
        if (this->vX < 0 || this->vWidth <= 0 || this->vX + this->vWidth > in.width) {
            return;
        }

        out.width = this->vWidth;
        out.height = in.height;
        out.bytes_per_pixel = in.bytes_per_pixel;
        out.format = in.format;
        out.data = new uint8_t[this->vWidth * in.height * out.bytes_per_pixel];

        int startIdx = this->vX * in.bytes_per_pixel;

        int bytesPerRow = this->vWidth * out.bytes_per_pixel;

        for (int y = 0; y < in.height; ++y) {
            int inIdx = startIdx + y * in.width * in.bytes_per_pixel;
            int outIdx = y * bytesPerRow;

            memcpy(out.data + outIdx, in.data + inIdx, bytesPerRow);
        }
    }

   private:
    const int vX;
    const int vWidth;
    const int vY;
    const int vHeight;

   protected:
};
}  // namespace Energyleaf::V1::Visual

#endif
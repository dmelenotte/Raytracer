#ifndef __PIXEL_BUFFER__
    #define __PIXEL_BUFFER__

#include "../elementary_data/Color.hpp"

#include <vector>

class PixelBuffer {
    public:
        PixelBuffer();
        PixelBuffer(int width, int height);
        ~PixelBuffer() = default;
        void fillBuffer(int width, int height);
        int getBufferWidth() const;
        int getBufferHeight() const;
        const std::vector<Color> &getBuffer() const;
        bool empty() const;
        Color &at(std::size_t x, std::size_t y);
        const Color &at(std::size_t x, std::size_t y) const;
        void setat(Color newcolor, std::size_t x, std::size_t y);
    private:
        int _width;
        int _height;
        std::vector<Color> _buffer;
};

#endif

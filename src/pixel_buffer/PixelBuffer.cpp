#include "PixelBuffer.hpp"

PixelBuffer::PixelBuffer() : _width(0), _height(0) {}

PixelBuffer::PixelBuffer(int width, int height) : _width(width), _height(height)
{
    std::size_t bufferSize = _width * _height;
    _buffer.resize(bufferSize);
}

void PixelBuffer::fillBuffer(int width, int height)
{
    _width = width;
    _height = height;
    std::size_t bufferSize = _width * _height;
    _buffer.resize(bufferSize);
}

int PixelBuffer::getBufferWidth() const
{
    return _width;
}

int PixelBuffer::getBufferHeight() const
{
    return _height;
}

const std::vector<Color> &PixelBuffer::getBuffer() const
{
    return _buffer;
}

bool PixelBuffer::empty() const
{
    return _buffer.empty();
}

Color &PixelBuffer::at(std::size_t x, std::size_t y)
{
    if (_buffer.size() <= ((_width * y) + x)) {
        return _buffer.at(_buffer.size() - 1);
    }
    return _buffer.at((_width * y) + x);
}

const Color &PixelBuffer::at(std::size_t x, std::size_t y) const
{
    if (_buffer.size() >= ((_width * y) + x)) {
        return _buffer.at(_buffer.size() - 1);
    }
    return _buffer.at((_width * y) + x);
}

void PixelBuffer::setat(Color newcolor, std::size_t x, std::size_t y)
{
    this->at(x, y) = newcolor;
}
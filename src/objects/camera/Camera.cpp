#include "Camera.hpp"

Camera::Camera(int width, int height, const Position &position, const Rotation &rotation, float fov, int depth) :
    _width(width), _height(height), _position(position), _rotation(rotation), _fov(fov), _depth(depth),
    _buffer(_width, _height) {}

IObject::ObjectType Camera::getObjectType() const
{
    return IObject::ObjectType::CAMERA;
}

int Camera::getWidth() const
{
    return _width;
}

int Camera::getHeight() const
{
    return _height;
}

float Camera::getFov() const
{
    return _fov;
}

int Camera::getDepth() const
{
    return _depth;
}

PixelBuffer &Camera::getBuffer()
{
    return _buffer;
}

const PixelBuffer &Camera::getBuffer() const
{
    return _buffer;
}

Ray Camera::ray(double x, double y)
{
    Vector dir = Vector{x, y, 1.0}.normalized();
    Matrix rX = Matrix::rotationX(_rotation.getX());
    Matrix rY = Matrix::rotationY(_rotation.getY());
    Matrix rZ = Matrix::rotationZ(_rotation.getZ());
    Matrix t = Matrix::translation((Vector)_position);
    Matrix totalMatrix = rX * rY * rZ * t;
    Matrix::Vec4D total = totalMatrix * Matrix::Vec4D(dir.getX(), dir.getY(), dir.getZ(), 0);

    return Ray(_position, Vector(total.x, total.y, total.z));
}

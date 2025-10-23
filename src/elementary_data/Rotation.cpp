#include "Rotation.hpp"

Rotation::Rotation() : _x(0), _y(0), _z(0) {}

Rotation::Rotation(double x, double y, double z) : _x(x), _y(y), _z(z) {}

Rotation::Rotation(const Rotation &otherRotation)
{
    _x = otherRotation._x;
    _y = otherRotation._y;
    _z = otherRotation._z;
}

void Rotation::setX(double x)
{
    _x = x;
}

void Rotation::setY(double y)
{
    _y = y;
}

void Rotation::setZ(double z)
{
    _z = z;
}

void Rotation::setX_Y_Z(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}

double Rotation::getX() const
{
    return _x;
}

double Rotation::getY() const
{
    return _y;
}

double Rotation::getZ() const
{
    return _z;
}

void Rotation::operator=(const Rotation &otherRotation)
{
    _x = otherRotation._x;
    _y = otherRotation._y;
    _z = otherRotation._z;
}

bool Rotation::operator==(const Rotation &otherRotation) const
{
    if (_x == otherRotation._x && _y == otherRotation._y && _z == otherRotation._z) {
        return true;
    }
    return false;
}

bool Rotation::operator!=(const Rotation &otherRotation) const
{
    if (_x == otherRotation._x && _y == otherRotation._y && _z == otherRotation._z) {
        return false;
    }
    return true;
}

Rotation::operator Vector() const
{
    return Vector(_x, _y, _z);
}

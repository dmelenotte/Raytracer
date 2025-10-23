#include "Vector.hpp"

#include <cmath>

Vector::Vector() : _x(0), _y(0), _z(0) {}

Vector::Vector(double x, double y, double z) : _x(x), _y(y), _z(z) {}

Vector::Vector(const Vector &otherVector)
{
    _x = otherVector._x;
    _y = otherVector._y;
    _z = otherVector._z;
}

void Vector::setX(double x)
{
    _x = x;
}

void Vector::setY(double y)
{
    _y = y;
}

void Vector::setZ(double z)
{
    _z = z;
}

void Vector::setX_Y_Z(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}

double Vector::getX() const
{
    return _x;
}

double Vector::getY() const
{
    return _y;
}

double Vector::getZ() const
{
    return _z;
}

double Vector::length() const
{
    double xSquare = _x * _x;
    double ySquare = _y * _y;
    double zSquare = _z * _z;
    double vectorLength = std::sqrt((xSquare + ySquare + zSquare));
    return vectorLength;
}

double Vector::dot(const Vector &otherVector) const
{
    double xDotPart = _x * otherVector._x;
    double yDotPart = _y * otherVector._y;
    double zDotPart = _z * otherVector._z;
    return (xDotPart + yDotPart + zDotPart);
}

Vector Vector::normalized() const
{
    double len = this->length();
    if (len == 0.0f) {
        return Vector(_x, _y, _z);
    }
    return Vector(_x / len, _y / len, _z / len);
}

Vector Vector::cross(const Vector &otherVector) const
{
    return Vector(
        _y * otherVector._z - _z * otherVector._y,
        _z * otherVector._x - _x * otherVector._z,
        _x * otherVector._y - _y * otherVector._x);
}

void Vector::operator=(const Vector &otherVector)
{
    _x = otherVector._x;
    _y = otherVector._y;
    _z = otherVector._z;
}

Vector Vector::operator+(const Vector &otherVector) const
{
    return Vector(_x + otherVector._x, _y + otherVector._y, _z + otherVector._z);
}

void Vector::operator+=(const Vector &otherVector)
{
    _x += otherVector._x;
    _y += otherVector._y;
    _z += otherVector._z;
}

Vector Vector::operator-(const Vector &otherVector) const
{
    return Vector(_x - otherVector._x, _y - otherVector._y, _z - otherVector._z);
}

Vector Vector::operator-() const
{
    return Vector(-_x, -_y, -_z);
}

void Vector::operator-=(const Vector &otherVector)
{
    _x -= otherVector._x;
    _y -= otherVector._y;
    _z -= otherVector._z;
}

Vector Vector::operator*(const Vector &otherVector) const
{
    return Vector(_x * otherVector._x, _y * otherVector._y, _z * otherVector._z);
}

Vector Vector::operator*(double value) const
{
    return Vector(_x * value, _y * value, _z * value);
}

void Vector::operator*=(const Vector &otherVector)
{
    _x *= otherVector._x;
    _y *= otherVector._y;
    _z *= otherVector._z;
}

void Vector::operator*=(double value)
{
    _x *= value;
    _y *= value;
    _z *= value;
}

Vector Vector::operator/(const Vector &otherVector) const
{
    return Vector((otherVector._x != 0.0f) ? (_x / otherVector._x) : _x,
      (otherVector._y != 0.0f) ? (_y / otherVector._y) : _y,
      (otherVector._z != 0.0f) ? (_z / otherVector._z) : _z);
}

Vector Vector::operator/(double value) const
{
    if (value == 0.0f)
    {
        return *this;
    }
    return Vector(_x / value, _y / value, _z / value);
}

void Vector::operator/=(const Vector &otherVector)
{
    if (otherVector._x != 0.0f)
    {
        _x /= otherVector._x;
    }
    if (otherVector._z != 0.0f)
    {
        _y /= otherVector._y;
    }
    if (otherVector._y != 0.0f)
    {
        _z /= otherVector._z;
    }
}

void Vector::operator/=(double value)
{
    if (value == 0.0f)
    {
        return;
    }
    _x /= value;
    _y /= value;
    _z /= value;
}
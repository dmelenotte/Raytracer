#include "Position.hpp"

Position::Position() : _x(0), _y(0), _z(0) {}

Position::Position(double x, double y, double z) : _x(x), _y(y), _z(z) {}

Position::Position(const Position &otherPosition)
{
    _x = otherPosition._x;
    _y = otherPosition._y;
    _z = otherPosition._z;
}

void Position::setX(double x)
{
    _x = x;
}

void Position::setY(double y)
{
    _y = y;
}

void Position::setZ(double z)
{
    _z = z;
}

void Position::setX_Y_Z(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}

double Position::getX() const
{
    return _x;
}

double Position::getY() const
{
    return _y;
}

double Position::getZ() const
{
    return _z;
}

void Position::operator=(const Position &otherPosition)
{
    _x = otherPosition._x;
    _y = otherPosition._y;
    _z = otherPosition._z;
}

bool Position::operator==(const Position &otherPosition) const
{
    if (_x == otherPosition._x && _y == otherPosition._y && _z == otherPosition._z) {
        return true;
    }
    return false;
}

bool Position::operator!=(const Position &otherPosition) const
{
    if (_x == otherPosition._x && _y == otherPosition._y && _z == otherPosition._z) {
        return false;
    }
    return true;
}

Position Position::operator+(const Position &p) const
{
    return (Position(
    _x + p._x,
    _y + p._y,
    _z + p._z));
}

Position Position::operator+(const Vector &vector) const
{
    return (Position(
        _x + vector.getX(),
        _y + vector.getY(),
        _z + vector.getZ()));
}

Position Position::operator-(const Position &p) const
{
    return (Position(
        _x - p._x,
        _y - p._y,
        _z - p._z));
}

Position Position::operator-(const Vector &vector) const
{
    return (Position(
        _x - vector.getX(),
        _y - vector.getY(),
        _z - vector.getZ()));
}

Position::operator Vector() const
{
    return Vector(_x, _y, _z);
}
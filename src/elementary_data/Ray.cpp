#include "Ray.hpp"

Ray::Ray(const Position &point, const Vector &vector) : _point(point), _vector(vector) {}

Ray::Ray(const Ray &other)
{
    _point = other._point;
    _vector = other._vector;
}

Position &Ray::getPoint()
{
    return _point;
}

const Position &Ray::getPoint() const
{
    return _point;
}

Vector &Ray::getVector()
{
    return _vector;
}

const Vector &Ray::getVector() const
{
    return _vector;
}

void Ray::operator=(const Ray &other)
{
    _point = other._point;
    _vector = other._vector;
}

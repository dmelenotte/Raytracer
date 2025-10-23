#include "Cylinder.hpp"

#include <cmath>

Cylinder::Cylinder(const Position &position, float radius, const Vector &directional,
    const Color &color, const Color &albedo, const Color &reflection) :
    APrimitive(color, albedo, reflection), _position(position), _radius(radius), _directional(directional) {}

IObject::ObjectType Cylinder::getObjectType() const
{
    return IObject::ObjectType::PRIMITIVE;
}

bool Cylinder::hit(const Ray &ray, double &t, Vector &normal)
{
    Vector oc = ray.getPoint() - _position;
    Vector ca = _directional.normalized();
    Vector dProj = ray.getVector() - ca * ray.getVector().dot(ca);
    Vector ocProj = oc - ca * oc.dot(ca);

    double a = dProj.dot(dProj);
    double b = 2.0 * dProj.dot(ocProj);
    double c = ocProj.dot(ocProj) - _radius * _radius;

    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) return false;

    double sqrtDisc = std::sqrt(discriminant);
    double t1 = (-b - sqrtDisc) / (2.0 * a);
    double t2 = (-b + sqrtDisc) / (2.0 * a);

    if (t1 > 1e-4) {
        t = t1;
    } else if (t2 > 1e-4) {
        t = t2;
    }
    else {
        return false;
    }

    Vector hitPoint = ray.getPoint() + ray.getVector() * t;
    Vector cp = hitPoint - _position;
    double projLen = cp.dot(ca);
    Vector proj = ca * projLen;
    normal = (cp - proj).normalized();
    return true;
}

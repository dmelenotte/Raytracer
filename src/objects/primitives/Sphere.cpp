#include "Sphere.hpp"

#include <cmath>

Sphere::Sphere(const Position &position, float radius, const Color &color,
    const Color &albedo, const Color &reflection) :
    APrimitive(color, albedo, reflection), _position(position), _radius(radius) {}

IObject::ObjectType Sphere::getObjectType() const
{
    return IObject::ObjectType::PRIMITIVE;
}

bool Sphere::hit(const Ray &ray, double &t, Vector &normal)
{
    Position point(ray.getPoint() - _position);
    Vector oc(point.getX(), point.getY(), point.getZ());
    double a = ray.getVector().dot(ray.getVector());
    double b = 2.0f * oc.dot(ray.getVector());
    double c = oc.dot(oc) - _radius * _radius;

    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return false;
    }
    double sqrtDisc = std::sqrt(discriminant);
    double t1 = (-b - sqrtDisc) / (2.0f * a);
    double t2 = (-b + sqrtDisc) / (2.0f * a);
    if (t1 > 0.001f) {
        t = t1;
    } else if (t2 > 0.001f) {
        t = t2;
    } else {
        return false;
    }
    Vector hitPoint = ray.getPoint() + ray.getVector() * t;
    normal = (hitPoint - _position).normalized();
    return true;
}

#ifndef __MOBIUS__
#define __MOBIUS__

#include "IPrimitive.hpp"

#include "../../elementary_data/Position.hpp"
#include "../../elementary_data/Color.hpp"
#include "../../elementary_data/Matrix.hpp"

class Mobius : public IPrimitive
{
public:
    typedef struct data_s
    {
        Position _position;
        double _angle;
        Vector _direction;
        Color _color;
    } data_t;

    Mobius(const Position &position, double angle, Vector direction, const Color &color);
    ~Mobius() = default;
    void applyTransform();
    IObject::ObjectType getObjectType() const;
    const Color &getColor() const;
    bool hit(const Ray &ray, double &t, Vector &normal);
    Vector normalAt(const Position &point) const;
    Position intersectionPoint(const Ray &ray, double t) const;
    const Vector &getNormal() const;

private:
    data_t _data;
    Vector _normal;
};

#endif

/* oh oui strip moi le mobius*/
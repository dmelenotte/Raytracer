#ifndef __CONE__
    #define __CONE__

#include "APrimivite.hpp"

#include "../../elementary_data/Position.hpp"
#include "../../elementary_data/Color.hpp"

class Cone : public APrimitive {
    public:
        Cone(const Position &position, float angle, const Vector &direction,
            const Color &color, const Color &albedo, const Color &reflection);
        ~Cone() = default;
        IObject::ObjectType getObjectType() const;
        bool hit(const Ray &ray, double &t, Vector &normal);
    private:
        Position _position;
        float _angle;
        Vector _direction;
};

#endif

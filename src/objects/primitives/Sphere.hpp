#ifndef __SPHERE__
    #define __SPHERE__

#include "APrimivite.hpp"

#include "../../elementary_data/Position.hpp"
#include "../../elementary_data/Color.hpp"

class Sphere : public APrimitive {
    public:
        Sphere(const Position &position, float radius, const Color &color, const Color &albedo, const Color &reflection);
        ~Sphere() = default;
        IObject::ObjectType getObjectType() const;
        bool hit(const Ray &ray, double &t, Vector &normal);
    private:
        Position _position;
        float _radius;
};

#endif

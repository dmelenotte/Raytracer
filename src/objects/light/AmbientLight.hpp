#ifndef __AMBIENT_LIGHT__
    #define __AMBIENT_LIGHT__

#include "ALight.hpp"

#include "../../elementary_data/Position.hpp"

class AmbientLight : public ALight {
    public:
        AmbientLight(float intensity);
        ~AmbientLight() = default;
        IObject::ObjectType getObjectType() const;
        ILight::LightType getLightType() const;
    private:
};

#endif

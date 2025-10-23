#ifndef __DIRECTIONAL_LIGHT__
    #define __DIRECTIONAL_LIGHT__

#include "ALight.hpp"

#include "../../elementary_data/Position.hpp"
#include "../../elementary_data/Vector.hpp"

class DirectionalLight : public ALight {
    public:
        DirectionalLight(float intensity, float shininess, const Vector &direction);
        ~DirectionalLight() = default;
        IObject::ObjectType getObjectType() const;
        ILight::LightType getLightType() const;
        double getShininess() const;
        const Vector &getDirectional() const;
    private:
        float _shininess;
        Vector _direction;
};

#endif

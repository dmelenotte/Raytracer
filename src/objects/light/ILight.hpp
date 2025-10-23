#ifndef __ILIGHT__
    #define __ILIGHT__

#include "../IObject.hpp"

#include "../../elementary_data/Vector.hpp"

class ILight : public IObject {
    public:
        enum LightType {
            AMBIENT,
            DIRECTIONAL
        };
        ILight() = default;
        virtual ~ILight() = default;
        virtual LightType getLightType() const = 0;
        virtual double getIntensity() const = 0;
};

#endif
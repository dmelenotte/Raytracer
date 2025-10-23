#ifndef __ALIGHT__
    #define __ALIGHT__

#include "ILight.hpp"

class ALight : public ILight {
    public:
        ALight(float intensity);
        ~ALight() = default;
        double getIntensity() const;
    private:
        float _intensity;
};

#endif

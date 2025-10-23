#ifndef __AMBIENT_LIGHT_CONTAINER__
    #define __AMBIENT_LIGHT_CONTAINER__

#include "AContainer.hpp"

class AmbientLightContainer : public AContainer {
    public:
        AmbientLightContainer();
        ~AmbientLightContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
        void getIntensity(nlohmann::json::const_iterator &jsonIterator);
    private:
        float _intensity;
        bool _getIntensity;
};

#endif

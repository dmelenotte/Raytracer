#ifndef __DIRECTIONAL_LIGHT_CONTAINER__
    #define __DIRECTIONAL_LIGHT_CONTAINER__

#include "AContainer.hpp"

#include "../../elementary_data/Vector.hpp"

class DirectionalLightContainer : public AContainer {
    public:
        DirectionalLightContainer();
        ~DirectionalLightContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
        void getIntensity(nlohmann::json::const_iterator &jsonIterator);
        void getShininess(nlohmann::json::const_iterator &jsonIterator);
        void getDirection(nlohmann::json::const_iterator &jsonIterator);
    private:
        float _intensity;
        float _shininess;
        Vector _direction;

        bool _getIntensity;
        bool _getShininess;
        bool _getDirection;
};

#endif

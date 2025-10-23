#ifndef __DIRECTIONAL_LIGHTS_LIST_CONTAINER__
    #define __DIRECTIONAL_LIGHTS_LIST_CONTAINER__

#include "AContainer.hpp"

class DirectionalsLightsListContainer : public AContainer {
    public:
        DirectionalsLightsListContainer();
        ~DirectionalsLightsListContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
};

#endif

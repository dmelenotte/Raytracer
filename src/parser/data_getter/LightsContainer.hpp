#ifndef __LIGHTS__
    #define __LIGHTS__

#include "AContainer.hpp"

class LightsContainer : public AContainer {
    public:
        LightsContainer();
        ~LightsContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
        bool _getAmbient;
        bool _getDirectionals;
};

#endif

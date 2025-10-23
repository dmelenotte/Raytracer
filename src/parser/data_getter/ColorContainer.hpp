#ifndef __COLOR_CONTAINER__
    #define __COLOR_CONTAINER__

#include "AContainer.hpp"

class ColorContainer : public AContainer {
    public:
        ColorContainer();
        ~ColorContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
        bool _getR;
        bool _getG;
        bool _getB;
};

#endif

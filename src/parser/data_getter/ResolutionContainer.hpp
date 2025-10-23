#ifndef __RESOLUTION_CONTAINER__
    #define __RESOLUTION_CONTAINER__

#include "AContainer.hpp"

class ResolutionContainer : public AContainer {
    public:
        ResolutionContainer();
        ~ResolutionContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
        bool _getWidth;
        bool _getHeight;
};

#endif

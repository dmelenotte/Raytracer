#ifndef __POSITION_CONTAINER__
    #define __POSITION_CONTAINER__

#include "AContainer.hpp"

class PositionContainer : public AContainer {
    public:
        PositionContainer();
        ~PositionContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
        bool _getX;
        bool _getY;
        bool _getZ;
};

#endif

#ifndef __ROTATION_CONTAINER__
    #define __ROTATION_CONTAINER__

#include "AContainer.hpp"

class RotationContainer : public AContainer {
    public:
        RotationContainer();
        ~RotationContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
        bool _getX;
        bool _getY;
        bool _getZ;
};

#endif

#ifndef __VECTOR_CONTAINER__
    #define __VECTOR_CONTAINER__

#include "AContainer.hpp"

class VectorContainer : public AContainer {
    public:
        VectorContainer();
        ~VectorContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
        bool _getX;
        bool _getY;
        bool _getZ;
};

#endif

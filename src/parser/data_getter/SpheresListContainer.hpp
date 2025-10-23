#ifndef __SPHERES_LIST_CONTAINER__
    #define __SPHERES_LIST_CONTAINER__

#include "AContainer.hpp"

class SphereListContainer : public AContainer {
    public:
        SphereListContainer();
        ~SphereListContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
};

#endif

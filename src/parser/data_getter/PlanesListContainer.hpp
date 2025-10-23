#ifndef __PLANES_LIST_CONTAINER__
    #define __PLANES_LIST_CONTAINER__

#include "AContainer.hpp"

class PlanesListContainer : public AContainer {
    public:
        PlanesListContainer();
        ~PlanesListContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
};

#endif

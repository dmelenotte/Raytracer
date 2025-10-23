#ifndef __CONES_LIST_CONTAINER__
    #define __CONES_LIST_CONTAINER__

#include "AContainer.hpp"

class ConesListContainer : public AContainer {
    public:
        ConesListContainer();
        ~ConesListContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
};

#endif

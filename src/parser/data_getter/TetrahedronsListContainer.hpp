#ifndef __TETRAHEDRONS_LIST_CONTAINER__
    #define __TETRAHEDRONS_LIST_CONTAINER__

#include "AContainer.hpp"

class TetrahedronsListContainer : public AContainer {
    public:
        TetrahedronsListContainer();
        ~TetrahedronsListContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
};

#endif

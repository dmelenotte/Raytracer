#ifndef __CYLINDER_LIST_CONTAINER__
    #define __CYLINDER_LIST_CONTAINER__

#include "AContainer.hpp"

class CylindersListContainer : public AContainer {
    public:
        CylindersListContainer();
        ~CylindersListContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
};

#endif

#ifndef __BOXS_LIST_CONTAINER__
    #define __BOXS_LIST_CONTAINER__

#include "AContainer.hpp"

class BoxsListContainer : public AContainer {
    public:
        BoxsListContainer();
        ~BoxsListContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
};

#endif

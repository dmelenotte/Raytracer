#ifndef __PRIMITIVES_CONTAINER__
    #define __PRIMITIVES_CONTAINER__

#include "AContainer.hpp"

class PrimitivesContainer : public AContainer {
    public:
        PrimitivesContainer();
        ~PrimitivesContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
        std::vector<std::pair<bool, std::string>> _gets;
};

#endif

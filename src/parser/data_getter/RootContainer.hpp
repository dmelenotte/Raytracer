#ifndef __ROOT_CONTAINER__
    #define __ROOT_CONTAINER__

#include "AContainer.hpp"

#include "../../objects/ObjectsFactory.hpp"

class RootContainer : public AContainer {
    public:
        RootContainer(ObjectsFactory &factory);
        ~RootContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
        bool _getCamera;
        bool _getPrimitives;
        bool _getLights;
};

#endif

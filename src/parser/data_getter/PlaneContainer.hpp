#ifndef __PLANE_CONTAINER__
    #define __PLANE_CONTAINER__

#include "AContainer.hpp"

#include "../../elementary_data/Color.hpp"

class PlaneContainer : public AContainer {
    public:
        PlaneContainer();
        ~PlaneContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
        void getAxis(nlohmann::json::const_iterator &jsonIterator);
        void getPosition(nlohmann::json::const_iterator &jsonIterator);
        void getColor(nlohmann::json::const_iterator &jsonIterator);
        void getAlbedo(nlohmann::json::const_iterator &jsonIterator);
        void getReflection(nlohmann::json::const_iterator &jsonIterator);
    private:
        char _axis;
        int _position;
        Color _color;
        Color _albedo;
        Color _reflection;

        bool _getAxis;
        bool _getPosition;
        bool _getColor;
        bool _getAlbedo;
        bool _getReflection;
};

#endif

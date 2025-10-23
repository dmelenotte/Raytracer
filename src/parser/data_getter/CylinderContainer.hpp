#ifndef __CYLINDER_CONTAINER__
    #define __CYLINDER_CONTAINER__

#include "AContainer.hpp"

#include "../../elementary_data/Position.hpp"
#include "../../elementary_data/Rotation.hpp"
#include "../../elementary_data/Vector.hpp"
#include "../../elementary_data/Color.hpp"

class CylinderContainer : public AContainer {
    public:
        CylinderContainer();
        ~CylinderContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
        void getPosition(nlohmann::json::const_iterator &jsonIterator);
        void getRadius(nlohmann::json::const_iterator &jsonIterator);
        void getDirection(nlohmann::json::const_iterator &jsonIterator);
        void getColor(nlohmann::json::const_iterator &jsonIterator);
        void getAlbedo(nlohmann::json::const_iterator &jsonIterator);
        void getReflection(nlohmann::json::const_iterator &jsonIterator);
    private:
        Position _position;
        float _radius;
        Vector _direction;
        Color _color;
        Color _albedo;
        Color _reflection;

        bool _getPosition;
        bool _getRadius;
        bool _getDirection;
        bool _getColor;
        bool _getAlbedo;
        bool _getReflection;
};

#endif

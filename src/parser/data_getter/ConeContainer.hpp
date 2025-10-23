#ifndef __CONE_CONTAINER__
    #define __CONE_CONTAINER__

#include "AContainer.hpp"

#include "../../elementary_data/Position.hpp"
#include "../../elementary_data/Rotation.hpp"
#include "../../elementary_data/Vector.hpp"
#include "../../elementary_data/Color.hpp"

class ConeContainer : public AContainer {
    public:
        ConeContainer();
        ~ConeContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
        void getPosition(nlohmann::json::const_iterator &jsonIterator);
        void getAngle(nlohmann::json::const_iterator &jsonIterator);
        void getDirection(nlohmann::json::const_iterator &jsonIterator);
        void getColor(nlohmann::json::const_iterator &jsonIterator);
        void getAlbedo(nlohmann::json::const_iterator &jsonIterator);
        void getReflection(nlohmann::json::const_iterator &jsonIterator);
    private:
        Position _position;
        float _angle;
        Vector _direction;
        Color _color;
        Color _albedo;
        Color _reflection;

        bool _getPosition;
        bool _getAngle;
        bool _getDirection;
        bool _getColor;
        bool _getAlbedo;
        bool _getReflection;
};

#endif

#ifndef __TETRAHEDRONS_CONTAINER__
    #define __TETRAHEDRONS_CONTAINER__

#include "AContainer.hpp"

#include "../../elementary_data/Position.hpp"
#include "../../elementary_data/Rotation.hpp"
#include "../../elementary_data/Vector.hpp"
#include "../../elementary_data/Color.hpp"

class TetrahedronContainer : public AContainer {
    public:
        TetrahedronContainer();
        ~TetrahedronContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
        void getPoint1(nlohmann::json::const_iterator &jsonIterator);
        void getPoint2(nlohmann::json::const_iterator &jsonIterator);
        void getPoint3(nlohmann::json::const_iterator &jsonIterator);
        void getPoint4(nlohmann::json::const_iterator &jsonIterator);
        void getDirection(nlohmann::json::const_iterator &jsonIterator);
        void getColor(nlohmann::json::const_iterator &jsonIterator);
        void getAlbedo(nlohmann::json::const_iterator &jsonIterator);
        void getReflection(nlohmann::json::const_iterator &jsonIterator);
    private:
        Position _point1;
        Position _point2;
        Position _point3;
        Position _point4;
        Vector _direction;
        Color _color;
        Color _albedo;
        Color _reflection;

        bool _getPoint1;
        bool _getPoint2;
        bool _getPoint3;
        bool _getPoint4;
        bool _getDirection;
        bool _getColor;
        bool _getAlbedo;
        bool _getReflection;
};

#endif

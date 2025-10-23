#ifndef __SPHERE_CONTAINER__
    #define __SPHERE_CONTAINER__

#include "AContainer.hpp"

#include "../../elementary_data/Position.hpp"
#include "../../elementary_data/Rotation.hpp"
#include "../../elementary_data/Vector.hpp"
#include "../../elementary_data/Color.hpp"

class SphereContainer : public AContainer {
    public:
        SphereContainer();
        ~SphereContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
        void getPosition(nlohmann::json::const_iterator &jsonIterator);
        void getRadius(nlohmann::json::const_iterator &jsonIterator);
        void getColor(nlohmann::json::const_iterator &jsonIterator);
        void getAlbedo(nlohmann::json::const_iterator &jsonIterator);
        void getReflection(nlohmann::json::const_iterator &jsonIterator);
    private:
        Position _position;
        float _radius;
        Color _color;
        Color _albedo;
        Color _reflection;

        bool _getPosition;
        bool _getRadius;
        bool _getColor;
        bool _getAlbedo;
        bool _getReflection;
};

#endif

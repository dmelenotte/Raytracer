#ifndef __BOX_CONTAINER__
    #define __BOX_CONTAINER__

#include "AContainer.hpp"

#include "../../elementary_data/Position.hpp"
#include "../../elementary_data/Rotation.hpp"
#include "../../elementary_data/Vector.hpp"
#include "../../elementary_data/Color.hpp"

class BoxContainer : public AContainer {
    public:
        BoxContainer();
        ~BoxContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
        void getPosition(nlohmann::json::const_iterator &jsonIterator);
        void getWidth(nlohmann::json::const_iterator &jsonIterator);
        void getHeight(nlohmann::json::const_iterator &jsonIterator);
        void getDepth(nlohmann::json::const_iterator &jsonIterator);
        void getDirection(nlohmann::json::const_iterator &jsonIterator);
        void getColor(nlohmann::json::const_iterator &jsonIterator);
        void getAlbedo(nlohmann::json::const_iterator &jsonIterator);
        void getReflection(nlohmann::json::const_iterator &jsonIterator);
    private:
        Position _position;
        int _width;
        int _height;
        int _depth;
        Vector _direction;
        Color _color;
        Color _albedo;
        Color _reflection;

        bool _getPosition;
        bool _getWidth;
        bool _getHeight;
        bool _getDepth;
        bool _getDirection;
        bool _getColor;
        bool _getAlbedo;
        bool _getReflection;
};

#endif

#ifndef __CAMERA_CONTAINER__
    #define __CAMERA_CONTAINER__

#include "AContainer.hpp"

#include "../../elementary_data/Position.hpp"
#include "../../elementary_data/Rotation.hpp"

class CameraContainer : public AContainer {
    public:
        CameraContainer();
        ~CameraContainer() = default;
        void execContainer(const nlohmann::json &json);
        void execContainer(nlohmann::json::const_iterator &jsonIterator);
    private:
        void getResolution(nlohmann::json::const_iterator &jsonIterator);
        void getPosition(nlohmann::json::const_iterator &jsonIterator);
        void getRotation(nlohmann::json::const_iterator &jsonIterator);
        void getFov(nlohmann::json::const_iterator &jsonIterator);
        void getDepth(nlohmann::json::const_iterator &jsonIterator);
    private:
        int _width;
        int _height;
        Position _position;
        Rotation _rotation;
        float _fov;
        int _depth;

        bool _getResolution;
        bool _getPosition;
        bool _getRotation;
        bool _getFov;
        bool _getDepth;

};

#endif

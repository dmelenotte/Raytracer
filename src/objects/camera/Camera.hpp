#ifndef __CAMERA__
    #define __CAMERA__

#include "../IObject.hpp"

#include "../../elementary_data/Position.hpp"
#include "../../elementary_data/Rotation.hpp"
#include "../../elementary_data/Matrix.hpp"
#include "../../elementary_data/Ray.hpp"

#include "../../pixel_buffer/PixelBuffer.hpp"

class Camera : public IObject {
    public:
        Camera(int width, int height, const Position &position, const Rotation &rotation, float fov, int depth);
        ~Camera() = default;
        IObject::ObjectType getObjectType() const;
        int getWidth() const;
        int getHeight() const;
        float getFov() const;
        int getDepth() const;
        PixelBuffer &getBuffer();
        const PixelBuffer &getBuffer() const;
        Ray ray(double x, double y);
    private:
        int _width;
        int _height;
        Position _position;
        Rotation _rotation;
        float _fov;
        int _depth;
        PixelBuffer _buffer;
};

#endif

#ifndef __ALL_TYPES__
    #define __ALL_TYPES__

#include "IType.hpp"

#include "../../../objects/ObjectsFactory.hpp"
#include "../../../objects/IObject.hpp"

#include "../../../elementary_data/Position.hpp"
#include "../../../elementary_data/Rotation.hpp"
#include "../../../elementary_data/Color.hpp"

class IntType : public IType {
    public:
        IntType(int value) : _value(value) {}
        ~IntType() = default;
    public:
        int _value;
};

class FloatType : public IType {
    public:
        FloatType(float value) : _value(value) {}
        ~FloatType() = default;
    public:
        float _value;
};

class CharType : public IType {
    public:
        CharType(char value) : _value(value) {}
        ~CharType() = default;
    public:
        char _value;
};

class FactoryType : public IType {
    public:
        FactoryType(ObjectsFactory &factory) : _factory(factory) {}
        ~FactoryType() = default;
    public:
        ObjectsFactory &_factory;
};

class ObjectListType : public IType {
    public:
        ObjectListType() = default;
        ~ObjectListType()
        {
            for (auto it = _listObject.begin(); it != _listObject.end(); ++it) {
                (*it).reset();
            }
        }
    public:
        std::vector<std::shared_ptr<IObject>> _listObject;
};

class ObjectType : public IType {
    public:
        ObjectType() = default;
        ObjectType(std::shared_ptr<IObject> object) : _object(object) {}
        ~ObjectType() {_object.reset();}
    public:
        std::shared_ptr<IObject> _object;
};

class ResolutionType : public IType {
    public:
        ResolutionType(int width, int height) : _width(width), _height(height) {}
        ~ResolutionType() = default;
    public:
        int _width;
        int _height;
};

class PositionType : public IType {
    public:
        PositionType(int x, int y, int z) : _x(x), _y(y), _z(z) {}
        ~PositionType() = default;
        operator Position () {return Position(_x, _y, _z);}
    public:
        int _x;
        int _y;
        int _z;
};

class RotationType : public IType {
    public:
        RotationType(int x, int y, int z) : _x(x), _y(y), _z(z) {}
        ~RotationType() = default;
        operator Rotation () {return Rotation(_x, _y, _z);}
    public:
        int _x;
        int _y;
        int _z;
};

class VectorType : public IType {
    public:
        VectorType(int x, int y, int z) : _x(x), _y(y), _z(z) {}
        ~VectorType() = default;
        operator Vector () {return Vector(_x, _y, _z);}
        operator Color () {return Color(_x, _y, _z);}
    public:
        int _x;
        int _y;
        int _z;
};

class ColorType : public IType {
    public:
        ColorType(unsigned char r, unsigned char g, unsigned char b) : _r(r), _g(g), _b(b) {}
        ~ColorType() = default;
        operator Color () {return Color(_r, _g, _b);}
    public:
        unsigned char _r;
        unsigned char _g;
        unsigned char _b;
};

#endif

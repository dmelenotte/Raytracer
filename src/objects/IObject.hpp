#ifndef __IOBJECT__
    #define __IOBJECT__

#include <cstddef>

class IObject {
    public:
        enum ObjectType {
            CAMERA,
            LIGHT,
            PRIMITIVE
        };

        IObject() = default;
        virtual ~IObject() = default;
        virtual ObjectType getObjectType() const = 0;
};

#endif

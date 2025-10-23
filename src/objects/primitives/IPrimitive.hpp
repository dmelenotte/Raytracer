#ifndef __IPRIMITIVE__
    #define __IPRIMITIVE__

#include "../IObject.hpp"

#include "../../elementary_data/Color.hpp"
#include "../../elementary_data/Ray.hpp"

class IPrimitive : public IObject {
    public:
        IPrimitive() = default;
        virtual ~IPrimitive() = default;
        virtual bool hit(const Ray &ray, double &t, Vector &normal) = 0;
        virtual const Color &getColor() const = 0;
        virtual const Color &getAlbedo() const = 0;
        virtual const Color &getReflectivity() const = 0;
};

#endif

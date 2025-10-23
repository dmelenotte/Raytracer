#ifndef __APRIMIVITE__
    #define __APRIMIVITE__

#include "IPrimitive.hpp"

#include "../../elementary_data/Color.hpp"

class APrimitive : public IPrimitive {
    public:
        APrimitive() = default;
        APrimitive(const Color &color, const Color &albedo, const Color &reflection);
        const Color &getColor() const;
        const Color &getAlbedo() const;
        const Color &getReflectivity() const;
    protected:
        Color _color;
        Color _albedo;
        Color _reflection;
};

#endif

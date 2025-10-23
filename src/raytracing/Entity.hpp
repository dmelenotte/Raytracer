#ifndef __ENTITY__
    #define __ENTITY__

#include "../objects/IObject.hpp"
#include "../objects/ObjectsFactory.hpp"
#include "../objects/primitives/IPrimitive.hpp"
#include "../objects/light/ILight.hpp"

#include <memory>
#include <vector>

class Entity {
    public:
        Entity(std::shared_ptr<IObject> object);
        Entity(const Entity &other);
        ~Entity();
        void registerEntity(const Entity &entity);
        void registerLights(const std::vector<std::shared_ptr<IObject>> &lights);
        Color calculateLightning(const Vector &hitPoint, const Vector &normal, const Vector &viewDirection);
        std::shared_ptr<IPrimitive> &getPrimitive();
        const std::shared_ptr<IPrimitive> &getPrimitive() const;
    private:
        bool inShadow(const Vector &point, const Vector &lightDirection);

        std::shared_ptr<IPrimitive> _primitive;
        std::vector<Entity> _connectedEntities;
        std::vector<std::shared_ptr<ILight>> _lights;
};

#endif

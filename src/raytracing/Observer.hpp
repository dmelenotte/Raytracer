#ifndef __OBSERVER__
    #define __OBSERVER__

#include "Entity.hpp"

#include "../objects/IObject.hpp"
#include "../objects/camera/Camera.hpp"
#include "../objects/primitives/IPrimitive.hpp"
#include "../graphic_render/Window.hpp"

#include <memory>
#include <vector>

class Observer {
    public:
        Observer(std::shared_ptr<IObject> object);
        ~Observer();
        void registerEntity(std::shared_ptr<IObject> object);
        void registerLights(const std::vector<std::shared_ptr<IObject>> &lights);
        void rendering();
    private:
        void calculRendering();
        Color getHit(const Ray &ray);
    private:
        int _currentDepth;
        std::shared_ptr<Camera> _camera;
        std::vector<Entity> _connectedEntities;
        Window _window;
};

#endif

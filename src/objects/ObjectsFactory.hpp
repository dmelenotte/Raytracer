#ifndef __OBJECTS_FACTORY__
    #define __OBJECTS_FACTORY__

#include "IObject.hpp"

#include "camera/Camera.hpp"
#include "light/AmbientLight.hpp"
#include "light/DirectionalLight.hpp"
#include "primitives/Plane.hpp"
#include "primitives/Sphere.hpp"
#include "primitives/Box.hpp"
#include "primitives/Cylinder.hpp"
#include "primitives/Tetrahedron.hpp"
#include "primitives/Cone.hpp"

#include "../elementary_data/Position.hpp"
#include "../elementary_data/Rotation.hpp"
#include "../elementary_data/Color.hpp"

#include <cstdarg>
#include <functional>
#include <memory>
#include <vector>
#include <map>

class ObjectsFactory {
    public:
        enum Object {
            CAMERA,
            AMBIENT_LIGHT,
            DIRECTIONAL_LIGHT,
            PLANE,
            SPHERE,
            BOX,
            CYLINDER,
            TETRAHEDRON,
            CONE
        };

        ObjectsFactory() = default;
        ~ObjectsFactory() = default;
        std::shared_ptr<IObject> createObject(Object object, ...);
        void addObject(std::shared_ptr<IObject> object);
        void clearObjects();
        const std::vector<std::shared_ptr<IObject>> &getAllObjects() const;
        std::shared_ptr<IObject> getObject(IObject::ObjectType objectType,
            const std::vector<std::shared_ptr<IObject>> &excludePointers) const;
    private:
        std::shared_ptr<IObject> createCamera(std::va_list &args);
        std::shared_ptr<IObject> createAmbientLight(std::va_list &args);
        std::shared_ptr<IObject> createDirectionalLight(std::va_list &args);
        std::shared_ptr<IObject> createPlane(std::va_list &args);
        std::shared_ptr<IObject> createSphere(std::va_list &args);
        std::shared_ptr<IObject> createBox(std::va_list &args);
        std::shared_ptr<IObject> createCylinder(std::va_list &args);
        std::shared_ptr<IObject> createTetrahedron(std::va_list &args);
        std::shared_ptr<IObject> createCone(std::va_list &args);

        std::vector<std::shared_ptr<IObject>> _allObjects;
        std::map<Object, std::function<std::shared_ptr<IObject>(std::va_list &)>> _factory {
            {CAMERA, [this](std::va_list &args){return this->createCamera(args);}},
            {AMBIENT_LIGHT, [this](std::va_list &args){return this->createAmbientLight(args);}},
            {DIRECTIONAL_LIGHT, [this](std::va_list &args){return this->createDirectionalLight(args);}},
            {PLANE, [this](std::va_list &args){return this->createPlane(args);}},
            {SPHERE, [this](std::va_list &args){return this->createSphere(args);}},
            {BOX, [this](std::va_list &args){return this->createBox(args);}},
            {CYLINDER, [this](std::va_list &args){return this->createCylinder(args);}},
            {TETRAHEDRON, [this](std::va_list &args){return this->createTetrahedron(args);}},
            {CONE, [this](std::va_list &args){return this->createCone(args);}}
        };
};

#endif

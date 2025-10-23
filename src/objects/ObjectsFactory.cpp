#include "ObjectsFactory.hpp"

#include "../errors/ObjectFactoryException.hpp"
#include <iostream>

std::shared_ptr<IObject> ObjectsFactory::createObject(ObjectsFactory::Object object, ...)
{
    std::va_list args;
    va_start(args, object);
    std::shared_ptr<IObject> newObject = _factory[object](args);
    va_end(args);
    return newObject;
}

void ObjectsFactory::addObject(std::shared_ptr<IObject> object)
{
    if (object.get() == nullptr) {
        return;
    }
    _allObjects.push_back(object);
}

void ObjectsFactory::clearObjects()
{
    _allObjects.clear();
}

const std::vector<std::shared_ptr<IObject>> &ObjectsFactory::getAllObjects() const
{
    return _allObjects;
}

std::shared_ptr<IObject> ObjectsFactory::getObject(IObject::ObjectType objectType,
    const std::vector<std::shared_ptr<IObject>> &excludePointers) const
{
    for (auto it = _allObjects.begin(); it != _allObjects.end(); ++it) {
        bool isExclude = false;
        if (!excludePointers.empty()) {
            for (auto itP = excludePointers.begin(); itP != excludePointers.end(); ++itP) {
                if ((*it) == (*itP)) {
                    isExclude = true;
                    break;
                }
            }
        }
        if (isExclude) {
            continue;
        }
        if ((*it)->getObjectType() == objectType) {
            return (*it);
        }
    }
    return {nullptr};
}

/* ----- Private ----- */

std::shared_ptr<IObject> ObjectsFactory::createCamera(std::va_list &args)
{
    int width = va_arg(args, int);
    int height = va_arg(args, int);
    Position *position = va_arg(args, Position *);
    Rotation *rotation = va_arg(args, Rotation *);
    double fod = va_arg(args, double);
    int depth = va_arg(args, int);

    if (position == nullptr || rotation == nullptr) {
        throw ObjectFactoryException();
    }
    std::shared_ptr<IObject> newObject(new Camera(width, height, *position, *rotation, fod, depth));
    _allObjects.push_back(newObject);
    return newObject;
}

std::shared_ptr<IObject> ObjectsFactory::createAmbientLight(std::va_list &args)
{
    float intensity = (float)va_arg(args, double);

    std::shared_ptr<IObject> newObject(new AmbientLight(intensity));
    _allObjects.push_back(newObject);
    return newObject;
}

std::shared_ptr<IObject> ObjectsFactory::createDirectionalLight(std::va_list &args)
{
    float intensity = (float)va_arg(args, double);
    float shininess = (float)va_arg(args, double);
    Vector *direction = va_arg(args, Vector *);

    if (direction == nullptr) {
        throw ObjectFactoryException();
    }
    std::shared_ptr<IObject> newObject(new DirectionalLight(intensity, shininess, *direction));
    _allObjects.push_back(newObject);
    return newObject;
}

std::shared_ptr<IObject> ObjectsFactory::createPlane(std::va_list &args)
{
    char axis = (char)va_arg(args, int);
    int position = va_arg(args, int);
    Color *color = va_arg(args, Color *);
    Color *albedo = va_arg(args, Color *);
    Color *reflection = va_arg(args, Color *);

    if (color == nullptr || albedo == nullptr || reflection == nullptr) {
        throw ObjectFactoryException();
    }
    std::shared_ptr<IObject> newObject(new Plane(axis, position, *color, *albedo, *reflection));
    _allObjects.push_back(newObject);
    return newObject;
}

std::shared_ptr<IObject> ObjectsFactory::createSphere(std::va_list &args)
{
    Position *position = va_arg(args, Position *);
    float rayon = va_arg(args, double);
    Color *color = va_arg(args, Color *);
    Color *albedo = va_arg(args, Color *);
    Color *reflection = va_arg(args, Color *);

    if (color == nullptr || albedo == nullptr || reflection == nullptr) {
        throw ObjectFactoryException();
    }
    std::shared_ptr<IObject> newObject(new Sphere(*position, rayon, *color, *albedo, *reflection));
    _allObjects.push_back(newObject);
    return newObject;
}

std::shared_ptr<IObject> ObjectsFactory::createBox(std::va_list &args)
{
    Position *position = va_arg(args, Position *);
    int wight = va_arg(args, int);
    int height = va_arg(args, int);
    int depth = va_arg(args, int);
    Vector *direction = va_arg(args, Vector *);
    Color *color = va_arg(args, Color *);
    Color *albedo = va_arg(args, Color *);
    Color *reflection = va_arg(args, Color *);

    if (color == nullptr || albedo == nullptr || reflection == nullptr) {
        throw ObjectFactoryException();
    }
    std::shared_ptr<IObject> newObject(new Box(*position, height, wight, depth, *direction, *color, *albedo, *reflection));
    _allObjects.push_back(newObject);
    return newObject;
}

std::shared_ptr<IObject> ObjectsFactory::createCylinder(std::va_list &args)
{
    Position *position = va_arg(args, Position *);
    double radius = va_arg(args, double);
    Vector *direction = va_arg(args, Vector *);
    Color *color = va_arg(args, Color *);
    Color *albedo = va_arg(args, Color *);
    Color *reflection = va_arg(args, Color *);

    if (color == nullptr || albedo == nullptr || reflection == nullptr) {
        throw ObjectFactoryException();
    }
    std::shared_ptr<IObject> newObject(new Cylinder(*position, radius, *direction, *color, *albedo, *reflection));
    _allObjects.push_back(newObject);
    return newObject;
}

std::shared_ptr<IObject> ObjectsFactory::createTetrahedron(std::va_list &args)
{
    Position *point1 = va_arg(args, Position *);
    Position *point2 = va_arg(args, Position *);
    Position *point3 = va_arg(args, Position *);
    Position *point4 = va_arg(args, Position *);
    Vector *direction = va_arg(args, Vector *);
    Color *color = va_arg(args, Color *);
    Color *albedo = va_arg(args, Color *);
    Color *reflection = va_arg(args, Color *);

    if (color == nullptr || albedo == nullptr || reflection == nullptr) {
        throw ObjectFactoryException();
    }
    std::shared_ptr<IObject> newObject(new Tetrahedron(*point1, *point2, *point3, *point4, *direction, *color, *albedo, *reflection));
    _allObjects.push_back(newObject);
    return newObject;
}

std::shared_ptr<IObject> ObjectsFactory::createCone(std::va_list &args)
{
    Position *point = va_arg(args, Position *);
    double angle = va_arg(args, double);
    Vector *direction = va_arg(args, Vector *);
    Color *color = va_arg(args, Color *);
    Color *albedo = va_arg(args, Color *);
    Color *reflection = va_arg(args, Color *);

    if (color == nullptr || albedo == nullptr || reflection == nullptr) {
        throw ObjectFactoryException();
    }
    std::shared_ptr<IObject> newObject(new Cone(*point, angle, *direction, *color, *albedo, *reflection));
    _allObjects.push_back(newObject);
    return newObject;
}
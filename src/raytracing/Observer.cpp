#include "Observer.hpp"

#include <cmath>
#include <iostream>
#include <thread>
#include <mutex>

std::mutex pixels;

Observer::Observer(std::shared_ptr<IObject> object) : _currentDepth(0), _window(1920, 1080)
{
    Camera *ptr = dynamic_cast<Camera *>(object.get());
    if (ptr == nullptr) {
        return;
    }
    _camera.reset(ptr, [](Camera *){});
    _window.resize(_camera->getBuffer().getBufferWidth(),
    _camera->getBuffer().getBufferHeight());
}

Observer::~Observer()
{
    _camera.reset();
}

void Observer::registerEntity(std::shared_ptr<IObject> object)
{
    Entity newEntity(object);

    for (auto it = _connectedEntities.begin(); it != _connectedEntities.end(); ++it) {
        (*it).registerEntity(newEntity);
        newEntity.registerEntity((*it));
    }
    _connectedEntities.push_back(newEntity);
}

void Observer::registerLights(const std::vector<std::shared_ptr<IObject>> &lights)
{
    for (auto it = _connectedEntities.begin(); it != _connectedEntities.end(); ++it) {
        (*it).registerLights(lights);
    }
}

void Observer::rendering()
{
    std::thread tCalcul(&Observer::calculRendering, this);
    _window.render();
    tCalcul.join();
}

/* ----- Private ----- */

void Observer::calculRendering()
{
    double ratio = (double)_camera->getBuffer().getBufferWidth() / _camera->getBuffer().getBufferHeight();
    double scale = std::tan(_camera->getFov() * 0.5 * M_PI / 180.0f);
    for (std::size_t y = 0; y < (std::size_t)_camera->getBuffer().getBufferHeight(); y++) {
        for (std::size_t x = 0; x < (std::size_t)_camera->getBuffer().getBufferWidth(); x++) {
            double px = (2 * ((x + 0.5) / _camera->getBuffer().getBufferWidth()) - 1) * ratio * scale;
            double py = (1 - 2 * ((y + 0.5) / _camera->getBuffer().getBufferHeight())) * scale;
            Ray ray = _camera->ray(px, py);
            Color writeColor = this->getHit(ray);
            _camera->getBuffer().at(x, y) = writeColor;
            pixels.lock();
            _window.pushAt(x, y, writeColor);
            pixels.unlock();
            _currentDepth = 0;
        }
    }
}

Color Observer::getHit(const Ray &ray)
{
    if (_currentDepth > _camera->getDepth()) {
        return Color(0, 0, 0);
    }

    Color writeColor(0, 0, 0);
    Vector normal;
    Position hitPoint;
    Color reflectivity = {0, 0, 0};
    bool hit = false;

    double t;
    double tMin = std::numeric_limits<double>::max();
    for (auto it = _connectedEntities.begin(); it != _connectedEntities.end(); ++it) {
        bool hasHit = (*it).getPrimitive()->hit(ray, t, normal);
        if (hasHit && t < tMin) {
            tMin = t;
            hitPoint = ray.getPoint() + ray.getVector() * t;
            Vector viewDirection = -ray.getVector();
            writeColor = (*it).calculateLightning(Vector(hitPoint.getX(), hitPoint.getY(), hitPoint.getZ()),
                normal, viewDirection);
            reflectivity = (*it).getPrimitive()->getReflectivity();
            hit = true;
        }
    }
    if (hit && (reflectivity.get(Color::R) > 0 || reflectivity.get(Color::G) > 0 || reflectivity.get(Color::B) > 0)) {
        Vector reflectionDirection = ray.getVector() - normal * (2.0 * ray.getVector().dot(normal));
        reflectionDirection = reflectionDirection.normalized();
        Vector newVectorOrigin = hitPoint + reflectionDirection * 0.01;
        Ray newRay(Position(newVectorOrigin.getX(), newVectorOrigin.getY(), newVectorOrigin.getZ()), reflectionDirection);
        _currentDepth++;
        Color reflectedColor = this->getHit(newRay);

        writeColor.change(Color::R, (writeColor.get(Color::R) *
            (1 - reflectivity.get(Color::R) / 255.0) + reflectedColor.get(Color::R) *
            (reflectivity.get(Color::R) / 255.0)));
        writeColor.change(Color::G, (writeColor.get(Color::G) *
            (1 - reflectivity.get(Color::G) / 255.0) + reflectedColor.get(Color::G) *
            (reflectivity.get(Color::G) / 255.0)));
        writeColor.change(Color::B, (writeColor.get(Color::B) *
            (1 - reflectivity.get(Color::B) / 255.0) + reflectedColor.get(Color::B) *
            (reflectivity.get(Color::B) / 255.0)));
    }
    writeColor.clamp();
    return writeColor;
}

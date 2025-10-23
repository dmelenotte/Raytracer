#include "file_manager/FileManager.hpp"
#include "file_manager/ImageManager.hpp"
#include "errors/FileManagerException.hpp"
#include "errors/ImageManagerException.hpp"

#include "parser/JsonParser.hpp"
#include "errors/JsonParserException.hpp"

#include "objects/ObjectsFactory.hpp"

#include "parser/data_getter/ContainerFactory.hpp"
#include "parser/data_getter/RootContainer.hpp"

#include "errors/ContainerException.hpp"

#include "pixel_buffer/PixelBuffer.hpp"

#include "raytracing/Observer.hpp"

#include <iostream>

#define USAGE "USAGE: ./raytracer <SCENE_FILE>\n  SCENE_FILE: scene configuration"

static bool saveImg(const ObjectsFactory &factory)
{
    std::shared_ptr<Camera> camera(dynamic_cast<Camera *>
        (factory.getObject(IObject::CAMERA, {}).get()), [](Camera *) {});
    if (camera.get() == nullptr) {
        return false;
    }
    if (camera->getBuffer().empty()) {
        std::cerr << "-W- >> Render impossible with no resolution." << std::endl;
        return true;
    }
    try {
        ImageManager img("output.ppm");
        img.save(camera->getBuffer());
    } catch (ImageManagerException &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    return true;
}

static void setObserver(const ObjectsFactory &factory, Observer &observer)
{
    std::vector<std::shared_ptr<IObject>> excludeObjects;
    std::vector<std::shared_ptr<IObject>> lights;

    std::shared_ptr<IObject> tmpObject = factory.getObject(IObject::LIGHT, excludeObjects);
    while (tmpObject.get() != nullptr) {
        excludeObjects.push_back(tmpObject);
        lights.push_back(tmpObject);
        tmpObject = factory.getObject(IObject::LIGHT, excludeObjects);
    }
    tmpObject = factory.getObject(IObject::PRIMITIVE, excludeObjects);
    while (tmpObject.get() != nullptr) {
        excludeObjects.push_back(tmpObject);
        observer.registerEntity(tmpObject);
        tmpObject = factory.getObject(IObject::PRIMITIVE, excludeObjects);
    }
    observer.registerLights(lights);
}

int main(int argc, const char **argv)
{
    if (argc != 2) {
        std::cerr << "-E- >> No scene file or -help given as parameter." << std::endl;
        return 84;
    }
    if (std::string(argv[1]) == "-help") {
        std::cout << USAGE << std::endl;
        return 0;
    }
    FileManager file(argv[1], ".json");
    try {
        file.read();
    } catch (FileManagerException &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    JsonParser jsonFile;
    try {
        jsonFile.parse(file.getContent());
    } catch (JsonParserException &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    ObjectsFactory factory;
    std::shared_ptr<IContainer> container(new RootContainer(factory));
    ContainerFactory containerFactory(container);
    try {
        container->execContainer(jsonFile.getJson());
    } catch (JsonParserException &e) {
        std::cout << e.what() << std::endl;
        return 84;
    } catch (ContainerException &e) {
        std::cout << e.what() << std::endl;
        return 84;
    }
    Observer observer(factory.getObject(IObject::CAMERA, {}));
    setObserver(factory, observer);
    observer.rendering();
    if (!saveImg(factory)) {
        return 84;
    }
    return 0;
}

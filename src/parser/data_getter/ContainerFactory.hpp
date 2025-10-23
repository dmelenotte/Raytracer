#ifndef __CONTAINER_FACTORY__
    #define __CONTAINER_FACTORY__

#include "IContainer.hpp"

#include <memory>
#include <map>
#include <functional>

class ContainerFactory {
    public:
        ContainerFactory(std::shared_ptr<IContainer> root);
        ~ContainerFactory() = default;
    private:
        void registerAll(std::shared_ptr<IContainer> container);

        std::shared_ptr<IContainer> createResolutionContainer();
        std::shared_ptr<IContainer> createPositionContainer();
        std::shared_ptr<IContainer> createRotationContainer();
        std::shared_ptr<IContainer> createVectorContainer();
        std::shared_ptr<IContainer> createColorContainer();
        std::shared_ptr<IContainer> createCameraContainer();
        std::shared_ptr<IContainer> createPrimitivesContainer();
        std::shared_ptr<IContainer> createSpheresListContainer();
        std::shared_ptr<IContainer> createSphereContainer();
        std::shared_ptr<IContainer> createPlanesListContainer();
        std::shared_ptr<IContainer> createPlaneContainer();
        std::shared_ptr<IContainer> createCylindersListContainer();
        std::shared_ptr<IContainer> createCylinderContainer();
        std::shared_ptr<IContainer> createConesListContainer();
        std::shared_ptr<IContainer> createConeContainer();
        std::shared_ptr<IContainer> createBoxsListContainer();
        std::shared_ptr<IContainer> createBoxContainer();
        std::shared_ptr<IContainer> createTetrahedronsListContainer();
        std::shared_ptr<IContainer> createTetrahedronContainer();
        std::shared_ptr<IContainer> createLightsContainer();
        std::shared_ptr<IContainer> createAmbientLightContainer();
        std::shared_ptr<IContainer> createDirectionalsLightsListContainer();
        std::shared_ptr<IContainer> createDirectionalLightContainer();
    private:
        std::shared_ptr<IContainer> _root;

        std::map<std::string, std::function<std::shared_ptr<IContainer>()>> _factory = {
            {"resolution", [this](){return this->createResolutionContainer();}},
            {"position", [this](){return this->createPositionContainer();}},
            {"rotation", [this](){return this->createRotationContainer();}},
            {"vector", [this](){return this->createVectorContainer();}},
            {"color", [this](){return this->createColorContainer();}},
            {"camera", [this](){return this->createCameraContainer();}},
            {"primitives", [this](){return this->createPrimitivesContainer();}},
            {"spheres", [this](){return this->createSpheresListContainer();}},
            {"sphere", [this](){return this->createSphereContainer();}},
            {"planes", [this](){return this->createPlanesListContainer();}},
            {"plane", [this](){return this->createPlaneContainer();}},
            {"cylinders", [this](){return this->createCylindersListContainer();}},
            {"cylinder", [this](){return this->createCylinderContainer();}},
            {"cones", [this](){return this->createConesListContainer();}},
            {"cone", [this](){return this->createConeContainer();}},
            {"boxs", [this](){return this->createBoxsListContainer();}},
            {"box", [this](){return this->createBoxContainer();}},
            {"tetrahedrons", [this](){return this->createTetrahedronsListContainer();}},
            {"tetrahedron", [this](){return this->createTetrahedronContainer();}},
            {"lights", [this](){return this->createLightsContainer();}},
            {"ambient", [this](){return this->createAmbientLightContainer();}},
            {"directionals", [this](){return this->createDirectionalsLightsListContainer();}},
            {"directional", [this](){return this->createDirectionalLightContainer();}}
        };
};

#endif

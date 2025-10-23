#include "ContainerFactory.hpp"

#include "ResolutionContainer.hpp"
#include "PositionContainer.hpp"
#include "RotationContainer.hpp"
#include "VectorContainer.hpp"
#include "ColorContainer.hpp"
#include "CameraContainer.hpp"
#include "PrimitivesContainer.hpp"
#include "SpheresListContainer.hpp"
#include "SphereContainer.hpp"
#include "PlanesListContainer.hpp"
#include "PlaneContainer.hpp"
#include "CylindersListContainer.hpp"
#include "CylinderContainer.hpp"
#include "ConesListContainer.hpp"
#include "ConeContainer.hpp"
#include "BoxsListContainer.hpp"
#include "BoxContainer.hpp"
#include "TetrahedronsListContainer.hpp"
#include "TetrahedronsContainer.hpp"
#include "LightsContainer.hpp"
#include "AmbientLightContainer.hpp"
#include "DirectionalsLightsListContainer.hpp"
#include "DirectionalLightContainer.hpp"

ContainerFactory::ContainerFactory(std::shared_ptr<IContainer> root) : _root(root)
{
    this->registerAll(_root);
}

/* ---- Private ---- */

void ContainerFactory::registerAll(std::shared_ptr<IContainer> container)
{
    for (auto it = container->getNeeds().begin(); it != container->getNeeds().end(); ++it) {
        if (!_factory.contains((*it))) {
            continue;
        }
        std::shared_ptr<IContainer> tmpContainer = _factory[(*it)]();
        container->registerContainer((*it), tmpContainer);
        this->registerAll(tmpContainer);
    }
}

std::shared_ptr<IContainer> ContainerFactory::createResolutionContainer()
{
    return std::shared_ptr<IContainer>(new ResolutionContainer());
}

std::shared_ptr<IContainer> ContainerFactory::createPositionContainer()
{
    return std::shared_ptr<IContainer>(new PositionContainer());
}

std::shared_ptr<IContainer> ContainerFactory::createRotationContainer()
{
    return std::shared_ptr<IContainer>(new RotationContainer());
}

std::shared_ptr<IContainer> ContainerFactory::createVectorContainer()
{
    return std::shared_ptr<IContainer>(new VectorContainer());
}

std::shared_ptr<IContainer> ContainerFactory::createColorContainer()
{
    return std::shared_ptr<IContainer>(new ColorContainer());
}

std::shared_ptr<IContainer> ContainerFactory::createCameraContainer()
{
    return std::shared_ptr<IContainer>(new CameraContainer());
}

std::shared_ptr<IContainer> ContainerFactory::createPrimitivesContainer()
{
    return std::shared_ptr<IContainer>(new PrimitivesContainer());
}

std::shared_ptr<IContainer> ContainerFactory::createSpheresListContainer()
{
    return std::shared_ptr<IContainer>(new SphereListContainer());
}

std::shared_ptr<IContainer> ContainerFactory::createSphereContainer()
{
    return std::shared_ptr<IContainer>(new SphereContainer());
}

std::shared_ptr<IContainer> ContainerFactory::createPlanesListContainer()
{
    return std::shared_ptr<IContainer>(new PlanesListContainer());
}

std::shared_ptr<IContainer> ContainerFactory::createPlaneContainer()
{
    return std::shared_ptr<IContainer>(new PlaneContainer());
}

std::shared_ptr<IContainer> ContainerFactory::createCylindersListContainer()
{
    return std::shared_ptr<IContainer>(new CylindersListContainer());
}

std::shared_ptr<IContainer> ContainerFactory::createCylinderContainer()
{
    return std::shared_ptr<IContainer>(new CylinderContainer());
}

std::shared_ptr<IContainer> ContainerFactory::createConesListContainer()
{
    return std::shared_ptr<IContainer>(new ConesListContainer());
}

std::shared_ptr<IContainer> ContainerFactory::createConeContainer()
{
    return std::shared_ptr<IContainer>(new ConeContainer());
}

std::shared_ptr<IContainer> ContainerFactory::createBoxsListContainer()
{
    return std::shared_ptr<IContainer>(new BoxsListContainer());
}

std::shared_ptr<IContainer> ContainerFactory::createBoxContainer()
{
    return std::shared_ptr<IContainer>(new BoxContainer());
}

std::shared_ptr<IContainer> ContainerFactory::createTetrahedronsListContainer()
{
    return std::shared_ptr<IContainer>(new TetrahedronsListContainer());
}

std::shared_ptr<IContainer> ContainerFactory::createTetrahedronContainer()
{
    return std::shared_ptr<IContainer>(new TetrahedronContainer());
}

std::shared_ptr<IContainer> ContainerFactory::createLightsContainer()
{
    return std::shared_ptr<IContainer>(new LightsContainer());
}

std::shared_ptr<IContainer> ContainerFactory::createAmbientLightContainer()
{
    return std::shared_ptr<IContainer>(new AmbientLightContainer());
}

std::shared_ptr<IContainer> ContainerFactory::createDirectionalsLightsListContainer()
{
    return std::shared_ptr<IContainer>(new DirectionalsLightsListContainer());
}

std::shared_ptr<IContainer> ContainerFactory::createDirectionalLightContainer()
{
    return std::shared_ptr<IContainer>(new DirectionalLightContainer());
}

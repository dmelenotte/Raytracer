#include "DirectionalLightContainer.hpp"

#include "types/AllTypes.hpp"

#include "../getters/Getters.hpp"

#include "../../errors/ContainerException.hpp"
#include "../../errors/GettersException.hpp"

DirectionalLightContainer::DirectionalLightContainer() :
    AContainer(std::shared_ptr<IType>(new ObjectType), {"vector"}),
    _intensity(0.0f), _shininess(0.0f),
    _getIntensity(false), _getShininess(false), _getDirection(false) {}

void DirectionalLightContainer::execContainer(__attribute__((unused)) const nlohmann::json &json)
{

}

void DirectionalLightContainer::execContainer(nlohmann::json::const_iterator &jsonIterator)
{
    if (!jsonIterator->is_object()) {
        throw ContainerException("-E- >> Invalid type for 'directional light'. Expected 'object'.");
    }
    if (jsonIterator->size() != 3) {
        throw ContainerException("-E- >> Key contains wrong number of elements. Expected 3.");
    }
    for (auto it = jsonIterator->begin(); it != jsonIterator->end(); ++it) {
        this->getIntensity(it);
        this->getShininess(it);
        this->getDirection(it);
    }
    if (!_getIntensity || !_getShininess || !_getDirection) {
        throw ContainerException("-E- >> Invalid arguments. Expected 'intensity' and 'shininess' and 'direction'.");
    }
    _getIntensity = false;
    _getShininess = false;
    _getDirection = false;
    std::shared_ptr<ObjectType> value(dynamic_cast<ObjectType *>(_value.get()), [](ObjectType *) {});
    ObjectsFactory tmpFactory;
    std::shared_ptr<IObject> obj = tmpFactory.createObject(ObjectsFactory::DIRECTIONAL_LIGHT,
        _intensity, _shininess, &_direction);
    value->_object = obj;
}

/* ---- Private ---- */

void DirectionalLightContainer::getIntensity(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "intensity") {
        if (_getIntensity) {
            throw ContainerException("-E- >> Redefinition of intensity.");
        }
        try {
            _intensity = Getter::getGenericFloat(jsonIterator, "intensity");
        } catch (GetterException &e) {
            throw ContainerException(e.what());
        }
        _getIntensity = true;
    }
}

void DirectionalLightContainer::getShininess(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "shininess") {
        if (_getShininess) {
            throw ContainerException("-E- >> Redefinition of shininess.");
        }
        try {
            _shininess = Getter::getGenericFloat(jsonIterator, "shininess");
        } catch (GetterException &e) {
            throw ContainerException(e.what());
        }
        _getShininess = true;
    }
}

void DirectionalLightContainer::getDirection(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "direction") {
        if (_getDirection) {
            throw ContainerException("-E- >> Redefinition of direction.");
        }
        if (!_subContainers.contains("vector")) {
            throw ContainerException("-E- >> Sub container needed not register.");
        }
        _subContainers.find("vector")->second->execContainer(jsonIterator);
        VectorType *ptr = dynamic_cast<VectorType *>(_subContainers.find("vector")->second->getValue().get());
        if (ptr == nullptr) {
            throw ContainerException("-E- >> Sub container return wrong type.");
        }
        _direction = ptr->operator Vector();
        _getDirection = true;
    }
}

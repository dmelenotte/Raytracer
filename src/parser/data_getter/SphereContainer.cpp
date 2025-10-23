#include "SphereContainer.hpp"

#include "types/AllTypes.hpp"

#include "../getters/Getters.hpp"

#include "../../errors/ContainerException.hpp"
#include "../../errors/GettersException.hpp"

SphereContainer::SphereContainer() :
    AContainer(std::shared_ptr<IType>(new ObjectType), {"position", "color", "vector"}),
    _getPosition(false), _getRadius(false), _getColor(false), _getAlbedo(false), _getReflection(false) {}

void SphereContainer::execContainer(__attribute__((unused)) const nlohmann::json &json)
{

}

void SphereContainer::execContainer(nlohmann::json::const_iterator &jsonIterator)
{
    if (!jsonIterator->is_object()) {
        throw ContainerException("-E- >> Invalid type for 'sphere'. Expected 'object'.");
    }
    if (jsonIterator->size() != 5) {
        throw ContainerException("-E- >> Key contains wrong number of elements. Expected 5.");
    }
    for (auto it = jsonIterator->begin(); it != jsonIterator->end(); ++it) {
        this->getPosition(it);
        this->getRadius(it);
        this->getColor(it);
        this->getAlbedo(it);
        this->getReflection(it);
    }
    if (!_getPosition || !_getRadius || !_getColor || !_getAlbedo || !_getReflection) {
        throw ContainerException("-E- >> Invalid arguments. Expected 'position' and 'radius' "
            "and 'color' and 'albedo' and 'reflexion'.");
    }
    _getPosition = false;
    _getRadius = false;
    _getColor = false;
    _getAlbedo = false;
    _getReflection = false;
    std::shared_ptr<ObjectType> value(dynamic_cast<ObjectType *>(_value.get()), [](ObjectType *) {});
    ObjectsFactory tmpFactory;
    std::shared_ptr<IObject> obj = tmpFactory.createObject(ObjectsFactory::SPHERE, &_position, _radius,
        &_color, &_albedo, &_reflection);
    value->_object = obj;
}

/* ---- Private ---- */

void SphereContainer::getPosition(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "position") {
        if (_getPosition) {
            throw ContainerException("-E- >> Redefinition of position.");
        }
        if (!_subContainers.contains("position")) {
            throw ContainerException("-E- >> Sub container needed not register.");
        }
        _subContainers.find("position")->second->execContainer(jsonIterator);
        PositionType *ptr = dynamic_cast<PositionType *>(_subContainers.find("position")->second->getValue().get());
        if (ptr == nullptr) {
            throw ContainerException("-E- >> Sub container return wrong type.");
        }
        _position = ptr->operator Position();
        _getPosition = true;
    }
}

void SphereContainer::getRadius(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "radius") {
        if (_getRadius) {
            throw ContainerException("-E- >> Redefinition of radius.");
        }
        try {
            _radius = Getter::getGenericFloat(jsonIterator, "radius");
        } catch (GetterException &e) {
            throw ContainerException(e.what());
        }
        _getRadius = true;
    }
}

void SphereContainer::getColor(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "color") {
        if (_getColor) {
            throw ContainerException("-E- >> Redefinition of color.");
        }
        if (!_subContainers.contains("color")) {
            throw ContainerException("-E- >> Sub container needed not register.");
        }
        _subContainers.find("color")->second->execContainer(jsonIterator);
        ColorType *ptr = dynamic_cast<ColorType *>(_subContainers.find("color")->second->getValue().get());
        if (ptr == nullptr) {
            throw ContainerException("-E- >> Sub container return wrong type.");
        }
        _color = ptr->operator Color();
        _getColor = true;
    }
}

void SphereContainer::getAlbedo(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "albedo") {
        if (_getAlbedo) {
            throw ContainerException("-E- >> Redefinition of albedo.");
        }
        if (!_subContainers.contains("vector")) {
            throw ContainerException("-E- >> Sub container needed not register.");
        }
        _subContainers.find("vector")->second->execContainer(jsonIterator);
        VectorType *ptr = dynamic_cast<VectorType *>(_subContainers.find("vector")->second->getValue().get());
        if (ptr == nullptr) {
            throw ContainerException("-E- >> Sub container return wrong type.");
        }
        _albedo = ptr->operator Color();
        _getAlbedo = true;
    }
}

void SphereContainer::getReflection(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "reflection") {
        if (_getReflection) {
            throw ContainerException("-E- >> Redefinition of reflection.");
        }
        if (!_subContainers.contains("vector")) {
            throw ContainerException("-E- >> Sub container needed not register.");
        }
        _subContainers.find("vector")->second->execContainer(jsonIterator);
        VectorType *ptr = dynamic_cast<VectorType *>(_subContainers.find("vector")->second->getValue().get());
        if (ptr == nullptr) {
            throw ContainerException("-E- >> Sub container return wrong type.");
        }
        _reflection = ptr->operator Color();
        _getReflection = true;
    }
}

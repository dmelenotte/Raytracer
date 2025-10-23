#include "CylinderContainer.hpp"

#include "types/AllTypes.hpp"

#include "../getters/Getters.hpp"

#include "../../errors/ContainerException.hpp"
#include "../../errors/GettersException.hpp"

CylinderContainer::CylinderContainer() :
    AContainer(std::shared_ptr<IType>(new ObjectType), {"position", "color", "vector"}),
    _getPosition(false), _getRadius(false), _getDirection(false),
    _getColor(false), _getAlbedo(false), _getReflection(false) {}

void CylinderContainer::execContainer(__attribute((unused)) const nlohmann::json &json)
{

}

void CylinderContainer::execContainer(nlohmann::json::const_iterator &jsonIterator)
{
    if (!jsonIterator->is_object()) {
        throw ContainerException("-E- >> Invalid type for 'cylinder'. Expected 'object'.");
    }
    if (jsonIterator->size() != 6) {
        throw ContainerException("-E- >> Key contains wrong number of elements. Expected 6.");
    }
    for (auto it = jsonIterator->begin(); it != jsonIterator->end(); ++it) {
        this->getPosition(it);
        this->getRadius(it);
        this->getDirection(it);
        this->getColor(it);
        this->getAlbedo(it);
        this->getReflection(it);
    }
    if (!_getPosition || !_getRadius || !_getDirection || !_getColor || !_getAlbedo || !_getReflection) {
        throw ContainerException("-E- >> Invalid arguments. Expected 'position' and 'radius' and 'direction'"
            "and 'color' and 'albedo' and 'reflexion'.");
    }
    _getPosition = false;
    _getRadius = false;
    _getDirection = false;
    _getColor = false;
    _getAlbedo = false;
    _getReflection = false;
    std::shared_ptr<ObjectType> value(dynamic_cast<ObjectType *>(_value.get()), [](ObjectType *) {});
    ObjectsFactory tmpFactory;
    std::shared_ptr<IObject> obj = tmpFactory.createObject(ObjectsFactory::CYLINDER, &_position, _radius,
        &_direction, &_color, &_albedo, &_reflection);
    value->_object = obj;
}

/* ---- Private ---- */

void CylinderContainer::getPosition(nlohmann::json::const_iterator &jsonIterator)
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

void CylinderContainer::getRadius(nlohmann::json::const_iterator &jsonIterator)
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

void CylinderContainer::getDirection(nlohmann::json::const_iterator &jsonIterator)
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

void CylinderContainer::getColor(nlohmann::json::const_iterator &jsonIterator)
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

void CylinderContainer::getAlbedo(nlohmann::json::const_iterator &jsonIterator)
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

void CylinderContainer::getReflection(nlohmann::json::const_iterator &jsonIterator)
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

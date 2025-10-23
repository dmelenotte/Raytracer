#include "PlaneContainer.hpp"

#include "types/AllTypes.hpp"

#include "../getters/Getters.hpp"

#include "../../errors/ContainerException.hpp"
#include "../../errors/GettersException.hpp"

PlaneContainer::PlaneContainer() :
    AContainer(std::shared_ptr<IType>(new ObjectType), {"color", "vector"}),
    _axis('\0'), _position(0),
    _getAxis(false), _getPosition(false), _getColor(false), _getAlbedo(false), _getReflection(false) {}

void PlaneContainer::execContainer(__attribute__((unused)) const nlohmann::json &json)
{

}

void PlaneContainer::execContainer(nlohmann::json::const_iterator &jsonIterator)
{
    if (!jsonIterator->is_object()) {
        throw ContainerException("-E- >> Invalid type for 'plane'. Expected 'object'.");
    }
    if (jsonIterator->size() != 5) {
        throw ContainerException("-E- >> Key contains wrong number of elements. Expected 5.");
    }
    for (auto it = jsonIterator->begin(); it != jsonIterator->end(); ++it) {
        this->getAxis(it);
        this->getPosition(it);
        this->getColor(it);
        this->getAlbedo(it);
        this->getReflection(it);
    }
    if (!_getAxis || !_getPosition || !_getColor || !_getAlbedo || !_getReflection) {
        throw ContainerException("-E- >> Invalid arguments. Expected 'axis' and 'position' "
            "and 'color' and 'albedo' and 'reflexion'.");
    }
    _getAxis = false;
    _getPosition = false;
    _getColor = false;
    _getAlbedo = false;
    _getReflection = false;
    std::shared_ptr<ObjectType> value(dynamic_cast<ObjectType *>(_value.get()), [](ObjectType *) {});
    ObjectsFactory tmpFactory;
    std::shared_ptr<IObject> obj = tmpFactory.createObject(ObjectsFactory::PLANE, _axis, _position,
        &_color, &_albedo, &_reflection);
    value->_object = obj;
}

/* ---- Private ---- */

void PlaneContainer::getAxis(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "axis") {
        if (_getAxis) {
            throw ContainerException("-E- >> Redefinition of axis.");
        }
        try {
            _axis = Getter::getGenericCharacter(jsonIterator, "axis");
        } catch (GetterException &e) {
            throw ContainerException(e.what());
        }
        _getAxis = true;
    }
}

void PlaneContainer::getPosition(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "position") {
        if (_getPosition) {
            throw ContainerException("-E- >> Redefinition of position.");
        }
        try {
            _position = Getter::getGenericInteger(jsonIterator, "position");
        } catch (GetterException &e) {
            throw ContainerException(e.what());
        }
        _getPosition = true;
    }
}

void PlaneContainer::getColor(nlohmann::json::const_iterator &jsonIterator)
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

void PlaneContainer::getAlbedo(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "albedo") {
        if (_getAlbedo) {
            throw ContainerException("-E- >> Redefinition of color.");
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

void PlaneContainer::getReflection(nlohmann::json::const_iterator &jsonIterator)
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

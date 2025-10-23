#include "BoxContainer.hpp"

#include "types/AllTypes.hpp"

#include "../getters/Getters.hpp"

#include "../../errors/ContainerException.hpp"
#include "../../errors/GettersException.hpp"

BoxContainer::BoxContainer() :
    AContainer(std::shared_ptr<IType>(new ObjectType), {"position", "color", "vector"}),
    _getPosition(false), _getWidth(false), _getHeight(false), _getDepth(false),
    _getDirection(false), _getColor(false), _getAlbedo(false), _getReflection(false) {}

void BoxContainer::execContainer(__attribute__((unused)) const nlohmann::json &json)
{

}

void BoxContainer::execContainer(nlohmann::json::const_iterator &jsonIterator)
{
    if (!jsonIterator->is_object()) {
        throw ContainerException("-E- >> Invalid type for 'box'. Expected 'object'.");
    }
    if (jsonIterator->size() != 8) {
        throw ContainerException("-E- >> Key contains wrong number of elements. Expected 8.");
    }
    for (auto it = jsonIterator->begin(); it != jsonIterator->end(); ++it) {
        this->getPosition(it);
        this->getWidth(it);
        this->getHeight(it);
        this->getDepth(it);
        this->getDirection(it);
        this->getColor(it);
        this->getAlbedo(it);
        this->getReflection(it);
    }
    if (!_getPosition || !_getWidth || !_getHeight || !_getDepth || !_getDirection ||
        !_getColor || !_getAlbedo || !_getReflection) {
        throw ContainerException("-E- >> Invalid arguments. Expected 'position' and 'width' "
            "and 'height' and 'height' and 'direction'"
            "and 'color' and 'albedo' and 'reflexion'.");
    }
    _getPosition = false;
    _getWidth = false;
    _getHeight = false;
    _getDepth = false;
    _getDirection = false;
    _getColor = false;
    _getAlbedo = false;
    _getReflection = false;
    std::shared_ptr<ObjectType> value(dynamic_cast<ObjectType *>(_value.get()), [](ObjectType *) {});
    ObjectsFactory tmpFactory;
    std::shared_ptr<IObject> obj = tmpFactory.createObject(ObjectsFactory::BOX,
        &_position, _width, _height, _depth, &_direction, &_color, &_albedo, &_reflection);
    value->_object = obj;
}

/* ---- Private ----*/

void BoxContainer::getPosition(nlohmann::json::const_iterator &jsonIterator)
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

void BoxContainer::getWidth(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "width") {
        if (_getWidth) {
            throw ContainerException("-E- >> Redefinition of width.");
        }
        try {
            _width = Getter::getGenericInteger(jsonIterator, "width");
        } catch (GetterException &e) {
            throw ContainerException(e.what());
        }
        _getWidth = true;
    }
}

void BoxContainer::getHeight(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "height") {
        if (_getWidth) {
            throw ContainerException("-E- >> Redefinition of height.");
        }
        try {
            _height = Getter::getGenericInteger(jsonIterator, "height");
        } catch (GetterException &e) {
            throw ContainerException(e.what());
        }
        _getHeight = true;}
}

void BoxContainer::getDepth(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "depth") {
        if (_getWidth) {
            throw ContainerException("-E- >> Redefinition of depth.");
        }
        try {
            _depth = Getter::getGenericInteger(jsonIterator, "depth");
        } catch (GetterException &e) {
            throw ContainerException(e.what());
        }
        _getDepth = true;
    }
}

void BoxContainer::getDirection(nlohmann::json::const_iterator &jsonIterator)
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

void BoxContainer::getColor(nlohmann::json::const_iterator &jsonIterator)
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

void BoxContainer::getAlbedo(nlohmann::json::const_iterator &jsonIterator)
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

void BoxContainer::getReflection(nlohmann::json::const_iterator &jsonIterator)
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

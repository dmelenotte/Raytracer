#include "TetrahedronsContainer.hpp"

#include "types/AllTypes.hpp"

#include "../getters/Getters.hpp"

#include "../../errors/ContainerException.hpp"

TetrahedronContainer::TetrahedronContainer() :
    AContainer(std::shared_ptr<IType>(new ObjectType), {"position", "color", "vector"}),
    _getPoint1(false), _getPoint2(false), _getPoint3(false), _getPoint4(false), _getDirection(false),
    _getColor(false), _getAlbedo(false), _getReflection(false) {}

void TetrahedronContainer::execContainer(__attribute__((unused)) const nlohmann::json &json)
{

}

void TetrahedronContainer::execContainer(nlohmann::json::const_iterator &jsonIterator)
{
    if (!jsonIterator->is_object()) {
        throw ContainerException("-E- >> Invalid type for 'cone'. Expected 'object'.");
    }
    if (jsonIterator->size() != 8) {
        throw ContainerException("-E- >> Key contains wrong number of elements. Expected 8.");
    }
    for (auto it = jsonIterator->begin(); it != jsonIterator->end(); ++it) {
        this->getPoint1(it);
        this->getPoint2(it);
        this->getPoint3(it);
        this->getPoint4(it);
        this->getDirection(it);
        this->getColor(it);
        this->getAlbedo(it);
        this->getReflection(it);
    }
    if (!_getPoint1 || !_getPoint2 || !_getPoint3 || !_getPoint4 || !_getDirection || !_getColor || !_getAlbedo || !_getReflection) {
        throw ContainerException("-E- >> Invalid arguments. Expected 'point1' and 'point2' "
             "'point3' and 'point4' and 'direction'"
             "and 'color' and 'albedo' and 'reflexion'.");
    }
    _getPoint1 = false;
    _getPoint2 = false;
    _getPoint3 = false;
    _getPoint4 = false;
    _getDirection = false;
    _getColor = false;
    _getAlbedo = false;
    _getReflection = false;
    std::shared_ptr<ObjectType> value(dynamic_cast<ObjectType *>(_value.get()), [](ObjectType *) {});
    ObjectsFactory tmpFactory;
    std::shared_ptr<IObject> obj = tmpFactory.createObject(ObjectsFactory::TETRAHEDRON, &_point1, &_point2, &_point3,
        &_point4, &_direction, &_color, &_albedo, &_reflection);
    value->_object = obj;
}

/* ---- Private ---- */

void TetrahedronContainer::getPoint1(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "point1") {
        if (_getPoint1) {
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
        _point1 = ptr->operator Position();
        _getPoint1 = true;
    }
}

void TetrahedronContainer::getPoint2(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "point2") {
        if (_getPoint2) {
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
        _point2 = ptr->operator Position();
        _getPoint2 = true;
    }
}

void TetrahedronContainer::getPoint3(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "point3") {
        if (_getPoint3) {
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
        _point3 = ptr->operator Position();
        _getPoint3 = true;
    }
}

void TetrahedronContainer::getPoint4(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "point4") {
        if (_getPoint4) {
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
        _point4 = ptr->operator Position();
        _getPoint4 = true;
    }
}

void TetrahedronContainer::getDirection(nlohmann::json::const_iterator &jsonIterator)
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

void TetrahedronContainer::getColor(nlohmann::json::const_iterator &jsonIterator)
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

void TetrahedronContainer::getAlbedo(nlohmann::json::const_iterator &jsonIterator)
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

void TetrahedronContainer::getReflection(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "reflection") {
        if (_getReflection) {
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
        _reflection = ptr->operator Color();
        _getReflection = true;
    }
}

#include "CameraContainer.hpp"

#include "types/AllTypes.hpp"

#include "../getters/Getters.hpp"

#include "../../errors/ContainerException.hpp"
#include "../../errors/GettersException.hpp"

CameraContainer::CameraContainer() :
    AContainer(std::shared_ptr<IType>(new ObjectType()), {"resolution", "position", "rotation"}),
    _getResolution(false), _getPosition(false), _getRotation(false), _getFov(false), _getDepth(false) {}

void CameraContainer::execContainer(__attribute__((unused)) const nlohmann::json &json)
{

}

void CameraContainer::execContainer(nlohmann::json::const_iterator &jsonIterator)
{
    if (!jsonIterator->is_object()) {
        throw ContainerException("-E- >> Key 'camera' is not object.");
    }
    if (jsonIterator->size() != 5) {
        throw ContainerException("-E- >> Key contains wrong number of elements. Expected 5.");
    }
    for (auto it = jsonIterator->begin(); it != jsonIterator->end(); ++it) {
        this->getResolution(it);
        this->getPosition(it);
        this->getRotation(it);
        this->getFov(it);
        this->getDepth(it);
    }
    if (!_getResolution || !_getPosition || !_getRotation || !_getFov || !_getDepth) {
        throw ContainerException("-E- >> Invalid arguments. Expected 'resolution' and 'position'"
            "and 'rotation' and 'fov' and 'depth'.");
    }
    std::shared_ptr<ObjectType> value(dynamic_cast<ObjectType *>(_value.get()), [](ObjectType *) {});
    ObjectsFactory tmpFactory;
    std::shared_ptr<IObject> obj = tmpFactory.createObject(ObjectsFactory::CAMERA,
        _width, _height, &_position, &_rotation, _fov, _depth);
    value->_object = obj;
}

/* ---- Private ---- */

void CameraContainer::getResolution(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "resolution") {
        if (_getResolution) {
            throw ContainerException("-E- >> Redefinition of resolution.");
        }
        if (!_subContainers.contains("resolution")) {
            throw ContainerException("-E- >> Sub container needed not register.");
        }
        _subContainers.find("resolution")->second->execContainer(jsonIterator);
        ResolutionType *ptr = dynamic_cast<ResolutionType *>(_subContainers.find("resolution")->second->getValue().get());
        if (ptr == nullptr) {
            throw ContainerException("-E- >> Sub container return wrong type.");
        }
        _width = ptr->_width;
        _height = ptr->_height;
        _getResolution = true;
    }
}

void CameraContainer::getPosition(nlohmann::json::const_iterator &jsonIterator)
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

void CameraContainer::getRotation(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "rotation") {
        if (_getRotation) {
            throw ContainerException("-E- >> Redefinition of rotation.");
        }
        if (!_subContainers.contains("rotation")) {
            throw ContainerException("-E- >> Sub container needed not register.");
        }
        _subContainers.find("rotation")->second->execContainer(jsonIterator);
        RotationType *ptr = dynamic_cast<RotationType *>(_subContainers.find("rotation")->second->getValue().get());
        if (ptr == nullptr) {
            throw ContainerException("-E- >> Sub container return wrong type.");
        }
        _rotation = ptr->operator Rotation();
        _getRotation = true;
    }
}

void CameraContainer::getFov(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "fieldOfView") {
        if (_getFov) {
            throw ContainerException("-E- >> Redefinition of fieldOfView.");
        }
        try {
            _fov = Getter::getGenericFloat(jsonIterator, "fieldOfView");
        } catch (GetterException &e) {
            throw ContainerException(e.what());
        }
        _getFov = true;
    }
}

void CameraContainer::getDepth(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "depth") {
        if (_getDepth) {
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

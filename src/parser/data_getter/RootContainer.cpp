#include "RootContainer.hpp"

#include "types/AllTypes.hpp"

#include "../getters/Getters.hpp"

#include "../../errors/ContainerException.hpp"

RootContainer::RootContainer(ObjectsFactory &factory) :
    AContainer(std::shared_ptr<IType>(new FactoryType(factory)), {"camera", "primitives", "lights"}),
    _getCamera(false), _getPrimitives(false), _getLights(false) {}

void RootContainer::execContainer(const nlohmann::json &json)
{
    std::shared_ptr<FactoryType> value(dynamic_cast<FactoryType *>(_value.get()), [](FactoryType *){});

    if (!json.is_object()) {
        throw ContainerException("-E- >> Json data's is not object.");
    }
    if (json.size() != 3) {
        throw ContainerException("-E- >> Key contains wrong number of elements. Expected 2.");
    }
    for (auto it = json.begin(); it != json.end(); ++it) {
        if (it.key() == "camera") {
            if (_getCamera) {
                throw ContainerException("-E- >> Redefinition of camera.");
            }
            if (!_subContainers.contains("camera")) {
                throw ContainerException("-E- >> Sub container needed not register.");
            }
            _subContainers.find("camera")->second->execContainer(it);
            ObjectType *obj = dynamic_cast<ObjectType *>(_subContainers.find("camera")->second->getValue().get());
            if (obj == nullptr) {
                throw ContainerException("-E- >> Sub container return wrong type.");
            }
            value->_factory.addObject(obj->_object);
            _getCamera = true;
        }
        if (it.key() == "primitives") {
            if (_getPrimitives) {
                throw ContainerException("-E- >> Redefinition of primitives.");
            }
            if (!_subContainers.contains("primitives")) {
                throw ContainerException("-E- >> Sub container needed not register.");
            }
            _subContainers.find("primitives")->second->execContainer(it);
            ObjectListType *list = dynamic_cast<ObjectListType *>(_subContainers.find("primitives")->second->getValue().get());
            if (list == nullptr) {
                throw ContainerException("-E- >> Sub container return wrong type.");
            }
            for (auto itO = list->_listObject.begin(); itO != list->_listObject.end(); ++itO) {
                value->_factory.addObject((*itO));
            }
            _getPrimitives = true;
        }
        if (it.key() == "lights") {
            if (_getLights) {
                throw ContainerException("-E- >> Redefinition of lights.");
            }
            if (!_subContainers.contains("lights")) {
                throw ContainerException("-E- >> Sub container needed not register.");
            }
            _subContainers.find("lights")->second->execContainer(it);
            ObjectListType *list = dynamic_cast<ObjectListType *>(_subContainers.find("lights")->second->getValue().get());
            if (list == nullptr) {
                throw ContainerException("-E- >> Sub container return wrong type.");
            }
            for (auto itO = list->_listObject.begin(); itO != list->_listObject.end(); ++itO) {
                value->_factory.addObject((*itO));
            }
            _getLights = true;
        }
    }
}

void RootContainer::execContainer(__attribute__((unused)) nlohmann::json::const_iterator &jsonIterator)
{

}

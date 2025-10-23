#include "LightsContainer.hpp"

#include "types/AllTypes.hpp"

#include "../../errors/ContainerException.hpp"

LightsContainer::LightsContainer() :
    AContainer(std::shared_ptr<IType>(new ObjectListType), {"ambient", "directionals"}),
    _getAmbient(false), _getDirectionals(false) {}

void LightsContainer::execContainer(__attribute__((unused)) const nlohmann::json &json)
{

}

void LightsContainer::execContainer(nlohmann::json::const_iterator &jsonIterator)
{
    std::shared_ptr<ObjectListType> value(dynamic_cast<ObjectListType *>(_value.get()), [](ObjectListType *) {});

    if (!jsonIterator->is_object()) {
        throw ContainerException("-E- >> Key 'lights' is not object.");
    }
    for (auto it = jsonIterator->begin(); it != jsonIterator->end(); ++it) {
        if (it.key() == "ambient") {
            if (_getAmbient) {
                throw ContainerException("-E- >> Redefinition of ambient.");
            }
            if (!_subContainers.contains("ambient")) {
                throw ContainerException("-E- >> Sub container needed not register.");
            }
            _subContainers.find("ambient")->second->execContainer(it);
            ObjectType *obj = dynamic_cast<ObjectType *>(_subContainers.find("ambient")->second->getValue().get());
            if (obj == nullptr) {
                throw ContainerException("-E- >> Sub container return wrong type.");
            }
            value->_listObject.push_back(obj->_object);
            _getAmbient = true;
            continue;
        }
        if (it.key() == "directionals") {
            if (_getDirectionals) {
                throw ContainerException("-E- >> Redefinition of directionals.");
            }
            if (!_subContainers.contains("directionals")) {
                throw ContainerException("-E- >> Sub container needed not register.");
            }
            _subContainers.find("directionals")->second->execContainer(it);
            ObjectListType *list = dynamic_cast<ObjectListType *>(_subContainers.find("directionals")->second->getValue().get());
            if (list == nullptr) {
                throw ContainerException("-E- >> Sub container return wrong type.");
            }
            for (auto itO = list->_listObject.begin(); itO != list->_listObject.end(); ++itO) {
                value->_listObject.push_back((*itO));
            }
            _getDirectionals = true;
            continue;
        }
    }
    if (!_getAmbient) {
        throw ContainerException("-E- >> Invalid arguments. Expected 'ambient light'.");
    }
    _getAmbient = false;
    _getDirectionals = false;
}

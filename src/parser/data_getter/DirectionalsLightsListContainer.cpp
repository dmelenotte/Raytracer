#include "DirectionalsLightsListContainer.hpp"

#include "types/AllTypes.hpp"

#include "../../errors/ContainerException.hpp"

DirectionalsLightsListContainer::DirectionalsLightsListContainer() :
    AContainer(std::shared_ptr<IType>(new ObjectListType),
    {"directional"}) {}

void DirectionalsLightsListContainer::execContainer(__attribute__((unused)) const nlohmann::json &json)
{

}

void DirectionalsLightsListContainer::execContainer(nlohmann::json::const_iterator &jsonIterator)
{
    std::shared_ptr<ObjectListType> value(dynamic_cast<ObjectListType *>(_value.get()), [](ObjectListType *) {});

    if (!jsonIterator->is_array()) {
        throw ContainerException("-E- >> Key 'directionals lights' is not array.");
    }
    if (!_subContainers.contains("directional")) {
        throw ContainerException("-E- >> Sub container needed not register.");
    }
    for (auto it = jsonIterator->begin(); it != jsonIterator->end(); ++it) {
        _subContainers.find("directional")->second->execContainer(it);
        ObjectType *obj = dynamic_cast<ObjectType *>(_subContainers.find("directional")->second->getValue().get());
        if (obj == nullptr) {
            throw ContainerException("-E- >> Sub container return wrong type.");
        }
        value->_listObject.push_back(obj->_object);
    }
}

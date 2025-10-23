#include "PlanesListContainer.hpp"

#include "types/AllTypes.hpp"

#include "../../errors/ContainerException.hpp"

PlanesListContainer::PlanesListContainer() :
    AContainer(std::shared_ptr<IType>(new ObjectListType),
    {"plane"}) {}

void PlanesListContainer::execContainer(__attribute((unused)) const nlohmann::json &json)
{

}

void PlanesListContainer::execContainer(nlohmann::json::const_iterator &jsonIterator)
{
    std::shared_ptr<ObjectListType> value(dynamic_cast<ObjectListType *>(_value.get()), [](ObjectListType *) {});

    if (!jsonIterator->is_array()) {
        throw ContainerException("-E- >> Key 'planes' is not array.");
    }
    if (!_subContainers.contains("plane")) {
        throw ContainerException("-E- >> Sub container needed not register.");
    }
    for (auto it = jsonIterator->begin(); it != jsonIterator->end(); ++it) {
        _subContainers.find("plane")->second->execContainer(it);
        ObjectType *obj = dynamic_cast<ObjectType *>(_subContainers.find("plane")->second->getValue().get());
        if (obj == nullptr) {
            throw ContainerException("-E- >> Sub container return wrong type.");
        }
        value->_listObject.push_back(obj->_object);
    }
}

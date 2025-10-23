#include "ConesListContainer.hpp"

#include "types/AllTypes.hpp"

#include "../../errors/ContainerException.hpp"

ConesListContainer::ConesListContainer() :
    AContainer(std::shared_ptr<IType>(new ObjectListType),
    {"cone"}) {}

void ConesListContainer::execContainer(__attribute__((unused)) const nlohmann::json &json)
{

}

void ConesListContainer::execContainer(nlohmann::json::const_iterator &jsonIterator)
{
    std::shared_ptr<ObjectListType> value(dynamic_cast<ObjectListType *>(_value.get()), [](ObjectListType *) {});

    if (!jsonIterator->is_array()) {
        throw ContainerException("-E- >> Key 'cones' is not array.");
    }
    if (!_subContainers.contains("cone")) {
        throw ContainerException("-E- >> Sub container needed not register.");
    }
    for (auto it = jsonIterator->begin(); it != jsonIterator->end(); ++it) {
        _subContainers.find("cone")->second->execContainer(it);
        ObjectType *obj = dynamic_cast<ObjectType *>(_subContainers.find("cone")->second->getValue().get());
        if (obj == nullptr) {
            throw ContainerException("-E- >> Sub container return wrong type.");
        }
        value->_listObject.push_back(obj->_object);
    }
}

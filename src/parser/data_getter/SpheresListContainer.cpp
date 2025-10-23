#include "SpheresListContainer.hpp"

#include "types/AllTypes.hpp"

#include "../../errors/ContainerException.hpp"

SphereListContainer::SphereListContainer() :
    AContainer(std::shared_ptr<IType>(new ObjectListType),
    {"sphere"}) {}

void SphereListContainer::execContainer(__attribute__((unused)) const nlohmann::json &json)
{

}

void SphereListContainer::execContainer(nlohmann::json::const_iterator &jsonIterator)
{
    std::shared_ptr<ObjectListType> value(dynamic_cast<ObjectListType *>(_value.get()), [](ObjectListType *) {});

    if (!jsonIterator->is_array()) {
        throw ContainerException("-E- >> Key 'spheres' is not array.");
    }
    if (!_subContainers.contains("sphere")) {
        throw ContainerException("-E- >> Sub container needed not register.");
    }
    for (auto it = jsonIterator->begin(); it != jsonIterator->end(); ++it) {
        _subContainers.find("sphere")->second->execContainer(it);
        ObjectType *obj = dynamic_cast<ObjectType *>(_subContainers.find("sphere")->second->getValue().get());
        if (obj == nullptr) {
            throw ContainerException("-E- >> Sub container return wrong type.");
        }
        value->_listObject.push_back(obj->_object);
    }
}

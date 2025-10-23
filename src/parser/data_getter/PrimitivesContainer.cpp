#include "PrimitivesContainer.hpp"

#include "types/AllTypes.hpp"

#include "../../errors/ContainerException.hpp"

PrimitivesContainer::PrimitivesContainer() :
    AContainer(std::shared_ptr<IType>(new ObjectListType),
    {"spheres", "planes", "cylinders", "cones", "boxs", "tetrahedrons"}),
    _gets({{false, "spheres"}, {false, "planes"},
    {false, "cylinders"}, {false, "cones"}, {false, "boxs"}, {false, "tetrahedrons"}}) {}

void PrimitivesContainer::execContainer(__attribute__((unused)) const nlohmann::json &json)
{

}

void PrimitivesContainer::execContainer(nlohmann::json::const_iterator &jsonIterator)
{
    std::shared_ptr<ObjectListType> value(dynamic_cast<ObjectListType *>(_value.get()), [](ObjectListType *) {});

    if (!jsonIterator->is_object()) {
        throw ContainerException("-E- >> Key 'primitives' is not object.");
    }
    for (auto it = jsonIterator->begin(); it != jsonIterator->end(); ++it) {
        for (auto itG = _gets.begin(); itG != _gets.end(); ++itG) {
            if ((*itG).second == it.key()) {
                if ((*itG).first) {
                    throw ContainerException("-E- >> Redefinition of " + (*itG).second + ".");
                }
                if (!_subContainers.contains((*itG).second)) {
                    throw ContainerException("-E- >> Sub container needed not register.");
                }
                _subContainers.find((*itG).second)->second->execContainer(it);
                ObjectListType *list = dynamic_cast<ObjectListType *>(_subContainers.find((*itG).second)->second->getValue().get());
                if (list == nullptr) {
                    throw ContainerException("-E- >> Sub container return wrong type.");
                }
                for (auto itO = list->_listObject.begin(); itO != list->_listObject.end(); ++itO) {
                    value->_listObject.push_back((*itO));
                }
                (*itG).first = true;
            }
        }
    }
    for (auto it = _gets.begin(); it != _gets.end(); ++it) {
        (*it).first = false;
    }
}

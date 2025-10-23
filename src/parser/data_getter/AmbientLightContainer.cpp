#include "AmbientLightContainer.hpp"

#include "types/AllTypes.hpp"

#include "../getters/Getters.hpp"

#include "../../errors/ContainerException.hpp"
#include "../../errors/GettersException.hpp"

AmbientLightContainer::AmbientLightContainer() :
        AContainer(std::shared_ptr<IType>(new ObjectType), {}),
        _intensity(0.0f),
        _getIntensity(false) {}

void AmbientLightContainer::execContainer(__attribute__((unused)) const nlohmann::json &json)
{

}

void AmbientLightContainer::execContainer(nlohmann::json::const_iterator &jsonIterator)
{
    float intensity = 0.0f;

    if (!jsonIterator->is_object()) {
        throw ContainerException("-E- >> Invalid type for 'ambient light'. Expected 'object'.");
    }
    if (jsonIterator->size() != 1) {
        throw ContainerException("-E- >> Key contains wrong number of elements. Expected 1.");
    }
    for (auto it = jsonIterator->begin(); it != jsonIterator->end(); ++it) {
        this->getIntensity(it);
    }
    if (!_getIntensity) {
        throw ContainerException("-E- >> Invalid arguments. Expected 'intensity'.");
    }
    _getIntensity = false;std::shared_ptr<ObjectType> value(dynamic_cast<ObjectType *>(_value.get()), [](ObjectType *) {});
    ObjectsFactory tmpFactory;
    std::shared_ptr<IObject> obj = tmpFactory.createObject(ObjectsFactory::AMBIENT_LIGHT, intensity);
    value->_object = obj;
}

/* ---- Private ---- */

void AmbientLightContainer::getIntensity(nlohmann::json::const_iterator &jsonIterator)
{
    if (jsonIterator.key() == "intensity") {
        if (_getIntensity) {
            throw ContainerException("-E- >> Redefinition of width.");
        }
        try {
            _intensity = Getter::getGenericFloat(jsonIterator, "intensity");
        } catch (GetterException &e) {
            throw ContainerException(e.what());
        }
        _getIntensity = true;
    }
}

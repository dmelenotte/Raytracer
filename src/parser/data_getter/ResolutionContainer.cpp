#include "ResolutionContainer.hpp"

#include "types/AllTypes.hpp"

#include "../getters/Getters.hpp"

#include "../../errors/ContainerException.hpp"
#include "../../errors/GettersException.hpp"

ResolutionContainer::ResolutionContainer() :
    AContainer(std::shared_ptr<IType>(new ResolutionType(0, 0)), {}),
    _getWidth(false), _getHeight(false) {}

void ResolutionContainer::execContainer(__attribute__((unused)) const nlohmann::json &json)
{

}

void ResolutionContainer::execContainer(nlohmann::json::const_iterator &jsonIterator)
{
    std::shared_ptr<ResolutionType> value(dynamic_cast<ResolutionType *>(_value.get()), [](ResolutionType *){});

    if (!jsonIterator->is_object()) {
        throw ContainerException("-E- >> Key 'resolution' is not object.");
    }
    if (jsonIterator->size() != 2) {
        throw ContainerException("-E- >> Key contains wrong number of elements. Expected 2.");
    }
    for (auto it = jsonIterator->begin(); it != jsonIterator->end(); ++it) {
        if (it.key() == "width") {
            if (_getWidth) {
                throw ContainerException("-E- >> Redefinition of width.");
            }
            try {
                value->_width = Getter::getGenericInteger(it, "width");
            } catch (GetterException &e) {
                throw ContainerException(e.what());
            }
            _getWidth = true;
            continue;
        }
        if (it.key() == "height") {
            if (_getWidth) {
                throw ContainerException("-E- >> Redefinition of height.");
            }
            try {
                value->_height = Getter::getGenericInteger(it, "height");
            } catch (GetterException &e) {
                throw ContainerException(e.what());
            }
            _getHeight = true;
            continue;
        }
    }
    if (!_getWidth || !_getHeight) {
        throw ContainerException("-E- >> Invalid arguments. Expected 'width' and 'height'.");
    }
    _getWidth = false;
    _getHeight = false;
}

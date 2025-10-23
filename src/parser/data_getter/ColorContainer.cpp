#include "ColorContainer.hpp"

#include "types/AllTypes.hpp"

#include "../getters/Getters.hpp"

#include "../../errors/ContainerException.hpp"
#include "../../errors/GettersException.hpp"

ColorContainer::ColorContainer() :
    AContainer(std::shared_ptr<IType>(new ColorType(0, 0, 0)), {}),
    _getR(false), _getG(false), _getB(false) {}

void ColorContainer::execContainer(__attribute__((unused)) const nlohmann::json &json)
{

}

void ColorContainer::execContainer(nlohmann::json::const_iterator &jsonIterator)
{
    std::shared_ptr<ColorType> value(dynamic_cast<ColorType *>(_value.get()), [](ColorType *){});

    if (!jsonIterator->is_object()) {
        throw ContainerException("-E- >> Key 'color' is not object.");
    }
    if (jsonIterator->size() != 3) {
        throw ContainerException("-E- >> Key contains wrong number of elements. Expected 3.");
    }
    for (auto it = jsonIterator->begin(); it != jsonIterator->end(); ++it) {
        if (it.key() == "r") {
            if (_getR) {
                throw ContainerException("-E- >> Redefinition of r.");
            }
            try {
                value->_r = Getter::getGenericUnsignedInteger(it, "r");
            } catch (GetterException &e) {
                throw ContainerException(e.what());
            }
            _getR = true;
            continue;
        }
        if (it.key() == "g") {
            if (_getG) {
                throw ContainerException("-E- >> Redefinition of g.");
            }
            try {
                value->_g = Getter::getGenericUnsignedInteger(it, "g");
            } catch (GetterException &e) {
                throw ContainerException(e.what());
            }
            _getG = true;
            continue;
        }
        if (it.key() == "b") {
            if (_getB) {
                throw ContainerException("-E- >> Redefinition of b.");
            }
            try {
                value->_b = Getter::getGenericUnsignedInteger(it, "b");
            } catch (GetterException &e) {
                throw ContainerException(e.what());
            }
            _getB = true;
            continue;
        }
    }
    if (!_getR || !_getG || !_getB) {
        throw ContainerException("-E- >> Invalid arguments. Expected 'r' and 'g' and 'b'.");
    }
    _getR = false;
    _getG = false;
    _getB = false;
}

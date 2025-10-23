#include "PositionContainer.hpp"

#include "types/AllTypes.hpp"

#include "../getters/Getters.hpp"

#include "../../errors/ContainerException.hpp"
#include "../../errors/GettersException.hpp"

PositionContainer::PositionContainer() :
    AContainer(std::shared_ptr<IType>(new PositionType(0, 0, 0)), {}),
    _getX(false), _getY(false), _getZ(false) {}

void PositionContainer::execContainer(__attribute__((unused)) const nlohmann::json &json)
{

}

void PositionContainer::execContainer(nlohmann::json::const_iterator &jsonIterator)
{
    std::shared_ptr<PositionType> value(dynamic_cast<PositionType *>(_value.get()), [](PositionType *){});

    if (!jsonIterator->is_object()) {
        throw ContainerException("-E- >> Key 'position' is not object.");
    }
    if (jsonIterator->size() != 3) {
        throw ContainerException("-E- >> Key contains wrong number of elements. Expected 3.");
    }
    for (auto it = jsonIterator->begin(); it != jsonIterator->end(); ++it) {
        if (it.key() == "x") {
            if (_getX) {
                throw ContainerException("-E- >> Redefinition of x.");
            }
            try {
                value->_x = Getter::getGenericInteger(it, "x");
            } catch (GetterException &e) {
                throw ContainerException(e.what());
            }
            _getX = true;
            continue;
        }
        if (it.key() == "y") {
            if (_getY) {
                throw ContainerException("-E- >> Redefinition of y.");
            }
            try {
                value->_y = Getter::getGenericInteger(it, "y");
            } catch (GetterException &e) {
                throw ContainerException(e.what());
            }
            _getY = true;
            continue;
        }
        if (it.key() == "z") {
            if (_getZ) {
                throw ContainerException("-E- >> Redefinition of z.");
            }
            try {
                value->_z = Getter::getGenericInteger(it, "z");
            } catch (GetterException &e) {
                throw ContainerException(e.what());
            }
            _getZ = true;
            continue;
        }
    }
    if (!_getX || !_getY || !_getZ) {
        throw ContainerException("-E- >> Invalid arguments. Expected 'x' and 'y' and 'z'.");
    }
    _getX = false;
    _getY = false;
    _getZ = false;
}

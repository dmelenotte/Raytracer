#include "Getters.hpp"

#include "../../errors/GettersException.hpp"

std::string Getter::getGenericString(nlohmann::json::const_iterator &jsonIterator, const std::string &objName)
{
    if (jsonIterator.key() == objName) {
        if (!jsonIterator->is_string()) {
            throw GetterException("-E- >> Invalid type for '" +
                jsonIterator.key() + "'. Expected 'string'.", GetterException::ERROR);
        }
        std::string str = jsonIterator->get<std::string>();
        return str;
    }
    throw GetterException("-W- >> '" +
        jsonIterator.key() + "' doesn't match with expected key.", GetterException::WARNING);
}

char Getter::getGenericCharacter(nlohmann::json::const_iterator &jsonIterator, const std::string &objName)
{
    if (jsonIterator.key() == objName) {
        if (!jsonIterator->is_string()) {
            throw GetterException("-E- >> Invalid type for '" +
                jsonIterator.key() + "'. Expected 'string'.", GetterException::ERROR);
        }
        std::string c = jsonIterator->get<std::string>();
        if (c.length() != 1) {
            throw GetterException("-E- >> Invalid type for '" +
                jsonIterator.key() + "'. Expected 'char'.", GetterException::ERROR);
        }
        return c.front();
    }
    throw GetterException("-W- >> '" +
        jsonIterator.key() + "' doesn't match with expected key.", GetterException::WARNING);
}

int Getter::getGenericInteger(nlohmann::json::const_iterator &jsonIterator, const std::string &objName)
{
    if (jsonIterator.key() == objName) {
        if (!jsonIterator->is_number_integer()) {
            throw GetterException("-E- >> Invalid type for '" +
                jsonIterator.key() + "'. Expected 'int'.", GetterException::ERROR);
        }
        return jsonIterator->get<int>();
    }
    throw GetterException("-W- >> '" +
        jsonIterator.key() + "' doesn't match with expected key.", GetterException::WARNING);
}

unsigned int Getter::getGenericUnsignedInteger(nlohmann::json::const_iterator &jsonIterator,
    const std::string &objName)
{
    if (jsonIterator.key() == objName) {
        if (!jsonIterator->is_number_unsigned()) {
            throw GetterException("-E- >> Invalid type for '" +
                jsonIterator.key() + "'. Expected 'unsigned int'.", GetterException::ERROR);
        }
        return jsonIterator->get<unsigned int>();
    }
    throw GetterException("-W- >> '" +
        jsonIterator.key() + "' doesn't match with expected key.", GetterException::WARNING);
}

float Getter::getGenericFloat(nlohmann::json::const_iterator &jsonIterator, const std::string &objName)
{
    if (jsonIterator.key() == objName) {
        if (!jsonIterator->is_number_float()) {
            throw GetterException("-E- >> Invalid type for '" +
                jsonIterator.key() + "'. Expected 'float'.", GetterException::ERROR);
        }
        return jsonIterator->get<float>();
    }
    throw GetterException("-W- >> '" +
        jsonIterator.key() + "' doesn't match with expected key." , GetterException::WARNING);
}

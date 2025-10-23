#ifndef __GETTERS__
    #define __GETTERS__

#include "../../elementary_data/Position.hpp"
#include "../../elementary_data/Rotation.hpp"
#include "../../elementary_data/Color.hpp"

#include <vector>

#include <nlohmann/json.hpp>

class Getter {
    public:
        static std::string getGenericString(nlohmann::json::const_iterator &jsonIterator,
            const std::string &objName);
        static char getGenericCharacter(nlohmann::json::const_iterator &jsonIterator,
            const std::string &objName);
        static int getGenericInteger(nlohmann::json::const_iterator &jsonIterator,
            const std::string &objName);
        static unsigned int getGenericUnsignedInteger(nlohmann::json::const_iterator &jsonIterator,
            const std::string &objName);
        static float getGenericFloat(nlohmann::json::const_iterator &jsonIterator,
            const std::string &objName);
};

#endif

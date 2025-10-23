#ifndef __JSON_PARSER__
#define __JSON_PARSER__

#include <string>

#include <nlohmann/json.hpp>

class JsonParser
{
public:
    JsonParser() = default;
    JsonParser(const std::string &jsonContent);
    JsonParser(const nlohmann::json &json);
    ~JsonParser() = default;
    void parse(const std::string &jsonContent);
    const nlohmann::json &getJson() const;

private:
    nlohmann::json _json;
};

#endif

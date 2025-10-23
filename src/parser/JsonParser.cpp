#include "JsonParser.hpp"

#include "../errors/JsonParserException.hpp"

#include <iostream>

JsonParser::JsonParser(const std::string &jsonContent)
{
    if (jsonContent.empty()) {
        return;
    }
    try {
        _json = nlohmann::json::parse(jsonContent);
    } catch (nlohmann::detail::parse_error &e) {
        throw JsonParserException("-E- >> Parse error :'" + std::string(e.what()) + "'.");
    }
    if (_json.empty()) {
        throw JsonParserException("-W- >> Json empty.");
    }
}

JsonParser::JsonParser(const nlohmann::json &json) : _json(json) {}

void JsonParser::parse(const std::string &jsonContent)
{
    if (jsonContent.empty()) {
        return;
    }
    try {
        _json = nlohmann::json::parse(jsonContent);
    } catch (nlohmann::detail::parse_error &e) {
        throw JsonParserException("-E- >> Parse error :'" + std::string(e.what()) + "'.");
    }
    if (_json.empty()) {
        throw JsonParserException("-W- >> Json empty.");
    }
}

const nlohmann::json &JsonParser::getJson() const
{
    if (_json.empty()) {
        throw JsonParserException("-W- >> Json empty.");
    }
    return _json;
}

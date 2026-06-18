#pragma once

#include "../lib/json.hpp"
#include <string>
#include <map>

typedef std::string JsonString;
typedef std::map<std::string, nlohmann::json> JsonObject;

class JsonDocument : public nlohmann::json {};

class DeserializationError : public std::string {
    public:
    operator bool() const {
        return !empty();
    }
};

DeserializationError deserializeJson(JsonDocument& document, const char* text);

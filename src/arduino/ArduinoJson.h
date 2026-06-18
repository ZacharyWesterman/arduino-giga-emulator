#pragma once

#include "../lib/json.hpp"
#include <string>
#include <map>

typedef std::string JsonString;
typedef std::map<std::string, nlohmann::json> JsonObject;

class JsonDocument : public nlohmann::json {
public:

    template <typename T>
    T as() {
        return get<T>();
    }

    template <typename T>
    bool is();
};

class DeserializationError : public std::string {
    public:
    operator bool() const {
        return !empty();
    }
};

DeserializationError deserializeJson(JsonDocument& document, const char* text);

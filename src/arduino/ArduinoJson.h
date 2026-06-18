#pragma once

#include "../lib/json.hpp"
#include <string>
#include <map>

typedef std::string JsonString;
typedef std::map<std::string, nlohmann::json> JsonObject;

// This is FUCKED tbh.
#define as get
#define isNull is_null

class JsonDocument : public nlohmann::json {
public:

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

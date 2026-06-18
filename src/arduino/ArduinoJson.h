#pragma once

#include "../lib/json.hpp"
#include <string>
#include <map>

typedef std::string JsonString;
typedef std::map<std::string, nlohmann::json> JsonObject;

class JsonDocument {
    nlohmann::json data;

public:

    template <typename T>
    T as();

    template <typename T>
    bool is();

    JsonDocument operator[](std::string) const;
};

int deserializeJson(JsonDocument& document, const char* text);

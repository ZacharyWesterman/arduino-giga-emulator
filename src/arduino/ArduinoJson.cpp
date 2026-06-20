#include "ArduinoJson.h"

DeserializationError deserializeJson(JsonDocument& document, const char* text) {
    try {
        document = nlohmann::json::parse(text);
    } catch(std::exception e) {
        return DeserializationError{e.what()};
    }

    return DeserializationError{};
}

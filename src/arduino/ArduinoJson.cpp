#include "ArduinoJson.h"

DeserializationError deserializeJson(JsonDocument& document, const char* text) {
    document = nlohmann::json::parse(text);

    return DeserializationError{};
}

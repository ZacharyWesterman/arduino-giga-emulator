#include "Arduino.h"

#include <chrono>
#include <iostream>
#include <thread>
#include <algorithm>

String::String(const char *value) : std::string(value) {}
String::String() : std::string() {}
String::String(char c) : std::string(1, c) {}
String::String(int value) : std::string(std::to_string(value)) {}
String::String(unsigned int value) : std::string(std::to_string(value)) {}
String::String(long value) : std::string(std::to_string(value)) {}
String::String(unsigned long value) : std::string(std::to_string(value)) {}
String::String(float value) : std::string(std::to_string(value)) {}
String::String(const std::basic_string<char> &value) : std::string(value) {}

String String::substring(unsigned int beginIndex, unsigned int endIndex) const {
	return substr(beginIndex, endIndex);
}

bool String::isEmpty() const {
	return empty();
}

String String::operator+(int rhs) const {
	return *this + String(rhs);
}

bool String::startsWith(const String& prefix) const {
	return 0 == compare(0, prefix.length(), prefix);
}

bool String::endsWith(const String& suffix) const {
	return 0 == compare(length() - suffix.length(), suffix.length(), suffix);
}

int String::indexOf(const String& c, int offset) const {
	return find(c, offset);
}

int String::lastIndexOf(const String& c, int offset) const {
	return rfind(c, offset);
}

void String::toLowerCase() {
	for (size_t i = 0; i < length(); i++) {
		this->at(i) = std::tolower(this->at(i));
	}
}

void String::concat(const char* str, int len) {
	operator+=(std::string(str, len));
}

char String::charAt(int index) const {
	return at(index);
}

void String::trim() {
    erase(begin(), std::find_if(begin(), end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));

    erase(std::find_if(rbegin(), rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), end());
}

int String::toInt() const {
	return std::stoi(*this);
}

unsigned long millis() {
	static auto begin = std::chrono::system_clock::now();
	auto elapsed = std::chrono::system_clock::now() - begin;

	return std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
}

void delay(unsigned long ms) {
	// std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void digitalWrite(int pinNumber, bool pinStatus) {}
void pinMode(int pinNumber, bool pinStatus) {}

void serialOut::print(const String &str) const {
	std::cout << str << std::flush;
}

void serialOut::println(const String &str) const {
	std::cout << str << std::endl;
}

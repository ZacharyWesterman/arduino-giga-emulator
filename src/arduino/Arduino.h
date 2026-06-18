#pragma once

#include <chrono>
#include <cinttypes>
#include <string>

#define HIGH 1
#define LOW 0
#define PROGMEM

class String : public std::string {
public:
	String(const char *value);
	String();
	String(char c);
	String(float value);
	String(int value);
	String(unsigned int value);
	String(long value);
	String(unsigned long value);
	String(const std::basic_string<char> &value);

	String substring(unsigned int beginIndex, unsigned int endIndex) const;
	inline String substring(unsigned int beginIndex) const {
		return substring(beginIndex, length());
	}

	bool isEmpty() const;

	String operator+(int rhs) const;

	bool startsWith(const String& prefix) const;
	bool endsWith(const String& suffix) const;
	int indexOf(char c, int offset = 0) const;
	int lastIndexOf(char c, int offset = 0) const;
	void toLowerCase();
	void concat(const char* str, int len);
	char charAt(int index) const;
	void trim();
	int toInt() const;
};

unsigned long millis();

void delay(unsigned long ms);

void digitalWrite(int pinNumber, bool pinStatus);

class serialOut {
public:
	void begin(int) const {};
	void print(const String &str) const;
	void println(const String &str) const;

	operator bool() const {
		return true;
	}
};

static serialOut Serial;

#include "console.h"

Console::Console(void) : HardwareSerial(0) {
	begin(115200);
	println();
	_max_tag_length = TAG_MAX_LENGTH;
}

void Console::line(style_t style, uint8_t length) {
	char chr = line_char[style];
	char line_str[length];
	memset(line_str, chr, length);
	println(line_str);
}

void Console::line(style_t style, const char * color, uint8_t length) {
	print(F(color));
	line(style, length);
	print(F(LOG_NORM));
}


void Console::writeTag(const char * tag) {
	char pad_str[_max_tag_length + 6];
	strcpy(pad_str, "[ ");
	memset(pad_str + 2, ' ', _max_tag_length);
	strcpy(pad_str + 2 + _max_tag_length, " ] ");
	strncpy(pad_str + 2, tag, strlen(tag));
	print(pad_str);
}

void Console::log(const char * tag, String message) {
	writeTag(tag);
	println(message);
}

void Console::success(const char * tag, String message) {
	print(F(LOG_GREN));
	log(tag, message);
	print(F(LOG_NORM));
}

void Console::info(const char * tag, String message) {
	print(F(LOG_BLUE));
	log(tag, message);
	print(F(LOG_NORM));
}

void Console::warning(const char * tag, String message) {
	print(F(LOG_YELW));
	log(tag, message);
	print(F(LOG_NORM));
}

void Console::error(const char * tag, String message) {
	print(F(LOG_RED));
	log(tag, message);
	print(F(LOG_NORM));
}

Console console;
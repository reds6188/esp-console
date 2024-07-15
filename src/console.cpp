#include "console.h"

Console::Console(void) : HardwareSerial(0) {
	begin(115200);
	println();
	_max_tag_length = TAG_MAX_LENGTH;
}

void Console::line(style_t style, uint8_t length) {
	char chr = line_char[style];
	char line_str[length + 1] = { };
	memset(line_str, chr, length);
	println(line_str);
}

void Console::line(style_t style, const char * color, uint8_t length) {
	print(F(color));
	line(style, length);
	print(F(LOG_NORM));
}

void Console::header(style_t style, const char * color, uint8_t length, const char * title) {
	int side = (length - strlen(title) - 6) / 2;
	char chr = line_char[style];
	char title_line[length + 1] = { };
	memset(title_line, chr, length);
	
	char title_str[strlen(title) + 7] = { };
	memset(title_str, ' ', strlen(title) + 6);
	strncpy(title_str + 3, title, strlen(title));
	strncpy(title_line + side, title_str, strlen(title) + 6);
	line(style, color, length);
	print(F(color));
	println(title_line);
	line(style, color, length);
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
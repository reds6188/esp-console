#ifndef CONSOLE_H_
#define CONSOLE_H_

#include <Arduino.h>

#define TAG_MAX_LENGTH		7

// ANSI colors ------------------------
#define LOG_NORM        "\033[0m"
#define LOG_RED         "\033[1;31m"
#define LOG_GREN        "\033[1;32m"
#define LOG_BLUE        "\033[1;34m"
#define LOG_YELW        "\033[1;33m"
#define LOG_MAGN        "\033[1;35m"
#define LOG_CYAN        "\033[1;36m"
#define LOG_GRAY        "\033[1;90m"
#define LOG_ORNG        "\033[38;5;214m"
#define LOG_PURP        "\033[38;5;91m"

// Line style -------------------------
typedef enum {
	DOTTED = 0,			// ...
	DASHED,				// ---
	DOUBLE_DASHED,		// ===
	LINE,				// ___
	WAVE,				// ~~~
	HASH,				// ###
	ASTERISK,			// ***
} style_t;

static const char line_char[] = {
	'.', '-', '=', '_', '~', '#', '*'
};

class Console : public HardwareSerial {
	private:
		uint8_t _max_tag_length;
	public:
		Console(void);
		void line(style_t style, uint8_t length);
		void line(style_t style, const char * color, uint8_t length);
		void header(style_t style, const char * color, uint8_t length, const char * title);
		void writeTag(const char * tag);
		void log(const char * tag, String message);
		void success(const char * tag, String message);
        void info(const char * tag, String message);
        void warning(const char * tag, String message);
        void error(const char * tag, String message);
		void data(const char * tag, String message);
		void disabled(const char * tag, String message);
};

extern Console console;

#endif  /* CONSOLE_H_ */
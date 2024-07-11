#ifndef CONSOLE_H_
#define CONSOLE_H_

#include <Arduino.h>

#define TAG_MAX_LENGTH		7

class Console : public HardwareSerial {
	private:
		uint8_t _max_tag_length;
	public:
		Console(void);
};

extern Console console;

#endif  /* CONSOLE_H_ */
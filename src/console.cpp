#include "console.h"

Console::Console(void) {
	begin(115200);
	println();
	_max_tag_length = TAG_MAX_LENGTH;
}
# esp-console
Console log library for ESP32

## Examples

```c++
#include <console.h>

#define MAIN_T     "MAIN"   // tag for log

void setup(void) {
    console.log(MAIN_T, "Hello World");
}

void loop(void) {
    delay(100);
}
```
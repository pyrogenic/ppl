#include <Arduino.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Debug.h"

void Serial_printf(const char *fmt, ...) {
  if (!Serial) {
    return;
  }
  va_list args;
  va_start(args, fmt);
  char buffer[255];
  vsnprintf(buffer, 255, fmt, args);
  va_end(args);
  Serial.print(buffer);
}

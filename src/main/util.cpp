#include "util.h"
#include <stdarg.h>
#include <stdio.h>
#include <Arduino.h>

void serial_printf(char* str, ...) {
  char buffer[100];

  va_list args;
  va_start(args, str);
  vsprintf(buffer, str, args);
  va_end(args);

  Serial.println(buffer);
}
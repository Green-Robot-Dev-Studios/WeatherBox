#include <WiFi.h>
#include "time_h.h"

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = -18000;
const int   daylightOffset_sec = 3600;

struct tm timeinfo;

void set_time() {
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.print("-> Current time is: ");
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}

int get_hour() {
  return timeinfo.tm_hour;
}

#include "weather.h"

#include <HTTPClient.h>
#include <string>
#include <ArduinoJson.h>

// String for storing server response
String response = "";
// JSON document
DynamicJsonDocument doc(8096 * 5);

void set_weather() {
  // Initiate HTTP client
  HTTPClient http;
  // The API URL
  String request = "https://api.open-meteo.com/v1/forecast?latitude=43.4643&longitude=-80.5204&hourly=temperature_2m,precipitation,windspeed_80m&daily=sunrise,sunset&timezone=America%2FNew_York";
  // Start the request
  http.begin(request);
  // Use HTTP GET request
  http.GET();
  // Response from server
  response = http.getString();
  // Parse JSON, read error if any
  DeserializationError error = deserializeJson(doc, response);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }

  http.end();
}

double get_temp(int hour) {
  return doc["hourly"]["temperature_2m"][hour];
}
double get_percipitation(int hour) {
  return doc["hourly"]["precipitation"][hour];
}
double get_wind(int hour) {
  return doc["hourly"]["windspeed_80m"][hour];
}
const char* get_sunrise() {
  return doc["daily"]["sunrise"][0];
}
const char* get_sunset() {
  return doc["daily"]["sunset"][0];
}
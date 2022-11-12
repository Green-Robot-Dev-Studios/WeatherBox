#include "lights.h"
#include "servo.h"
#include "fans.h"
#include "network.h"
#include "time_h.h"

#include <HTTPClient.h>
#include <string>
#include <ArduinoJson.h>

// //String for storing server response
String response = "";
// //JSON document
DynamicJsonDocument doc(8096 * 5);

void setup() {
  Serial.begin(115200);
  initialize_connection();
  setup_lights();
  setup_servo();
  if (check_connection()) {  //initilize time and weather
    set_time();
    getWeather();
  }
  doDemo();
}

void loop() {
  //Wait
  delay(5000);
  //Get weather details based on time
  unsigned long currentTime = millis();
  unsigned long seconds = currentTime / 1000;
  unsigned long minutes = seconds / 60;
  unsigned long hours = minutes / 60;
  double temperature = doc["hourly"]["temperature_2m"][hours];
  double percipitation = doc["hourly"]["precipitation"][hours];
  double wind = doc["hourly"]["windspeed_80m"][hours];
  const char* sunrise = doc["daily"]["sunrise"][0];
  const char* sunset = doc["daily"]["sunset"][0];

  //Update lights and servo based on weather details
  update_lights();
  update_servo();
}

//If demo button is pressed
void doDemo() {
  for (int i = 0; i < 24; i++) {
  double temperature = doc["hourly"]["temperature_2m"][i];
  double percipitation = doc["hourly"]["precipitation"][i];
  double wind = doc["hourly"]["windspeed_80m"][i];
    const char* sunrise = doc["daily"]["sunrise"][0];
    const char* sunset = doc["daily"]["sunset"][0];
    Serial.println(temperature);
    Serial.println(percipitation);
    Serial.println(wind);
    Serial.println(sunrise);
    Serial.println(sunset);
    Serial.println();
    update_lights();  // update lights with time of i and percipitation of time i
    update_servo();   // update servos with time of i and percipitation of time i
    delay(2000);      //wait 2 seconds before next hour
  }
}


void getWeather() {
  //Initiate HTTP client
  HTTPClient http;
  //The API URL
  String request = "https://api.open-meteo.com/v1/forecast?latitude=43.4643&longitude=-80.5204&hourly=temperature_2m,precipitation,windspeed_80m&daily=sunrise,sunset&timezone=America%2FNew_York";
  //Start the request
  http.begin(request);
  //Use HTTP GET request
  http.GET();
  //Response from server
  response = http.getString();
  //Parse JSON, read error if any
  DeserializationError error = deserializeJson(doc, response);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }
  //Print parsed value on Serial Monitor
  // Serial.println(doc["elevation"].as<char*>());
  // serializeJsonPretty(doc, Serial);
  //Close connection
  http.end();
}
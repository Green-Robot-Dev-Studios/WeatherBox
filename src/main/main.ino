#include "lights.h"
#include "servo.h"
#include "fans.h"
#include "network.h"
#include "time_h.h"

#include <HTTPClient.h>
#include <ArduinoJson.h>

// //String for storing server response
// String response = "";
// //JSON document
// DynamicJsonDocument doc(8096 * 5);

void setup() {
    Serial.begin(115200);
    // initialize_connection();
    setup_lights();
    setup_servo();
    // set_time();


    
}

void loop() {
    update_lights();
    update_servo();

    // //Initiate HTTP client
    // HTTPClient http;
    // //The API URL
    // String request = "https://api.open-meteo.com/v1/forecast?latitude=43.4643&longitude=-80.5204&hourly=temperature_2m,precipitation,windspeed_80m&daily=sunrise,sunset&timezone=America%2FNew_York";
    // //Start the request
    // http.begin(request);
    // //Use HTTP GET request
    // http.GET();
    // //Response from server
    // response = http.getString();
    // //Parse JSON, read error if any
    // DeserializationError error = deserializeJson(doc, response);
    // if(error) {
    //   Serial.print(F("deserializeJson() failed: "));
    //   Serial.println(error.f_str());
    //   return;
    // }
    // //Print parsed value on Serial Monitor
    // // Serial.println(doc["elevation"].as<char*>());
    // serializeJsonPretty(doc, Serial);
    // //Close connection  
    // http.end();
    // //Wait two seconds for next joke
    // delay(2000);
}
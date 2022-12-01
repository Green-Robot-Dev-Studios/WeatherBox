#include "lights.h"
#include "servo.h"
#include "fans.h"
#include "network.h"
#include "time_h.h"
#include "weather.h"
#include "util.h"

void setup() {
  // Serial connection
  Serial.begin(9600);
  // WiFi Connection
  initialize_connection();
  setup_lights();
  setup_servo();
  // Once WiFi is connected
  if (check_connection()) {
    set_time();
    set_weather();
  }

  // Demo purposes
  doDemo();
}

void loop() {
  // loop() will only run once the demo has completed. Do not write anything here.

  //Wait
  delay(10000);

  int hour = get_hour();
  double temperature = get_temp(hour);
  double percipitation = get_percipitation(hour);
  double wind = get_wind(hour);
  const char* sunrise = get_sunrise();
  const char* sunset = get_sunset();

  serial_printf("--- Updating display with hour %d ---", hour);
  serial_printf("-> Temperature: %lf", temperature);
  serial_printf("-> Percipitation: %lf", percipitation);
  serial_printf("-> Wind: %lf", wind);
  serial_printf("-> Sunrise: %s", sunrise);
  serial_printf("-> Sunset: %s", sunset);

  //Update lights and servo based on weather details
  update_lights(hour, percipitation, sunrise, sunset);
  update_servo(hour);
  serial_printf("--- Done updating ---");
}

void doDemo() {
  for (int i = 0; i < 24; i++) {
    double temperature = get_temp(i);
    double percipitation = get_percipitation(i);
    double wind = get_wind(i);
    const char* sunrise = get_sunrise();
    const char* sunset = get_sunset();
    serial_printf("--- Timelapsing to %d hours ---", i);
    serial_printf("-> Temperature: %lf", temperature);
    serial_printf("-> Percipitation: %lf", percipitation);
    serial_printf("-> Wind: %lf", wind);
    serial_printf("-> Sunrise: %s", sunrise);
    serial_printf("-> Sunset: %s", sunset);

    update_lights(i, 10.0, "", ""); // Update lights with time of i and percipitation of time i
    update_servo(i); // Update servos with time of i and percipitation of time i
    serial_printf("--- Done updating ---");
    Serial.println();

    delay(2000); // Wait 2 seconds before next hour
  }
}

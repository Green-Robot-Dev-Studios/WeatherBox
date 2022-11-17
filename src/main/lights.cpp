#include "lights.h"
#include <FastLED.h>
#include <math.h>
#include <string>
#include <WiFi.h>
#include "time_h.h"

#define LED_PIN 4
#define NUM_LEDS 60

CRGB leds[NUM_LEDS];

void setup_lights() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

int sine = 0;
int red = 255, green = 0, blue = 0, dim = 60;


void update_lights(int hour, double percipitation, const char* sunrise, const char* sunset) {
  if (Serial.available()) {                         // if there is data comming
    String command = Serial.readStringUntil('\n');  // read string until newline character

    red = command.substring(0, command.indexOf(",")).toInt();
    command = command.substring(command.indexOf(",") + 1, command.length());
    green = command.substring(0, command.indexOf(",")).toInt();
    command = command.substring(command.indexOf(",") + 1, command.length());
    blue = command.substring(0, command.indexOf(".")).toInt();
    command = command.substring(command.indexOf(".") + 1, command.length());
    dim = command.substring(0, command.length()).toInt();
  }

  sine++;
  // 0-23 inclusive
  switch (hour) {
    case 0:
      for (int i = 0; i < 60; i++) {
        if (i % 10 == 0) {
          leds[i] = CRGB(6, 1, 43);
        } else {
          leds[i] = CRGB(0, 0, 0);
        }
      }
      break;

    case 1:
      for (int i = 0; i < 60; i++) {
        if (i % 10 == 0) {
          leds[i] = CRGB(6, 1, 43);
        } else {
          leds[i] = CRGB(0, 0, 0);
        }
      }
      break;

    case 2:
      for (int i = 0; i < 60; i++) {
        if (i % 10 == 0) {
          leds[i] = CRGB(6, 1, 43);
        } else {
          leds[i] = CRGB(0, 0, 0);
        }
      }
      break;

    case 3:
      for (int i = 0; i < 60; i++) {
        if (i % 6 == 0) {
          leds[i] = CRGB(6, 1, 43);
        } else {
          leds[i] = CRGB(0, 0, 0);
        }
      }
      break;

    case 4:
      for (int i = 0; i < 60; i++) {
        if (i % 6 == 0) {
          leds[i] = CRGB(6, 1, 43);
        } else {
          leds[i] = CRGB(0, 0, 0);
        }
      }
      break;

    case 5:
      for (int i = 0; i < 60; i++) {
        if (i % 3 == 0) {
          leds[i] = CRGB(252, 29, 0);
        } else {
          leds[i] = CRGB(0, 0, 0);
        }
      }
      break;

    case 6:
      for (int i = 0; i < 60; i++) {
        if (i % 3 == 0) {
          leds[i] = CRGB(252, 29, 0);
        } else {
          leds[i] = CRGB(0, 0, 0);
        }
      }
      break;

    case 7:
      for (int i = 0; i < 60; i++) {
        if (i % 2 == 0) {
          leds[i] = CRGB(252, 184, 15);
        } else {
          leds[i] = CRGB(0, 0, 0);
        }
      }
      break;

    case 8:
      for (int i = 0; i < 60; i++) {
        if (i % 2 == 0) {
          leds[i] = CRGB(250, 203, 87);
        } else {
          leds[i] = CRGB(0, 0, 0);
        }
      }
      break;

    case 9:
      for (int i = 0; i < 60; i++) {
        leds[i] = CRGB(250, 203, 87);
      }
      break;

    case 10:
      for (int i = 0; i < 60; i++) {
        leds[i] = CRGB(250, 203, 87);
      }
      break;

    case 11:
      for (int i = 0; i < 60; i++) {
        leds[i] = CRGB(250, 203, 87);
      }
      break;

    case 12:
      for (int i = 0; i < 60; i++) {
        leds[i] = CRGB(250, 203, 87);
      }
      break;

    case 13:
      for (int i = 0; i < 60; i++) {
        leds[i] = CRGB(247, 160, 10);
      }
      break;

    case 14:
      for (int i = 0; i < 60; i++) {
        leds[i] = CRGB(247, 160, 10);
      }
      break;

    case 15:
      for (int i = 0; i < 60; i++) {
        if (i % 2 == 0) {
          leds[i] = CRGB(250, 203, 87);
        } else {
          leds[i] = CRGB(0, 0, 0);
        }
      }
      break;

    case 16:
      for (int i = 0; i < 60; i++) {
        if (i % 2 == 0) {
          leds[i] = CRGB(250, 203, 87);
        } else {
          leds[i] = CRGB(0, 0, 0);
        }
      }
      break;

    case 17:
      for (int i = 0; i < 60; i++) {
        if (i % 3 == 0) {
          leds[i] = CRGB(250, 203, 87);
        } else {
          leds[i] = CRGB(0, 0, 0);
        }
      }
      break;

    case 18:
      for (int i = 0; i < 60; i++) {
        if (i % 3 == 0) {
          leds[i] = CRGB(252, 184, 15);
        } else {
          leds[i] = CRGB(0, 0, 0);
        }
      }
      break;

    case 19:
      for (int i = 0; i < 60; i++) {
        if (i % 6 == 0) {
          leds[i] = CRGB(252, 29, 0);
        } else {
          leds[i] = CRGB(0, 0, 0);
        }
      }
      break;

    case 20:
      for (int i = 0; i < 60; i++) {
        if (i % 6 == 0) {
          leds[i] = CRGB(252, 29, 0);
        } else {
          leds[i] = CRGB(0, 0, 0);
        }
      }
      break;

    case 21:
      for (int i = 0; i < 60; i++) {
        if (i % 10 == 0) {
          leds[i] = CRGB(6, 1, 43);
        } else {
          leds[i] = CRGB(0, 0, 0);
        }
      }
      break;

    case 22:
      for (int i = 0; i < 60; i++) {
        if (i % 10 == 0) {
          leds[i] = CRGB(6, 1, 43);
        } else {
          leds[i] = CRGB(0, 0, 0);
        }
      }
      break;

    case 23:
      for (int i = 0; i < 60; i++) {
        if (i % 10 == 0) {
          leds[i] = CRGB(6, 1, 43);
        } else {
          leds[i] = CRGB(0, 0, 0);
        }
      }
      break;
  }
  FastLED.show();
}

/*
ideas:
- research sunset, sunrise, etc
- research how to make certain shades with RGB lights
- decide on brightness (can you adjust brightness) for each "level" of sun brightness
- what will the lights look light when its partly cloudy, cloudy
- think of different weather: sunny, partly cloudy, cloudly, raining/stormy 
- times of day: sunrise/set, nighttime (not all black, then can't see inside box)

time: 5-6am, 7-8pm - orange
weather:

*/
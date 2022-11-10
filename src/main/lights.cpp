#include "lights.h"
#include <FastLED.h>
#include <math.h>

#define LED_PIN 4
#define NUM_LEDS 60

CRGB leds[NUM_LEDS];

void setup_lights() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

int sine = 0;

void update_lights() {
  sine++;
//RGB has limit of 255, must adjust range of the sine function to match this (og sine range [-1,1])
  for (int i = 0; i < 60; i++) {
    leds[i] = CRGB(255, 0, 0);
  }

  FastLED.show();
  delay(1);
}

/*
ideas:
- research sunset, sunrise, etc
- research how to make certain shades with RGB lights
- decide on brightness (can you adjust brightness) for each "level" of sun brightness
- what will the lights look light when its partly cloudy, cloudy
- think of different weather: sunny, partly cloudy, cloudly, raining/stormy 
- times of day: sunrise/set, nighttime (not all black, then can't see inside box)

*/
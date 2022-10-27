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
    leds[i] = CRGB((sin(0, (i * 0.05) + (sine*0.01))+1)*127, 0);
  }

  FastLED.show();
  delay(1);
}
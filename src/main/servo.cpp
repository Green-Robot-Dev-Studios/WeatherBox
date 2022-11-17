#include "servo.h"
#include <ESP32Servo.h>

#define SERVO_PIN 16

Servo myservo;

void setup_servo() {
  myservo.attach(SERVO_PIN);
}

int pos = 0;
void update_servo(int hour) {
  int twelve_hour = hour % 12;
  double completion = 180 - ((twelve_hour / 12.0) * 180.0);

  myservo.write(completion);
}
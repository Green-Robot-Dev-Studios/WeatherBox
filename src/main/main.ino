#include "lights.h"
#include "servo.h"
#include "fans.h"
#include "network.h"

void setup() {
    setup_lights();
    setup_servo();
}

void loop() {
    update_lights();
    update_servo();
}

#include "lights.h"
#include "servo.h"
#include "fans.h"
#include "network.h"
#include "time_h.h"

void setup() {
    Serial.begin(115200);
    initialize_connection();
    setup_lights();
    setup_servo();
    set_time();
}

void loop() {
    update_lights();
    update_servo();
}

#include "network.h"
#include "WiFi.h"

const char* ssid = "RejieLi";
const char* password = "qjzx2711";

void initialize_connection() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi ..");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print('.');
        delay(1000);
    }
    Serial.println(WiFi.localIP());
}

int check_connection() {
    Serial.println(WiFi.status());
    return WiFi.status() == WL_CONNECTED;
}


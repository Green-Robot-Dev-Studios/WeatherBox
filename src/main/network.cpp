#include "network.h"
#include "WiFi.h"

const char* ssid = "REPLACE_WITH_HOTSPOT_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";

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
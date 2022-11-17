#include "network.h"
#include "WiFi.h"
#include "util.h"

const char* ssid = "test";
const char* password = "password";

void initialize_connection() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("\nConnecting to WiFi .");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.print("Got IP: ");
  Serial.println(WiFi.localIP());
}

int check_connection() {
  return WiFi.status() == WL_CONNECTED;
}
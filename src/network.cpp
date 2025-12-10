#include "network.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include "config.example.h" // will be replaced by user's config.h
#include <Arduino.h>

// Defaults (will be overridden by config.h if provided)
// Provide weak defaults to avoid compile error if user forgets to create config.h
#ifndef WIFI_SSID
  const char* WIFI_SSID = "";
  const char* WIFI_PASS = "";
  const char* THINGSPEAK_WRITE_KEY = "";
#else
  // if config.h defines them, they will be used
#endif

void networkBegin() {
  if (String(WIFI_SSID).length() == 0) {
    Serial.println("Warning: WIFI_SSID empty. Create src/config.h based on config.example.h");
    return;
  }
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.print("Conectando a WiFi");
  int tries = 0;
  while (WiFi.status() != WL_CONNECTED && tries < 40) {
    delay(500);
    Serial.print(".");
    tries++;
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi conectado");
    Serial.print("IP: "); Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nNo se pudo conectar a WiFi");
  }
}

bool networkConnected() {
  return (WiFi.status() == WL_CONNECTED);
}

int sendToThingSpeak(int field1, float field2, int field3, int field4, float field5, float field6, float field7, int field8) {
  if (!networkConnected()) return -1;
  HTTPClient http;
  String url = String("http://api.thingspeak.com/update?api_key=") + THINGSPEAK_WRITE_KEY +
               "&field1=" + String(field1) +
               "&field2=" + String(field2,2) +
               "&field3=" + String(field3) +
               "&field4=" + String(field4) +
               "&field5=" + String(field5,2) +
               "&field6=" + String(field6,2) +
               "&field7=" + String(field7,2) +
               "&field8=" + String(field8);
  http.begin(url);
  int code = http.GET();
  http.end();
  return code;
}
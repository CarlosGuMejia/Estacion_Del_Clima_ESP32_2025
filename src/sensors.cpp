#include "sensors.h"
#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <SHT21.h>
#include <Arduino.h>

// Pins (match your hardware)
static const int PIN_SOIL = 32;
static const int PIN_RAIN = 33;
static const int PIN_LIGHT = 34;
static const int PIN_VOLT = 35;

static Adafruit_BMP280 bmp;
static SHT21 sht;
static bool bmp_ok = false;

void sensorsBegin() {
  Wire.begin();
  if (bmp.begin(0x76)) {
    bmp_ok = true;
  } else if (bmp.begin(0x77)) {
    bmp_ok = true;
  } else {
    bmp_ok = false;
  }
  // SHT21: some libraries don't need begin()
  // sht.begin(); // if your lib requires it, uncomment
}

int readAvg(int pin, int samples=10, int delayMs=10) {
  long sum = 0;
  for (int i=0;i<samples;i++) {
    sum += analogRead(pin);
    delay(delayMs);
  }
  return (int)(sum / samples);
}

int readSoilRaw() {
  return readAvg(PIN_SOIL);
}
int readRainRaw() {
  return readAvg(PIN_RAIN);
}
int readLightRaw() {
  return readAvg(PIN_LIGHT);
}
int readVoltRaw() {
  return readAvg(PIN_VOLT);
}

float readBmpTemp() {
  if (!bmp_ok) return NAN;
  return bmp.readTemperature();
}
float readBmpPres() {
  if (!bmp_ok) return NAN;
  return bmp.readPressure() / 100.0F;
}
float readShtTemp() {
  return sht.getTemperature();
}
float readShtHum() {
  return sht.getHumidity();
}
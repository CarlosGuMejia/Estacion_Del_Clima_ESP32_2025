#pragma once
#include <Arduino.h>

void sensorsBegin();
int readSoilRaw();
int readRainRaw();
int readLightRaw();
int readVoltRaw();
float readBmpTemp();
float readBmpPres();
float readShtTemp();
float readShtHum();
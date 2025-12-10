#include "config.example.h" // copy to config.h and define values
#include "sensors.h"
#include "network.h"
#include "mapping.h"
#include <Arduino.h>

const long interval = 20000; // 20s

// Calibration values (from your measurements)
const int SOIL_DRY = 4095;
const int SOIL_WET = 1918;

const int RAIN_DRY = 4095;
const int RAIN_WET = 2067;

const int LIGHT_DARK = 4095;
const int LIGHT_BRIGHT = 40;

unsigned long previousMillis = 0;

void setup() {
  Serial.begin(9600);
  delay(200);
  Serial.println("Iniciando Estación - módulo principal");
  sensorsBegin();
  networkBegin();
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    int rawSoil = readSoilRaw();
    int rawRain = readRainRaw();
    int rawLight = readLightRaw();
    int rawVolt = readVoltRaw();

    float tempBmp = readBmpTemp();
    float presBmp = readBmpPres();
    float tempSht = readShtTemp();
    float humSht = readShtHum();

    int soilPct = (int)mapToPercentFloat(rawSoil, SOIL_DRY, SOIL_WET, true);
    int rainPct = (int)mapToPercentFloat(rawRain, RAIN_DRY, RAIN_WET, true);
    int lightPct = (int)mapToPercentFloat(rawLight, LIGHT_DARK, LIGHT_BRIGHT, true);

    Serial.println("------ LECTURAS ------");
    Serial.print("Soil raw: "); Serial.print(rawSoil); Serial.print(" -> "); Serial.print(soilPct); Serial.println(" %");
    Serial.print("Rain raw: "); Serial.print(rawRain); Serial.print(" -> "); Serial.print(rainPct); Serial.println(" %");
    Serial.print("Light raw: "); Serial.print(rawLight); Serial.print(" -> "); Serial.print(lightPct); Serial.println(" %");
    Serial.print("Temp BMP: "); Serial.println(tempBmp);
    Serial.print("Pres BMP: "); Serial.println(presBmp);
    Serial.print("Temp SHT: "); Serial.println(tempSht);
    Serial.print("Hum SHT: "); Serial.println(humSht);
    Serial.println("----------------------");

    int httpCode = sendToThingSpeak(soilPct, tempBmp, rainPct, lightPct, presBmp, tempSht, humSht, rawVolt);
    if (httpCode > 0) {
      Serial.print("ThingSpeak HTTP code: "); Serial.println(httpCode);
    } else {
      Serial.println("No se envió (no hay conexión o error)");
    }
  }
}
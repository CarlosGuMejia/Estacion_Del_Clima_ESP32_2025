# 🌤️ Estación Meteorológica IoT – ESP32 (Versión 2025)

Proyecto de estación meteorológica basada en ESP32 (WROVER) para medir variables ambientales y enviar datos a ThingSpeak. Código modular en C++/Arduino.

## Estructura
```
EstacionClimaESP32/
├── src/
│   ├── main.ino
│   ├── sensors.cpp
│   ├── sensors.h
│   ├── network.cpp
│   ├── network.h
│   ├── mapping.cpp
│   ├── mapping.h
│   └── config.example.h
├── docs/
│   ├── arquitectura_estacion.md
│   └── esquema_conexiones.png (En Proceso)
├── hardware/
│   └── lista_componentes.md
├── .gitignore
└── LICENSE
```

## Cómo usar
1. Copia `src/config.example.h` a `src/config.h` y rellena `WIFI_SSID`, `WIFI_PASS` y `THINGSPEAK_WRITE_KEY`. **No subir `config.h` al repositorio ya que estarias revelando datos sensibles.**
2. Abre `src/main.ino` en Arduino IDE (selecciona "ESP32 Wrover Module").
3. Instala librerías:
   - Adafruit BMP280
   - Adafruit Unified Sensor
   - SHT21 (la que uses)
4. Compila y sube.
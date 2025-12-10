# 🌤️ Estación Meteorológica IoT – ESP32 (Versión 2025)

Proyecto de estación meteorológica basada en ESP32 (WROVER) para medir variables ambientales y enviar datos a ThingSpeak. Código modular en C++/Arduino.
Incluye sensores de temperatura, humedad, presión, luz solar, lluvia, humedad de suelo y voltaje de batería.

## Estructura del Proyecto
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
### 🚀 Características principales

📡 Conexión WiFi automática

🌡️ Lectura de sensores múltiples:

BMP280 → Temperatura y presión

SHT21 → Temperatura y humedad

Fotoresistor → Luz solar

Sensor resistivo → Lluvia

Sensor resistivo → Humedad de suelo

ADC interno → Voltaje de batería

☁️ Envío de datos a ThingSpeak por API

🔄 Mapeo normalizado (0–100) para sensores análogos

⚡ Compatible con ESP32 Wrover Kit

🔧 Código modular, fácil de extender y mantener

#### 🧱 Hardware utilizado

Componente	Descripción

ESP32 Wrover Kit	MCU principal

BMP280	Temperatura + presión

SHT21	Temperatura + humedad

Sensor de lluvia resistivo	Lectura análoga

Sensor de humedad de suelo	Lectura análoga

Fotoresistor (LDR)	Intensidad de luz

Divisor resistivo	Medición del voltaje de batería

Cables Dupont	Conexión

Fuente 5V / Batería Lipo	Alimentación

##### 🧩 Conexión de pines
Función-------------------Pin ESP32

Sensor lluvia------------------35

Humedad suelo---------------34

Luz solar---------------------32

Voltaje batería---------------33

I2C SDA (BMP280 + SHT21)----21

I2C SCL (BMP280 + SHT21)----22

Puedes encontrar el diagrama detallado en /docs/esquema_conexiones.png.

###### ▶️ Cómo compilar y cargar
1. Copia `src/config.example.h` a `src/config.h` y rellena `WIFI_SSID`, `WIFI_PASS` y `THINGSPEAK_WRITE_KEY`. 

2. Abre `src/main.ino` en Arduino IDE (selecciona "ESP32 Wrover Module").

3. Instala librerías:
   - Adafruit BMP280
   - Adafruit Unified Sensor
   - SHT21 (la que uses)

4. Compila y Sube el código al ESP32

Y listo.

###### 📊 Ejemplo de lecturas

------ LECTURAS DE SENSORES ------

Humedad Suelo: 41 %

Lluvia: 12 %

Luz Solar: 87 %

BMP Temp: 27.30 °C

BMP Presión: 899.5 hPa

SHT Temp: 26.6 °C

SHT Humedad: 40 %

Voltaje Batería: 3.72 V
-----------------------------------


###### 🤝 Contribuir

Si deseas aportar mejoras:

Haz un fork

Crea una rama (feature-nueva)

Envía un Pull Request


###### 📄 Licencia

Este proyecto está bajo la Licencia MIT. Ver LICENSE para más detalles.

###### 👥 Equipo

    Desarrollo: EcoMonitor Team
    Estación: Universidad del Valle - Sede Tulúa
    API: ThingSpeak


Si tienes dudas o quieres sugerir mejoras, siéntete libre de abrir un issue en el repositorio.

###### 📧 Contacto

Carlos.humberto.gutierrez@correounivalle.edu.co
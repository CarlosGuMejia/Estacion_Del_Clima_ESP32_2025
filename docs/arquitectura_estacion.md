# Arquitectura de la Estación (resumen)

Ver README.md para la descripción completa. Aquí se detalla la interacción de módulos:

- `sensors.cpp/.h` : inicializa y lee BMP280, SHT21 y ADCs.
- `mapping.cpp/.h` : funciones de mapeo y normalización.
- `network.cpp/.h` : conexión WiFi y envío a ThingSpeak.
- `main.ino` : orquestador principal (muestreo y envío).
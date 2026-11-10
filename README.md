# Brote Lab

Mi laboratorio para re-aprender microcontroladores, sensores y redes de punta a punta.
La meta es construir **Brote #001** (un monitor de plantas) y prepararme para los proyectos IoT del PTI (monitoreo de gas y alumbrado con LoRaWAN).

Placa principal: **LILYGO T3 V1.6.1** (ESP32-PICO-D4 + LoRa SX1278 433 MHz + OLED).

## Estructura

```
brote-lab/
├── cronograma.md   ← plan de sesiones, inventario y pendientes
├── bitacora/       ← una nota por sesión: AAAA-MM-DD-sesion-NN.md
├── firmware/       ← un sketch por sesión: NNN-Placa-descripcion/
└── imagenes/       ← fotos de circuitos (sesion-NN/) y del fabricante
```

## Sesiones

| # | Sesión | Bitácora | Firmware |
|---|---|---|---|
| 1 | Hola Cami en la OLED | [2026-11-09](bitacora/2026-11-09-sesion-01.md) | [001-LilyGo-imprimirnombre](firmware/001-LilyGo-imprimirnombre/) |
| 2 | Pinout y salidas digitales | [2026-11-10](bitacora/2026-11-10-sesion-02.md) | [002-LilyGo-parpadeo](firmware/002-LilyGo-parpadeo/) |

El plan completo está en [cronograma.md](cronograma.md).

## Cómo trabajo

- Cada sesión va en su propia rama: `sesion-NN-descripcion`.
- Al cerrar la sesión: bitácora + commit, y merge a `main`.

## Entorno

- Arduino IDE 2.x + core ESP32 de Espressif (v3.3.12)
- Placa en el IDE: **TTGO LoRa32-OLED**, revisión **TTGO LoRa32 V2.1 (1.6.1)**
- Librerías: Adafruit SSD1306, Adafruit GFX

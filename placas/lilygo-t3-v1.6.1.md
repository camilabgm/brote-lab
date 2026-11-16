# LILYGO T3 V1.6.1 (ESP32 + LoRa 433 MHz + OLED)

**Chip principal:** ESP32-PICO-D4 (ESP32 + 4 MB de flash + cristal de 40 MHz en un solo encapsulado)
**Radio:** LoRa SX1278, 433/470 MHz
**Voltaje lógico:** 3,3 V. **Nunca 5 V en un GPIO.**
**Conversor USB-serie:** CH9102F (si Windows no reconoce la placa, es el driver que hay que instalar)
**Fecha de fábrica impresa en la placa:** 20210104
**MAC:** `4c:75:25:a8:4e:f0`
**Puerto en mi notebook:** COM7
**Configuración en el IDE:** placa **TTGO LoRa32-OLED**, revisión **TTGO LoRa32 V2.1 (1.6.1)**, core ESP32 de Espressif v3.3.12
**Nombres:** LILYGO = marca (antes TTGO, por eso el IDE dice TTGO). LoRa32 = línea. T3 = modelo. V1.6.1 = revisión del hardware.
**Fuentes:** foto del fabricante con la serigrafía de los pines [`datasheets/lilygo-t3-v1.6.1-serigrafia.png`](datasheets/lilygo-t3-v1.6.1-serigrafia.png), sesiones [01](../bitacora/2026-11-09-sesion-01.md) y [02](../bitacora/2026-11-10-sesion-02.md). Falta el diagrama de pinout oficial del fabricante (con las funciones de cada pin).

## 1. Anatomía

| Parte | Para qué sirve | Cómo habla con el ESP32 | Pines |
|---|---|---|---|
| Pantalla OLED 0,96" (SSD1306, 128 × 64 px) | Mostrar texto y gráficos | I2C, dirección `0x3C` | 21 (SDA), 22 (SCL) |
| Radio LoRa SX1278 | Comunicación por radio de largo alcance | SPI | 5, 18, 19, 23, 26, 27 (+ LoRa1, LoRa2) |
| Ranura microSD | Guardar datos | SPI | 2, 13, 14, 15 |
| LED verde integrado | Indicador | GPIO | 25 |
| Medición de batería | Leer el voltaje de la batería | ADC | 35 |
| Conversor USB-serie CH9102F | Traducir entre USB (computadora) y UART (ESP32). Por acá se sube el programa y habla el Serial Monitor | UART | TXD (1), RXD (3) |
| Conector SMA / IPEX | Antena LoRa. **Nunca transmitir sin antena** | — | — |
| Resistencia selectora de antena | Elige SMA o IPEX (marcada en rojo en la foto del fabricante). **No tocar** | — | — |
| Conector JST de batería | Batería de litio de 3,7 V (cargador incorporado) | — | — |
| Switch ON/OFF y botón RST | Encender/apagar y reiniciar el programa | — | — |

Los agujeros del borde vienen **sin pines soldados**: para la protoboard se usan cables dupont **macho/macho**.

## 2. Pines que salen al borde

Según la serigrafía de la placa (vista de frente, con la antena abajo):

| Borde izquierdo | Borde derecho |
|---|---|
| S_VP (36) | IO21 |
| S_VN (39) | TXD (1) |
| RST | RXD (3) |
| IO34 | IO22 |
| IO35 | IO23 |
| IO14 | IO19 |
| IO12 | LoRa2 |
| IO13 | LoRa1 |
| IO15 | IO26 |
| IO2 | GND |
| IO0 | 3.3V |
| IO4 | GND |
| IO25 | 5V |

**No salen al borde:** 5, 18, 27 (usados por la radio LoRa por dentro) y **32, 33**. Los pines 32 y 33 no se pueden usar en esta placa.

## 3. Pines reservados (no usar)

| Pines | Ocupados por | Fuente |
|---|---|---|
| 21, 22 | OLED (I2C) | Sesión 01 (funcionó con `Wire.begin(21, 22)`) |
| 5, 18, 19, 23, 26, 27, LoRa1, LoRa2 | Radio LoRa (SPI y señales de la radio) | Sesión 02, serigrafía |
| 2, 13, 14, 15 | microSD | Sesión 02 |
| 35 | Medición de batería | Sesión 02 |
| TXD (1), RXD (3) | UART del USB: subida del programa y Serial Monitor. Conectar algo ahí rompe la subida | Serigrafía + dato del chip ESP32 |
| 25 | LED integrado (se puede usar como salida para el LED) | Sesión 02 (funcionó) |
| 5V, 3.3V, GND | Alimentación. **El pin 5V nunca va a un GPIO** | Serigrafía |

## 4. Pines con cuidado

| Pin | Qué tiene de especial |
|---|---|
| 0 | Botón de arranque (*boot*). No usar |
| 12 | Pin de configuración al arrancar (*strapping*): según su nivel al encender puede cambiar el voltaje de la flash y la placa no arranca. Evitar |
| 34, 36 (S_VP), 39 (S_VN) | **Solo entrada.** **No tienen pull-up ni pull-down interno** (dato del chip ESP32): como entrada digital necesitan resistencia externa. Son del **ADC1**: ideales para sensores analógicos (ver abajo) |
| ADC2 (0, 2, 4, 12–15, 25–27) | El conversor analógico ADC2 **no funciona mientras el WiFi está activo** (dato del chip ESP32) |

## 5. Pines libres y para qué sirve cada uno

| Pin | Capacidades | Uso recomendado | Probado |
|---|---|---|---|
| 4 | Digital entrada/salida, pull-up interno, ADC2, táctil | **Todo lo digital:** LEDs, entradas, DHT22 | ✅ Sesión 02 (salida, LED externo) |
| 34 | Solo entrada, ADC1, sin pull-up interno | **Sensores analógicos** | |
| 36 (S_VP) | Solo entrada, ADC1, sin pull-up interno | **Sensores analógicos** | |
| 39 (S_VN) | Solo entrada, ADC1, sin pull-up interno | **Sensores analógicos** | |

**Regla para Brote #001:** todo sensor **analógico** (humedad de suelo capacitivo, YL-38 en modo analógico) va en **34, 36 o 39**, porque son del ADC1 y siguen funcionando cuando la placa use WiFi para mandar los datos. El pin **4** queda para lo **digital**.

Con un solo pin digital libre, si una sesión necesita dos salidas digitales, la segunda puede ser el 25 (LED integrado, ya probado como salida).

## 6. Historial de uso

| Sesión | Pin | Para qué | Resultado |
|---|---|---|---|
| 01 | 21, 22 | OLED por I2C ("Hola Cami") | ✅ |
| 02 | 25 | LED integrado, salida digital | ✅ |
| 02 | 4 | LED externo con resistencia de 220 Ω en protoboard | ✅ |

## 7. Mañas y errores conocidos

| Síntoma | Causa | Solución |
|---|---|---|
| La placa prende pero no aparece ningún puerto COM | Cable USB **solo de carga** (sin hilos de datos) | Usar un cable de datos |
| `setupSDCard FAIL` en el Serial Monitor | Sigue corriendo la demo de fábrica: el programa no se subió | Subir con **Upload (→)** |
| `unable to open ftdi device` | Se apretó **Debug**: busca un depurador JTAG que no hay | **Upload (→)** o **Ctrl + U** |
| `Failed uploading: no upload port provided` | No hay puerto elegido | **Tools → Port → COM7** |
| Componente externo que no responde | Cable dupont **hembra** en la protoboard: no hace contacto | Cables **macho/macho** |
| Caracteres raros en el Serial Monitor | Velocidad distinta en el código y en el monitor | Las dos en **115200** |

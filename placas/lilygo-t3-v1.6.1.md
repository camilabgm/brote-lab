# LILYGO T3 V1.6.1 (ESP32 + LoRa 433 MHz + OLED)

**Chip principal:** ESP32-PICO-D4 (ESP32 + 4 MB de flash + cristal de 40 MHz en un solo encapsulado)
**Radio:** LoRa SX1278, 433 MHz
**Voltaje lógico:** 3,3 V. **Nunca 5 V en un GPIO.**
**MAC:** `4c:75:25:a8:4e:f0`
**Puerto en mi notebook:** COM7
**Configuración en el IDE:** placa **TTGO LoRa32-OLED**, revisión **TTGO LoRa32 V2.1 (1.6.1)**, core ESP32 de Espressif v3.3.12
**Nombres:** LILYGO = marca (antes TTGO, por eso el IDE dice TTGO). LoRa32 = línea. T3 = modelo. V1.6.1 = revisión del hardware.
**Fuentes:** sesiones [01](../bitacora/2026-11-09-sesion-01.md) y [02](../bitacora/2026-11-10-sesion-02.md), imagen del fabricante [`LoRa-IPEX.png`](../imagenes/LilyGo-433470/LoRa-IPEX.png). Falta guardar el pinout oficial en `datasheets/`.

## 1. Anatomía

| Parte | Para qué sirve | Cómo habla con el ESP32 | Pines |
|---|---|---|---|
| Pantalla OLED 0,96" (SSD1306, 128 × 64 px) | Mostrar texto y gráficos | I2C, dirección `0x3C` | 21 (SDA), 22 (SCL) |
| Radio LoRa SX1278 | Comunicación por radio de largo alcance | SPI | 5, 18, 19, 23, 26, 27 (+ LoRa1, LoRa2) |
| Ranura microSD | Guardar datos | SPI | 2, 13, 14, 15 |
| LED verde integrado | Indicador | GPIO | 25 |
| Medición de batería | Leer el voltaje de la batería | ADC | 35 |
| Chip conversor USB-serie | Traducir entre USB (computadora) y UART (ESP32) | UART | — |
| Conector SMA / IPEX | Antena LoRa. **Nunca transmitir sin antena** | — | — |
| Resistencia selectora de antena | Elige SMA o IPEX (marcada en rojo en la imagen del fabricante). **No tocar** | — | — |
| Conector JST de batería | Batería de litio de 3,7 V (cargador incorporado) | — | — |
| Switch ON/OFF y botón RST | Encender/apagar y reiniciar el programa | — | — |

Los agujeros del borde vienen **sin pines soldados**: para la protoboard se usan cables dupont **macho/macho**.

## 2. Pines reservados (no usar)

| Pines | Ocupados por | Fuente |
|---|---|---|
| 21, 22 | OLED (I2C) | Sesión 01 (funcionó con `Wire.begin(21, 22)`) |
| 5, 18, 19, 23, 26, 27 (+ LoRa1, LoRa2) | Radio LoRa (SPI) | Sesión 02, pinout del fabricante |
| 2, 13, 14, 15 | microSD | Sesión 02, pinout del fabricante |
| 35 | Medición de batería | Sesión 02, pinout del fabricante |
| 25 | LED integrado (se puede usar como salida para el LED) | Sesión 02 (funcionó) |

## 3. Pines con cuidado

| Pin | Qué tiene de especial |
|---|---|
| 0 | Botón de arranque (*boot*). No usar |
| 12 | Pin de configuración al arrancar (*strapping*): según su nivel al encender puede cambiar el voltaje de la flash y la placa no arranca. Evitar |
| 34, 36 (S_VP), 39 (S_VN) | **Solo entrada.** Además **no tienen pull-up ni pull-down interno** (dato del chip ESP32): si se usan como entrada digital necesitan resistencia externa |
| ADC2 (0, 2, 4, 12–15, 25–27) | El conversor analógico ADC2 **no funciona mientras el WiFi está activo** (dato del chip ESP32). Para sensores analógicos en proyectos con WiFi, usar pines del ADC1 (32–39) |
| 32, 33 | *(a confirmar con el pinout oficial)* pueden estar conectados a la radio LoRa por los pads marcados LoRa1 / LoRa2. Verificar antes de usarlos |

## 4. Pines libres

| Pin | Capacidades | Probado |
|---|---|---|
| 4 | Digital entrada/salida, pull-up interno, ADC2 (no sirve como analógico con WiFi), táctil | ✅ Sesión 02 (salida, LED externo) |

*(A completar cuando se guarde el pinout oficial en `datasheets/`.)*

## 5. Historial de uso

| Sesión | Pin | Para qué | Resultado |
|---|---|---|---|
| 01 | 21, 22 | OLED por I2C ("Hola Cami") | ✅ |
| 02 | 25 | LED integrado, salida digital | ✅ |
| 02 | 4 | LED externo con resistencia de 220 Ω en protoboard | ✅ |

## 6. Mañas y errores conocidos

| Síntoma | Causa | Solución |
|---|---|---|
| La placa prende pero no aparece ningún puerto COM | Cable USB **solo de carga** (sin hilos de datos) | Usar un cable de datos |
| `setupSDCard FAIL` en el Serial Monitor | Sigue corriendo la demo de fábrica: el programa no se subió | Subir con **Upload (→)** |
| `unable to open ftdi device` | Se apretó **Debug**: busca un depurador JTAG que no hay | **Upload (→)** o **Ctrl + U** |
| `Failed uploading: no upload port provided` | No hay puerto elegido | **Tools → Port → COM7** |
| Componente externo que no responde | Cable dupont **hembra** en la protoboard: no hace contacto | Cables **macho/macho** |
| Caracteres raros en el Serial Monitor | Velocidad distinta en el código y en el monitor | Las dos en **115200** |

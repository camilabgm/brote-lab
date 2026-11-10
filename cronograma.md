# Brote Lab — Cronograma de sesiones

**Versión:** 1 (10/11/2026)
**Objetivo general:** re-aprender microcontroladores, sensores y redes de punta a punta, construir **Brote #001** (monitor de plantas) y prepararme para los proyectos IoT del PTI (monitoreo de gas y alumbrado con LoRaWAN).

## Reglas de trabajo

- Sesiones de 60–90 minutos, a la mañana. Una o dos por día según la energía.
- **Un concepto nuevo por sesión.** Si una sesión sale rápido, paso a la siguiente.
- **Anatomía primero:** cada componente nuevo arranca con qué es, qué partes tiene y cómo se comunica.
- Se corta cuando la confusión se vuelve frustración, no cuando se termina el horario.
- Al final de cada sesión: bitácora (qué hice, qué entendí, qué me confundió) y commit cuando yo lo decida.
- Cada sesión en su propia rama de Git.

## Inventario

| Componente | Microcontrolador / chip | Voltaje lógico | Notas |
|---|---|---|---|
| LILYGO T3 V1.6.1 | ESP32-PICO-D4 + LoRa SX1278 | 3,3 V | 433 MHz. OLED, microSD. Placa principal |
| TTGO LoRa32 (carcasa 3D), placa "LORA_V1.3 20190614" | ESP32-D0WDQ6 + flash externa + LoRa **SX1276** | 3,3 V | **868/915 MHz** (antena "TTGO/915"). Conversor USB CP2104. Antena chip de WiFi/BT + antena LoRa por pigtail |
| Heltec HT-M00 | Gateway LoRa de 2 canales (ESP32) | — | **Frecuencia a confirmar** (etiqueta trasera) |
| Arduino Uno | ATmega328P | 5 V | Cable USB-B |
| 2 × Arduino Mega 2560 | ATmega2560 | 5 V | Clones |
| 2 × Arduino Nano | ATmega328P | 5 V | Clones con chip CH340. **Cable mini-USB** |
| Ethernet Shield W5100 | W5100 | 5 V | Con ranura microSD |
| 2 × sensor de humedad de suelo capacitivo v1.2 | — | 3,3–5 V | Salida analógica |
| DHT22 (módulo) | — | 3,3–5 V | Temperatura y humedad del aire |
| YL-38 + sonda | LM393 | 3,3–5 V | Salida digital y analógica |
| PMS5003 + cable | — | 5 V (datos 3,3 V) | Material particulado, UART |
| MiCS-6814 | — | 5 V | CO, NH3 y NO2. Nuevo, en bolsa antiestática |
| ME2-CO | Electroquímico | — | Posiblemente agotado; necesita circuito amplificador |
| Regulador AMS1117 | — | 5 V → 3,3 V | |
| Porta-batería 18650 | — | 3,7 V / salida USB 5 V | |
| Protoboards, cables dupont (M/H, H/M), resistencias | — | — | Valor de las resistencias desconocido |
| LEDs sueltos | — | — | Sin pulsadores |
| Multímetro | — | — | Prestado, por recuperar |
| **Pendiente de compra** | Mini bomba 3–5 V + relé 1 canal compatible con 3,3 V | | La tienda los tendría esta semana |

## Módulo 1 — Dominar la placa (LILYGO)

*Objetivo: entender cómo el ESP32 interactúa con el mundo físico a través de sus pines.*

| # | Sesión | Conceptos | Componentes | Estado |
|---|---|---|---|---|
| 1 | Hola Cami en la OLED | Placa, core, librerías, UART, I2C | LILYGO | ✅ 09/11 |
| 2 | Pinout y salidas digitales | GPIO, HIGH/LOW, 3,3 V, pines reservados de la placa, `delay()` vs `millis()`, por qué un LED necesita resistencia, código de colores | LED integrado + LED externo con resistencia en protoboard | ✅ 10/11 (falta `millis()`) |
| 3 | Entradas digitales | Pull-up / pull-down, pin flotante, rebote | Cable puente a GND | |
| 4 | Entradas analógicas (ADC) | Conversión analógico-digital, 12 bits, ADC1 vs ADC2 (el ADC2 no funciona con WiFi) | YL-38 + sonda | |

## Módulo 2 — Sensores (corazón de Brote #001)

*Objetivo: leer el mundo, calibrar y mostrar los datos.*

| # | Sesión | Conceptos | Componentes | Estado |
|---|---|---|---|---|
| 5 | Humedad de suelo capacitiva | Calibración seco/agua, conversión a %, ruido y promedios | Sensor capacitivo | |
| 6 | DHT22 | Protocolo de un solo cable, tiempos de lectura, librería | DHT22 | |
| 7 | Sensor de lluvia | Salida digital vs analógica, umbral del potenciómetro | YL-38 + placa de lluvia | |
| 8 | **Brote #001 v0: estación offline** | Integrar todo en un programa ordenado, mostrarlo en la OLED | Todo lo anterior | |

## Módulo 3 — Redes

*Objetivo: que el dato salga de la placa y llegue a mi backend, entendiendo cada salto.*

| # | Sesión | Conceptos | Componentes | Estado |
|---|---|---|---|---|
| 9 | WiFi e IP en la OLED | Modo estación, DHCP, IP privada, MAC, RSSI, subred | LILYGO | |
| 10 | HTTP: la placa como cliente | Petición/respuesta, métodos, códigos de estado, JSON | LILYGO | |
| 11 | Backend Next.js + Prisma | API en la red local, puertos, firewall de Windows, por qué `localhost` no sirve desde la placa | LILYGO + notebook | |
| 12 | MQTT | Broker, publicar/suscribir, topics, QoS | LILYGO + broker | |
| 13 | Red por cable: Arduino + Ethernet shield | Ethernet vs WiFi, IP fija vs DHCP, 5 V vs 3,3 V | Uno o Mega + W5100 | |

## Módulo 4 — Brote #001 completo

*Objetivo: el sistema de punta a punta, del sensor a la alerta.*

| # | Sesión | Conceptos | Componentes | Estado |
|---|---|---|---|---|
| 14 | Reglas y alertas | Lógica de riego, notificaciones por Telegram | Backend | |
| 15 | Dashboard | Gráficos de lecturas en el tiempo | Next.js o Grafana | |
| 16 | Energía | Batería 18650, consumo, *deep sleep* | Porta-18650, AMS1117 | |
| 17 | Riego automático | Relé, carga externa, aislar el agua de la electrónica | Bomba + relé | Cuando lleguen |

## Módulo 5 — Preparación PTI (gas y LoRa)

*Objetivo: lo que sirve directamente para los proyectos de monitoreo de gas y alumbrado.*

| # | Sesión | Conceptos | Componentes | Estado |
|---|---|---|---|---|
| 18 | PMS5003: un sensor que habla UART | Tramas UART, alimentación de 5 V con datos de 3,3 V | PMS5003 | |
| 19 | MiCS-6814: gas multicanal | Precalentamiento, resistencia del sensor, calibración, curvas de ppm | MiCS-6814 | |
| 20 | Diagnóstico del ME2-CO | Sensores electroquímicos, vida útil, circuito amplificador | ME2-CO | |
| 21 | SPI y la radio LoRa | Cómo habla el ESP32 con la radio, frecuencias por región, SF/BW, RSSI/SNR | TTGO 915 | |
| 22 | Gateway HT-M00 | Qué hace un gateway, conexión a WiFi, registro en un servidor de red | HT-M00 | Si es de 915 |
| 23 | LoRaWAN de punta a punta | Nodo → gateway → servidor de red → mi backend. Conexión con la tesis y el alumbrado | TTGO 915 + HT-M00 | Si es de 915 |

## Pendientes de confirmar

- [x] Frecuencia de la TTGO de la carcasa: chip **SX1276** → 868/915 MHz ✅
- [ ] Frecuencia del gateway HT-M00 (etiqueta trasera).
- [x] LEDs sueltos: sí. Pulsadores: no (sesión 3 con cable puente).
- [ ] Recuperar el multímetro.
- [x] Cables para los Arduino ✅
- [ ] Identificar el valor de las resistencias: por colores, probablemente de 220 Ω (rojo-rojo-negro-negro-marrón). Confirmar con el multímetro.
- [ ] La LILYGO no tiene pines soldados: por ahora uso cables **macho/macho**. (Opcional) Soldar tiras de pines.

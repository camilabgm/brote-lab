# Plantilla — Ficha de placa

Ruta: `placas/<marca-modelo-revision>.md`, en minúsculas con guiones (por ejemplo `placas/lilygo-t3-v1.6.1.md`).
Fuentes: `placas/datasheets/`. Todo dato sin fuente confirmada lleva *(a confirmar)*.

```markdown
# Nombre de la placa — Revisión

**Chip principal:** ...
**Voltaje lógico:** 3,3 V / 5 V
**Conversor USB-serie:** ... (define el driver y el cable)
**Configuración en el IDE:** placa, revisión, core y versión
**Fuentes:** enlaces a `datasheets/`

## 1. Anatomía

| Parte | Para qué sirve | Cómo habla con el microcontrolador | Pines |
|---|---|---|---|

## 2. Pines reservados (no usar)

| Pines | Ocupados por | Fuente |
|---|---|---|

## 3. Pines con cuidado

| Pin | Qué tiene de especial |
|---|---|
(arranque, solo entrada, sin pull-up interno, ADC que no anda con WiFi, etc.)

## 4. Pines libres

| Pin | Capacidades | Probado |
|---|---|---|
(digital E/S, ADC1/ADC2, PWM, táctil… "Probado" = sesión en la que funcionó)

## 5. Historial de uso

| Sesión | Pin | Para qué | Resultado |
|---|---|---|---|

## 6. Mañas y errores conocidos

| Síntoma | Causa | Solución |
|---|---|---|
```

# Plantilla — Preparación de sesión

Se entrega en la conversación (no se guarda como archivo). El objetivo y los materiales después pasan al encabezado de la bitácora.

```markdown
# Sesión NN — Título (según el cronograma)

**Placa:** nombre y revisión (ficha: `placas/<placa>.md`)
**Rama sugerida:** `sesion-NN-descripcion`
**Objetivo:** una frase con algo observable ("que el LED se prenda al tocar GND con el cable").
**Concepto nuevo:** uno solo.
**Retomamos de la sesión anterior:** lo pendiente que entra hoy, o "nada".

## 1. Anatomía
Qué es el componente nuevo, qué partes tiene y cómo se comunica con el microcontrolador.
Si no hay componente nuevo, qué parte de la placa se estudia hoy.

## 2. Materiales
| Material | Cantidad | ¿Lo tengo? | Nota |
|---|---|---|---|

⚠️ Faltantes o sin confirmar, y su alternativa.

## 3. Pines
| Pin | Uso hoy | Modo | Por qué este pin |
|---|---|---|---|

## 4. Conexiones
Tabla de conexiones + recorrido eléctrico (ver "Diagramas" en SKILL.md).

## 5. Pasos
1. ...
(Cada paso con su porqué. El código va después de entender qué va a pasar en el hardware.)

## 6. Listo cuando
Qué tiene que verse o medirse para dar el objetivo por cumplido.

## 7. Qué puede salir mal
Los errores más probables y cómo diagnosticarlos, incluidos los que ya pasaron en sesiones anteriores
(Debug en vez de Upload, puerto no elegido, cable solo de carga, cables hembra en la protoboard).
```

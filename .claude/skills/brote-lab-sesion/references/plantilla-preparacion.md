# Plantilla — Preparación de sesión

Se entrega en la conversación (no se guarda como archivo). El objetivo y los materiales después pasan al encabezado de la bitácora.

**Al arrancar se entrega solo el resumen corto (secciones 1 a 4).** Las secciones 5 a 8 son la guía de Claude: los pasos se mandan **de a uno** durante la sesión, esperando la confirmación de Cami antes del siguiente, y las conexiones van dentro del paso en que se arma el circuito.

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

## 4. Riesgos
- **Para la placa y los componentes:** qué conexión o qué error de código los puede dañar hoy (salida unida directo a GND, 5 V en un GPIO, metal suelto entre pines, LoRa sin antena, estática) y cómo se evita.
- **Para Cami:** si hay alguno. Con 3,3 V y 5 V, no; sí con 220 V del enchufe o baterías de litio en cortocircuito.

## 5. Conexiones
Primero preguntar qué protoboard (grande o mini). Conexiones por filas y columnas con orientación y punto de partida, sin coordenadas tipo "10c" + recorrido eléctrico (ver "Diagramas" en SKILL.md).

## 6. Pasos (se mandan de a uno)
1. ...
(Cada paso con su porqué y la fuente de cada dato. El código va después de entender qué va a pasar en el hardware.)
(Después de cada paso, preguntar si tiene dudas antes de mandar el siguiente.)
(Con el circuito armado y antes de subir el código: foto de la protoboard en `imagenes/sesion-NN/` para verificar las conexiones.)

## 7. Listo cuando
Qué tiene que verse o medirse para dar el objetivo por cumplido.

## 8. Qué puede salir mal
Los errores más probables y cómo diagnosticarlos, incluidos los que ya pasaron en sesiones anteriores
(Debug en vez de Upload, puerto no elegido, cable solo de carga, cables hembra en la protoboard,
subida que no terminó y sigue corriendo el programa anterior, pin de la placa que se hunde al poner la hembra).
```

---
name: brote-lab-sesion
description: Flujo de las sesiones de Brote Lab, el laboratorio de microcontroladores e IoT de Cami (ESP32/LILYGO, Arduino, sensores, LoRa). Úsala siempre que Cami quiera arrancar o preparar una sesión ("arrancamos la sesión 3", "¿qué toca hoy?", "preparemos la próxima"), cerrarla ("cerremos", "hagamos la bitácora", "terminé por hoy"), usar una placa de desarrollo nueva ("vamos a usar la TTGO 915", "conecté el Mega", "te paso el datasheet") o decidir qué pin conectar, aunque no nombre la skill. Lee el cronograma y la ficha de la placa del repo brote-lab, arma el plan con materiales, pines validados y el diagrama de conexiones, y al cerrar escribe la bitácora y actualiza cronograma, README y ficha de placa.
---

# Sesiones de Brote Lab

Brote Lab es el laboratorio de Cami para re-aprender hardware y redes. Las sesiones duran 60–90 minutos y tienen un objetivo concreto. Esta skill existe para que **ningún paso se repita a mano** y para que el conocimiento sobre cada placa **se acumule** en vez de quedar enterrado en bitácoras viejas.

Antes de nada, leé el `CLAUDE.md` del repo si no lo tenés en contexto: ahí están las reglas de explicación (anatomía primero, el porqué antes del código, sin analogías cotidianas) y las de Git. Esta skill las da por sabidas.

## Dónde leer y dónde escribir

El repo `brote-lab` es la única fuente de verdad (`github.com/camilabgm/brote-lab`).

- **En Claude Code, o con la carpeta del repo conectada:** leé y escribí los archivos directamente.
- **En un chat sin acceso de escritura al repo:** leé los archivos desde el proyecto (sincronizado con GitHub). Entregá cada archivo nuevo o modificado completo, con su ruta exacta, listo para que Cami lo pegue o lo pase a Code. Decí qué archivos cambian.

Archivos que usa la skill:

| Archivo | Para qué |
|---|---|
| `cronograma.md` | Qué sesión toca, sus conceptos y componentes, inventario, pendientes de confirmar |
| `placas/<placa>.md` | Pines reservados, libres y usados de cada placa. **Se consulta antes de proponer cualquier pin** |
| `bitacora/` | Las sesiones anteriores, para retomar lo que quedó pendiente |
| `README.md` | Tabla de sesiones |

Elegí el flujo según lo que pida Cami. Si llega una placa nueva en medio de la preparación, hacé primero el flujo de placa nueva.

---

## Flujo A — Placa de desarrollo nueva

Se activa cuando aparece una placa que no tiene ficha en `placas/`. Las fichas existen porque cada placa tiene pines que el fabricante ya conectó a algo (pantalla, radio, microSD, LED) y otros que se comportan raro al arrancar. Si eso no está escrito en un lugar fijo, se redescubre en cada sesión.

1. **Pedí la fuente.** Pedile a Cami el datasheet, la imagen del pinout del fabricante o una foto de la placa (las dos caras si se puede). Identificá también la **revisión exacta** (por ejemplo V1.6.1), porque entre revisiones cambian las conexiones internas. Guardá los PDF o imágenes en `placas/datasheets/`.
2. **No inventes pines.** Todo pin reservado tiene que salir del datasheet, del pinout del fabricante o de algo comprobado en una sesión. Si no se puede confirmar, va con la marca *a confirmar*. Un pin mal marcado como libre puede hacer perder una sesión entera.
3. **Armá la ficha** con la plantilla de `references/plantilla-ficha-placa.md`. El orden importa: primero la anatomía (qué chips tiene y cómo se comunican), después los pines.
4. **Explicale la ficha a Cami** antes de usarla: qué partes tiene la placa y por qué esos pines están ocupados. Esa explicación es parte del aprendizaje, no un trámite.
5. Si la placa no está en el inventario del `cronograma.md`, agregala.

---

## Flujo B — Preparar una sesión

El objetivo es que Cami llegue a la protoboard sabiendo qué va a conectar, dónde y por qué, sin descubrir a mitad de sesión que falta un cable o que el pin estaba ocupado.

1. **Ubicá la sesión.** En el `cronograma.md` buscá la primera sesión sin ✅, o la que Cami nombre. Revisá la última bitácora: lo que quedó en *Pendientes* o en *Quedó para después* puede entrar en esta sesión si está relacionado.
2. **Leé la ficha de la placa** que se va a usar. Si no existe, hacé antes el Flujo A.
3. **Revisá los materiales** contra el inventario y contra *Pendientes de confirmar*. Avisá claramente si falta algo o si hay algo sin confirmar que afecta la sesión (un multímetro prestado, una resistencia de valor dudoso, una frecuencia sin verificar). Proponé una alternativa si existe.
4. **Elegí los pines.** Cada pin propuesto se valida contra la ficha: tiene que estar libre, ser apto para lo que se va a hacer (entrada, salida, analógico, con o sin pull-up interno) y no ser especial al arrancar. Explicá en una línea por qué ese pin y no otro. Preferí reutilizar pines que ya funcionaron en sesiones anteriores, salvo que la sesión necesite otro tipo de pin.
5. **Dibujá las conexiones** (ver *Diagramas* más abajo).
6. **Entregá el plan** con la plantilla de `references/plantilla-preparacion.md`.
7. **Rama de Git:** proponé `sesion-NN-descripcion` (dos dígitos, descripción corta en minúsculas con guiones, como `sesion-02-salidas-digitales`). En Code, ofrecé crearla y esperá la confirmación antes de ejecutar.

Mientras dure la sesión vale lo del `CLAUDE.md`: anatomía primero, el porqué antes del código, un concepto nuevo, cortar si aparece la frustración.

**Verificación con foto:** cuando Cami termine de armar el circuito y antes de subir el código, pedile una foto de la protoboard (guardada en `imagenes/sesion-NN/` y pasada por ruta). Compará cable por cable contra la tabla de conexiones: número y letra de cada punta, orientación de los componentes con polaridad, que ninguna pieza tenga las dos patas en el mismo grupo. Un cable corrido un agujero es el error más común y el más difícil de ver desde el código.

---

## Flujo C — Cerrar una sesión

1. **Primero, las palabras de Cami.** Antes de escribir nada, preguntale:
   - ¿Qué aprendiste hoy?
   - ¿Qué te confundió o te quedó flojo?

   Esperá la respuesta. Va primero porque escribir la bitácora por ella le quitaría el ejercicio de reconstruir lo aprendido, y porque lo que la confundió es justo lo que la bitácora tiene que explicar mejor. Puede contestar por voz y de forma desordenada: ordená sin cambiarle el sentido.
2. **Escribí la bitácora** en `bitacora/AAAA-MM-DD-sesion-NN.md` con la plantilla de `references/plantilla-bitacora.md`:
   - La sección *En mis palabras* lleva lo que dijo Cami, ordenado pero en su voz.
   - Cada cosa que la confundió tiene que tener su explicación clara en *Conceptos*, o quedar en *Pendientes* si no hubo tiempo.
   - Los problemas van como **problema → diagnóstico → solución**. El diagnóstico (cómo se llegó a la causa) es lo que más sirve la próxima vez.
3. **Actualizá el resto del repo:**
   - `cronograma.md`: estado de la sesión en `✅ DD/MM`, y lo que haya quedado sin ver entre paréntesis (por ejemplo `✅ 10/11 (falta millis())`). Marcá los *Pendientes de confirmar* que se hayan resuelto. Si cambió el inventario, actualizalo.
   - `README.md`: agregá la fila de la sesión con los enlaces a la bitácora y al firmware.
   - `placas/<placa>.md`: agregá al *Historial de uso* los pines usados y para qué. Si se descubrió algo nuevo de la placa (un pin que no anda, una maña del IDE), sumalo a la ficha. Así la ficha crece con cada sesión.
4. **Fotos:** revisá que las fotos de la sesión estén en `imagenes/sesion-NN/` con los nombres que enlaza la bitácora. Si alguna se pasó por fuera (arrastrada a Code o compartida en el chat) y no está guardada, recordale guardarla ahí.
5. **Git:** mostrá la lista de archivos que cambiaron y proponé el mensaje de commit con este estilo: `Sesión NN: tema (resumen corto de lo logrado)`. **No hagas commit, push ni merge** hasta que Cami lo diga. Cuando lo diga, el orden es commit en la rama de la sesión → merge a `main` → push.

---

## Diagramas de conexiones

Los diagramas existen para que Cami pueda armar el circuito sin interpretar. Por eso usan **las letras y números impresos en la protoboard**, nunca "fila" o "columna" a secas, que dependen de cómo esté girada.

Recordatorio de la mecánica (mini protoboard de 170 puntos): cada grupo de 5 agujeros perpendicular al canal central está unido por dentro (por ejemplo, `10a–10e` es un solo nodo eléctrico, y `10f–10j` es otro). Las dos patas de un mismo componente nunca van en el mismo grupo. Dos componentes que se conectan entre sí comparten grupo.

**En Claude Code**, dos partes en texto:

1. Una tabla de conexiones, en el orden en que se arman:

   | # | Desde | Hasta | Cable / componente | Nota |
   |---|---|---|---|---|
   | 1 | Placa IO4 | 10a | Dupont M/M | Pin libre según la ficha |
   | 2 | 10c | 14c | Resistencia 220 Ω | Sin polaridad |
   | 3 | 14d | 16d | LED (largo en 14d, corto en 16d) | Pata larga = ánodo (+) |
   | 4 | 16a | Placa GND | Dupont M/M | Cierra el circuito |

2. Un recorrido del camino eléctrico en una línea, para verificar que el circuito cierra:

   ```
   IO4 → [10] → resistencia → [14] → LED (+ → −) → [16] → GND
   ```

**En el chat**, además del texto, un dibujo visual de la protoboard con los mismos números.

Antes de entregar cualquier diagrama, verificá: que ningún componente tenga las dos patas en el mismo grupo, que el circuito vuelva a GND, que los componentes con polaridad estén orientados y que ningún GPIO del ESP32 reciba 5 V.

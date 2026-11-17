# Brote Lab — instrucciones para Claude

Este es el laboratorio personal de **Cami** (Ing. Camila Guerrero, Ingeniera en Sistemas). Acá re-aprende microcontroladores, sensores, redes e IoT de punta a punta. La meta es construir **Brote #001**, un monitor de plantas, y prepararse para los proyectos IoT del PTI: monitoreo de gas y alumbrado con LoRaWAN.

- **Nivel:** principiante-intermedio en hardware y redes. Sólida en software (Next.js, React, Prisma, PostgreSQL, Git).
- **Idioma:** español. Ella habla informal; la documentación del repo se escribe prolija.
- **Dictado por voz:** usa mucho voz a texto. Si una palabra no tiene sentido, interpretá lo que quiso decir; si cambia algo importante, preguntá.

## Dónde está cada cosa

Este repo es la **única fuente de verdad**. El proyecto de claude.ai lee estos mismos archivos desde GitHub, así que cualquier cambio se hace acá. Ojo: no hay que contar con que el proyecto se sincronice solo. **Después de cada push, sincronizalo vos** desde el navegador integrado: proyecto Brote Lab → **Contexto** → menú **⋯** del repo → **Sincronizar ahora** (detalle en el paso 6 del cierre de la skill). Si claude.ai pide iniciar sesión, pedile a Cami que entre; si no hay navegador, recordale que lo haga ella.

| Ruta | Qué tiene |
|---|---|
| `cronograma.md` | Plan de sesiones, inventario de componentes y pendientes de confirmar |
| `placas/<placa>.md` | Una ficha por placa de desarrollo: anatomía, pines reservados y libres, historial de uso, mañas |
| `placas/datasheets/` | Datasheets y pinouts del fabricante |
| `bitacora/AAAA-MM-DD-sesion-NN.md` | Una nota por sesión |
| `firmware/NNN-Placa-descripcion/` | Un sketch de Arduino por sesión |
| `imagenes/sesion-NN/` | Fotos de los circuitos de cada sesión |
| `.claude/skills/brote-lab-sesion/` | La skill para preparar sesiones, cerrarlas y dar de alta placas nuevas |

## Cómo explicar

1. **Anatomía primero.** Antes de cualquier práctica con un componente nuevo: qué es, qué partes tiene y cómo se comunica con el microcontrolador.
2. **El porqué antes del código.** Cada paso se explica antes de hacerlo. El código viene después de entender qué va a pasar en el hardware.
3. **El mecanismo real, con términos precisos.** Nada de analogías con casas, calles u objetos cotidianos: la confunden más. Si hace falta, se explica qué pasa eléctricamente o en el protocolo.
4. **Un concepto nuevo por sesión.** Si aparece otro, se anota en pendientes en vez de abrirlo ahí mismo.
5. **Cortar a tiempo.** Las sesiones duran 60–90 minutos. Se corta cuando la confusión se convierte en frustración, no cuando se termina el horario. Si se nota eso, proponé cerrar y dejarlo anotado.
6. **Primero en sus palabras, después lo técnico.** Cuando Cami explica algo como lo entendió, respondé primero en su lenguaje: si está bien, confirmáselo así; si no, decile qué no es. Recién después pasá a la explicación técnica o la corrección.
7. **Respuestas cortas.** Cubrí todas sus dudas, pero sin profundizar de más: el exceso de detalle la frustra. Si algo merece más profundidad, ofrecelo en vez de darlo de entrada.
8. **Un paso por mensaje durante la sesión.** Mandá un paso, esperá a que lo haga o lo confirme, y recién ahí el siguiente. Nunca el plan entero de golpe.

## Antes de tocar un pin

Antes de proponer cualquier conexión, **leé la ficha de la placa** en `placas/`. Ahí está qué pines están ocupados por la propia placa (OLED, LoRa, microSD, etc.), cuáles son especiales al arrancar y cuáles ya se usaron en sesiones anteriores. Si la placa no tiene ficha, se crea primero (ver la skill).

## Seguridad del hardware

- El ESP32 trabaja a **3,3 V**. Nunca conectar 5 V a un GPIO. Los Arduino Uno, Mega y Nano son de 5 V: ojo al mezclarlos.
- **Nunca transmitir por LoRa sin la antena conectada.** Puede dañar la radio.
- Verificar la frecuencia de cada radio LoRa antes de usarla (433 MHz vs 868/915 MHz).

## Git

- Cada sesión va en su propia rama: `sesion-NN-descripcion`.
- Podés **proponer y ejecutar** comandos de Git, pero **siempre pedí confirmación antes** de cada uno.
- **Commit, push y merge a `main` solo cuando Cami lo indique.** Proponé el mensaje de commit; no lo ejecutes por tu cuenta.

## Fotos

Claude Code puede ver fotos: Cami las arrastra a la ventana o, mejor, te pasa la ruta del archivo. El flujo preferido es que guarde la foto primero en su carpeta definitiva (`imagenes/sesion-NN/descripcion.jpeg`) y te diga "mirá `imagenes/sesion-NN/...`". Así la foto ya queda donde la bitácora la va a enlazar y lista para el commit.

- Si te pasa una foto que todavía no está en `imagenes/`, sugerí el nombre y la carpeta donde guardarla.
- Cuando el circuito esté armado, una foto sirve para **verificar las conexiones contra la tabla del plan antes de subir el código**: fijate en qué fila y columna de la protoboard está cada cable y cada pata, y si algo no coincide, decilo.
- Pegar con Ctrl+V en Windows a veces no funciona; arrastrar o dar la ruta siempre funciona.

## Diagramas de conexiones

- **Nada de coordenadas tipo "10c".** Las conexiones se describen con **filas y columnas**, diciendo siempre **cómo está apoyada la protoboard** y **desde dónde se cuenta** (por ejemplo: "con las líneas de alimentación a los costados, contando desde arriba, fila 5").
- **Antes de dar conexiones, preguntá qué protoboard va a usar.** Cami alterna dos:
  - **Grande:** con líneas de alimentación verticales a los costados; la del + y la del − están separadas. Puede que cada línea esté cortada a la mitad: si no está confirmado, preguntá.
  - **Mini (170 puntos):** sin líneas de alimentación.
- **En Claude Code:** las conexiones en texto (ver la skill).
- **En el chat:** además del texto, un dibujo visual.

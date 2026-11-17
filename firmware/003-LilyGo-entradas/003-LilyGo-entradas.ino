// Brote Lab — Sesión 3, paso 7: contar los cambios de IO4 para ver el rebote
// Circuito: IO4 → fila 6 → resistencia 220 Ω → fila 11 ← cable a GND (se mete y se saca a mano)
#define ENTRADA   4    // GPIO 4: el único digital libre en la T3 V1.6.1
#define LED_PLACA 25   // LED verde integrado, para ver la lectura sin mirar el monitor

int lecturaAnterior;          // La última lectura, para saber si cambió
unsigned long cambios = 0;    // Cuántas veces cambió la lectura desde que arrancó

void setup() {
  Serial.begin(115200);              // Serial Monitor a 115200
  pinMode(ENTRADA, INPUT_PULLUP);    // Pull-up interno: el pin queda en 3,3 V si nada lo baja
  pinMode(LED_PLACA, OUTPUT);
  lecturaAnterior = digitalRead(ENTRADA);
}

void loop() {
  int lectura = digitalRead(ENTRADA);   // Sin delay: el loop lee el pin miles de veces por segundo

  if (lectura != lecturaAnterior) {     // Solo cuando la lectura es distinta de la anterior
    cambios++;
    Serial.print("Cambio #");
    Serial.print(cambios);
    Serial.print(" -> ");
    Serial.println(lectura);
    lecturaAnterior = lectura;
  }

  if (lectura == 0) {
    digitalWrite(LED_PLACA, HIGH);      // Lee 0 → LED prendido
  } else {
    digitalWrite(LED_PLACA, LOW);       // Lee 1 → LED apagado
  }
}

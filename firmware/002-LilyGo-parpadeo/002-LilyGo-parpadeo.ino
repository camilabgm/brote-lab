// Brote Lab — Sesión 2: parpadeo del LED integrado y de un LED externo
// Circuito externo: IO4 → resistencia (≈220 Ω) → pata larga del LED; pata corta → GND
#define LED_PLACA   25   // LED verde integrado: el fabricante lo conectó al GPIO 25
#define LED_EXTERNO 4    // GPIO 4: libre en la T3 V1.6.1 y no es especial al arrancar

void setup() {
  pinMode(LED_PLACA, OUTPUT);    // Los dos pines van a ser SALIDAS
  pinMode(LED_EXTERNO, OUTPUT);
}

void loop() {
  digitalWrite(LED_PLACA, HIGH);    // 3,3 V → prendidos
  digitalWrite(LED_EXTERNO, HIGH);
  delay(500);                       // Medio segundo (bloquea: la placa no hace nada más)
  digitalWrite(LED_PLACA, LOW);     // 0 V → apagados
  digitalWrite(LED_EXTERNO, LOW);
  delay(500);
}

// Brote Lab — Sesión 1: "Hola Cami" en la pantalla OLED
#include <Wire.h>              // Librería para hablar I2C
#include <Adafruit_GFX.h>      // Sabe dibujar letras y formas
#include <Adafruit_SSD1306.h>  // Sabe hablar con el chip de la pantalla

#define ANCHO     128   // Píxeles de ancho de la pantalla
#define ALTO      64    // Píxeles de alto
#define OLED_SDA  21    // Pin de datos I2C en la LILYGO
#define OLED_SCL  22    // Pin de reloj I2C en la LILYGO
#define OLED_DIR  0x3C  // "Dirección de casa" de la pantalla

// Creamos el objeto "pantalla". -1 = no usamos pin de reset
Adafruit_SSD1306 pantalla(ANCHO, ALTO, &Wire, -1);

void setup() {
  Serial.begin(115200);  // Abrimos el canal hacia la computadora
  delay(500);
  Serial.println("Brote Lab: arrancando...");

  Wire.begin(OLED_SDA, OLED_SCL);  // Arrancamos I2C en los pines correctos

  // Intentamos conectar con la pantalla
  if (!pantalla.begin(SSD1306_SWITCHCAPVCC, OLED_DIR)) {
    Serial.println("ERROR: no encontre la pantalla OLED");
    while (true) { delay(1000); }  // Nos quedamos acá parados
  }

  pantalla.clearDisplay();               // Borramos lo que había
  pantalla.setTextColor(SSD1306_WHITE);  // Texto encendido (la OLED es monocromo)

  pantalla.setTextSize(2);               // Letra grande
  pantalla.setCursor(0, 10);             // Posición: x=0, y=10
  pantalla.println("Hola Cami");

  pantalla.setTextSize(1);               // Letra chica
  pantalla.setCursor(0, 45);
  pantalla.println("Brote Lab #001");

  pantalla.display();  // Recién acá se ve todo en la pantalla
  Serial.println("Pantalla lista!");
}

void loop() {
  // Por ahora nada se repite
}
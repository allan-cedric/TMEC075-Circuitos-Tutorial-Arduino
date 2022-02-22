/*
 * Pisca-pisca(Blink) com dois LEDs de forma alternada
 */

const uint8_t greenLedPin = 12; // pino de saída digital que o led verde está conectado
const uint8_t redLedPin = 13;   // pino de saída digital que o led vermelho está conectado

void setup() {
  pinMode(redLedPin, OUTPUT);   // declare o led como o output
  pinMode(greenLedPin, OUTPUT); // declare o led como o output
}

void loop() {
  digitalWrite(redLedPin, HIGH);  // liga o led
  digitalWrite(greenLedPin, LOW); // liga o led
  delay(1000);                    // espera 1000 milisegundos
  
  digitalWrite(redLedPin, LOW);   // desliga o led
  digitalWrite(greenLedPin, HIGH);// desliga o led
  delay(1000);                    // espera 1000 milisegundos
}

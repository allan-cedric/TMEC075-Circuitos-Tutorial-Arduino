/*
 * Pisca-pisca(Blink) com dois LEDs de forma alternada
 */

const uint8_t pinoLEDvd = 12; // pino de saída digital que o led verde está conectado
const uint8_t pinoLEDvm = 13; // pino de saída digital que o led vermelho está conectado

void setup() {
  pinMode(pinoLEDvm, OUTPUT); // declare o led como o output
  pinMode(pinoLEDvd, OUTPUT); // declare o led como o output
}

void loop() {
  digitalWrite(pinoLEDvm, HIGH);  // liga o led
  digitalWrite(pinoLEDvd, LOW);   // liga o led
  delay(1000);                    // espera 1000 milisegundos
  
  digitalWrite(pinoLEDvm, LOW);   // desliga o led
  digitalWrite(pinoLEDvd, HIGH);  // desliga o led
  delay(1000);                    // espera 1000 milisegundos
}

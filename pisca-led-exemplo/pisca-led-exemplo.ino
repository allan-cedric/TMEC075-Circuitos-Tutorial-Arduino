/*
 * Pisca-pisca(Blink) com um LED
 */

const uint8_t pinoLED = 13; // pino de saída digital que o led está conectado

void setup() {
  pinMode(pinoLED, OUTPUT); // declare o led como o output
}

void loop() {
  digitalWrite(pinoLED, HIGH);  // liga o led
  delay(1000);                  // espera 100 milisegundos
  digitalWrite(pinoLED, LOW);   // desliga o led
  delay(1000);                  // espera 100 milisegundos
  
  /* while(1) { //entra num loop de while 1.
  //Como 1 nunca muda, o programa nunca sai desse loop
  //não faça nada aqui
  }
  //o programa está preso no while(1)
  //então nunca chegará a este ponto */
}

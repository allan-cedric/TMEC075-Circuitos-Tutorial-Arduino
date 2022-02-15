const uint8_t pinoLED = 2; // Pino digital 2
const int delayLED = 1000; // Tempo que o LED estará ligado ou desligado(em ms)

void setup() {
  // put your setup code here, to run once:
  
  pinMode(pinoLED, OUTPUT); // Define a porta do LED como saída digital
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(pinoLED, HIGH); // Liga o LED
  delay(delayLED);             // Espera delayLED milissegundos
  digitalWrite(pinoLED, LOW);  // Desliga o LED
  delay(delayLED);             // Espera delayLED milissegundos
}

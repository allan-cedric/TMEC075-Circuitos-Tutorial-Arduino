/*
 * Teste de leitura do sensor óptico TCRT5000
 */

const uint8_t pinoSensor = 8; // inicializa o pino dig 8 para o sensor
const uint8_t pinoLed = 12;   // inicializa o pino dig 12 para o LED

void setup(){
  pinMode(pinoSensor, INPUT); // define sensor como entrada
  pinMode(pinoLed, OUTPUT);   // define LED como saída
  digitalWrite(pinoLed, LOW); // inicia LED desligado
}

void loop(){
  // se o sensor estiver em low, liga o LED
  if (digitalRead(pinoSensor) == LOW){ // (com reflexão)
    digitalWrite(pinoLed, HIGH);
  }
  // se o sensor estiver em high, desliga o LED
  else{ // (sem reflexão)
    digitalWrite(pinoLed, LOW); // apaga O LED
  }
}

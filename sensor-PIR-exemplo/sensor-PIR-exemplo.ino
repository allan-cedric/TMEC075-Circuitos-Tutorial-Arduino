/*
 * Teste simples de leitura do sensor de movimento PIR
 */

const uint8_t pirPin = 2;  // pino de entrada do sensor
const uint8_t ledPin = 12; // pino de saída do LED

uint8_t state = LOW;  // sem movimento como default
uint8_t val = 0;      // variável auxiliar

void setup() {
  pinMode(ledPin, OUTPUT);  // inicializa o LED como uma saída
  pinMode(pirPin, INPUT);   // inicializa o sensor como uma entrada
  Serial.begin(9600);       // inicializa a serial
}

void loop(){
  val = digitalRead(pirPin); // leitura do sinal do sensor
  //delay(1000);
  
  if (val != state){ // se o sinal do sensor é diferente do guardado
    // tem movimento!
    digitalWrite(ledPin, HIGH); // liga o LED
    delay(500);
  }else{ // se não, não tem movimento!
    digitalWrite(ledPin, LOW); // desliga o LED
  }
  
  state = val;  // atualiza a variável de estado para detectar
                // o próximo movimento.
}

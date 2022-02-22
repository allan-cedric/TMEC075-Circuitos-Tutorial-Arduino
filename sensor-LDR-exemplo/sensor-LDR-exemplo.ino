/*
 * Teste de sensor de luminosidade LDR
 */

const uint8_t ledPin = 7;   // inicia o LED no pino digital 7
const uint8_t ldrPin = A0;  // inicia o LDR no pino analógico A0

int ldrVal = 0; // inicia variável de valor lido do LDR

void setup() {
  pinMode(ledPin,OUTPUT); // define a saída do LED
  pinMode(ldrPin,INPUT);  // define o sensor como entrada
  Serial.begin(9600);     // inicia a comunicação serial
}

void loop() {
  // loop para ler o valor do LDR
  ldrVal = analogRead(ldrPin); // repare! Usamos analogRead!
  
  // o valor lido será entre 0 e 1023 -> limite do sensor
  // se o valor lido for maior que 950, liga o led -> valor configurável(threshold)
  if (ldrVal>= 950) digitalWrite(ledPin,HIGH);
  else digitalWrite(ledPin,LOW);
  
  // imprime o valor lido do LDR no monitor serial
  Serial.println(ldrVal);
  delay(100);
}

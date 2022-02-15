const uint8_t pinoLED = 2; // Pino digital 2
const uint8_t pinoPIR = 3; // Pino digital 3

void setup() {
  // put your setup code here, to run once:

  pinMode(pinoLED, OUTPUT); // Define a porta do LED como saída digital
  pinMode(pinoPIR, INPUT);  // Define a porta do PIR como entrada digital
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(digitalRead(pinoPIR) == HIGH) // Sensor PIR detectou algo ?
  {
    digitalWrite(pinoLED, HIGH);   // Então liga o LED
    delay(8000);                   // Espera por uma nova leitura do sensor
  }
  else
    digitalWrite(pinoLED, LOW);    // Senão desliga o LED
   
}

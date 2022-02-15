const uint8_t pinoLED = 2;  // Pino digital 2
const uint8_t pinoLDR = A0; // Pino analógico A0

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);       // Inicializa o monitor serial

  pinMode(pinoLED, OUTPUT); // Define a porta do LED como saída digital
  pinMode(pinoLDR, INPUT);  // Define a porta do LDR como entrada analógica
}

void loop() {
  // put your main code here, to run repeatedly:

  int valorLDR = analogRead(pinoLDR); // Lê o sensor LDR

  if(valorLDR <= 150)           
    digitalWrite(pinoLED, HIGH); // Liga o LED
  else
    digitalWrite(pinoLED, LOW);  // Desliga o LED

  // Imprime no monitor serial o valor lido pelo LDR
  Serial.print("Valor LDR: ");
  Serial.println(valorLDR);
  delay(100);
}

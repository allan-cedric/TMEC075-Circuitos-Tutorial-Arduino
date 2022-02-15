const uint8_t pinoEcho = 4; // Pino digital 4
const uint8_t pinoTrig = 5; // Pino digital 5

long duracao;  // Duração de um pulso digital
int distancia; // Distância detectada pelo sensor

void setup() {
  Serial.begin(9600);
  pinMode(pinoEcho, INPUT);   // Define a porta do Echo como entrada digital    
  pinMode(pinoTrig, OUTPUT);  // Define a porta do Trigger como saída digital  
}
void loop() {
  // Limpa o sinal do Trigger
  digitalWrite(pinoTrig, LOW);
  delayMicroseconds(5);

  // Faz um pulso de 10us
  digitalWrite(pinoTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTrig, LOW);

  // Duração do pulso recebido pelo Echo
  duracao = pulseIn(pinoEcho, HIGH);

  // Calcula a distância(cm) em relação ao objeto
  distancia = duracao * 0.034 / 2;
  
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println("cm");
  delay(100);
}

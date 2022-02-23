/*
 * Teste de leitura do sensor ultrassônico HC-SR04 com LED
 * 
 * REQUISITOS: Biblioteca Ultrasonic -> https://github.com/filipeflop/Ultrasonic
 * Passos: Baixar o ZIP(Aba Code) -> Sketch -> Incluir Biblioteca -> Adicionar biblioteca .ZIP
 */

//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>

//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

//Inicializa o pino em que o LED está conectado
int led = 9;

void setup()
{
  pinMode(led, OUTPUT); //Inicializa o LED como saída
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}

void loop()
{
  //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  Serial.print(" - Distancia em polegadas: ");
  Serial.println(inMsec);
  delay(100);
  
  if (cmMsec <= 10){ //Se a distância medida for menor que 10cm
    digitalWrite(led, HIGH); //Liga o LED
    delay(200); //Espera 200ms
  }else{ //Se a medida for maior que 10cm
    digitalWrite(led, LOW); //Desliga o LED
  }
}

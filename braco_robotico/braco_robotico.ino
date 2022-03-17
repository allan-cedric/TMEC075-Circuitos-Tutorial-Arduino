#include <Servo.h>

int tolerancia = 10;

const uint8_t servoPinoGarra = 7;
const uint8_t servoPinoDir = 6;
const uint8_t servoPinoEsq = 5;
const uint8_t servoPinoBase = 4;

const uint8_t potGarra = A3;
const uint8_t potEsq = A2;
const uint8_t potDir = A1;
const uint8_t potBase = A0;

int lastPotGarra;
int lastPotEsq;
int lastPotDir;
int lastPotBase;

Servo servoGarra, servoDir, servoEsq, servoBase;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(potGarra, INPUT);
  pinMode(potEsq, INPUT);
  pinMode(potDir, INPUT);
  pinMode(potBase, INPUT);
  
  servoGarra.attach(servoPinoGarra);
  servoDir.attach(servoPinoDir);
  servoEsq.attach(servoPinoEsq);
  servoBase.attach(servoPinoBase);

  servoGarra.write(180);
  servoDir.write(60);
  servoEsq.write(120);
  servoBase.write(0);

  delay(300);

  servoGarra.detach();
  servoDir.detach();
  servoEsq.detach();
  servoBase.detach();

  lastPotGarra = map(analogRead(potGarra), 0, 1023, 0, 180);
  lastPotEsq = map(analogRead(potEsq), 0, 1023, 0, 180);
  lastPotDir = map(analogRead(potDir), 0, 1023, 0, 180);
  lastPotBase = map(analogRead(potBase), 0, 1023, 0, 180);

//  while(1);
}

void loop() {
  // put your main code here, to run repeatedly:

  int potGarraValor = map(analogRead(potGarra), 0, 1023, 0, 180);
  int potEsqValor = map(analogRead(potEsq), 0, 1023, 0, 180);
  int potDirValor = map(analogRead(potDir), 0, 1023, 0, 180);
  int potBaseValor = map(analogRead(potBase), 0, 1023, 0, 180);

  Serial.print(potGarraValor);
  Serial.print(' ');
  Serial.print(potEsqValor);
  Serial.print(' ');
  Serial.print(potDirValor);
  Serial.print(' ');
  Serial.println(potBaseValor);
  delay(50);

  if(abs(lastPotGarra - potGarraValor) > tolerancia)
  {
    servoGarra.attach(servoPinoGarra);
    servoGarra.write(potGarraValor);
    delay(300);
    servoGarra.detach();
    lastPotGarra = potGarraValor;
  }
  else if(abs(lastPotDir - potDirValor) > tolerancia)
  {
    servoDir.attach(servoPinoDir);
    servoDir.write(potDirValor);
    delay(300);
    servoDir.detach();
    lastPotDir = potDirValor;
  }
  else if(abs(lastPotEsq - potEsqValor) > tolerancia)
  {
    servoEsq.attach(servoPinoEsq);
    servoEsq.write(potEsqValor);
    delay(300);
    servoEsq.detach();
    lastPotEsq = potEsqValor;
  }
  else if(abs(lastPotBase - potBaseValor) > tolerancia)
  {
    servoBase.attach(servoPinoBase);
    servoBase.write(potBaseValor);
    delay(300);
    servoBase.detach();
    lastPotBase = potBaseValor;
  }
}

#include <Servo.h>

int tolerancia = 20;

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

  lastPotGarra = map(analogRead(potGarra), 0, 1023, 180, 150);
  lastPotEsq = map(analogRead(potEsq), 0, 1023, 0, 180);
  lastPotDir = map(analogRead(potDir), 0, 1023, 0, 180);
  lastPotBase = map(analogRead(potBase), 0, 1023, 0, 180);

//  while(1);
}

void loop() {
  // put your main code here, to run repeatedly:

  int potGarraValor = map(analogRead(potGarra), 0, 1023, 180, 150);
  int potEsqValor = map(analogRead(potEsq), 0, 1023, 0, 180);
  int potDirValor = map(analogRead(potDir), 0, 1023, 0, 180);
  int potBaseValor = map(analogRead(potBase), 0, 1023, 0, 180);

//  Serial.print("garra: ");
//  Serial.print(potGarraValor);
//  Serial.print("  esq: ");
//  Serial.print(potEsqValor);
//  Serial.print("  dir: ");
//  Serial.print(potDirValor);
//  Serial.print("  base: ");
//  Serial.println(potBaseValor);
  delay(50);

  if(abs(lastPotGarra - potGarraValor) > tolerancia)
  {
    servoGarra.attach(servoPinoGarra);
    servoGarra.write(potGarraValor);
    lastPotGarra = potGarraValor;
  }
  else if(abs(lastPotDir - potDirValor) > tolerancia)
  {
    servoDir.attach(servoPinoDir);
    servoDir.write(potDirValor);
    lastPotDir = potDirValor;
  }
  else if(abs(lastPotEsq - potEsqValor) > tolerancia)
  {
    servoEsq.attach(servoPinoEsq);
    servoEsq.write(potEsqValor);
    lastPotEsq = potEsqValor;
  }
  else if(abs(lastPotBase - potBaseValor) > tolerancia)
  {
    servoBase.attach(servoPinoBase);
    servoBase.write(potBaseValor);
    lastPotBase = potBaseValor;
  }
}

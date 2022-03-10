#include <Servo.h>

const uint8_t servoPinoFrente = 7;
const uint8_t servoPinoDir = 5;

Servo servoFrente, servoEsq, servoDir;

void setup() {
  // put your setup code here, to run once:
  servoFrente.attach(servoPinoFrente);
  servoDir.attach(servoPinoDir);

  servoFrente.write(170);
  servoDir.write(90);
//  while(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 60; i <= 100; i++)
  {
    servoDir.write(i);
    delay(10);
  }
  delay(200);
  
  for(int i = 170; i >= 120; i--)
  {
    servoFrente.write(i);
    delay(10);
  }
  delay(200);

  for(int i = 120; i <= 170; i++)
  {
    servoFrente.write(i);
    delay(10);
  }
  delay(200);

  for(int i = 100; i >= 60; i--)
  {
    servoDir.write(i);
    delay(10);
  }
  delay(200);
}

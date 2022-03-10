#include <Servo.h>

const uint8_t servoPinoFrente = 7;
const uint8_t servoPinoDir = 5;

Servo servoFrente, servoEsq, servoDir;

void setup() {
  // put your setup code here, to run once:
  servoFrente.attach(servoPinoFrente);
  servoDir.attach(servoPinoDir);

  servoFrente.write(180);
  servoDir.write(40);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 40; i <= 100; i++)
  {
    servoDir.write(i);
    delay(10);
  }
  delay(200);
  
  for(int i = 180; i >= 100; i--)
  {
    servoFrente.write(i);
    delay(10);
  }
  delay(200);

  for(int i = 100; i <= 180; i++)
  {
    servoFrente.write(i);
    delay(10);
  }
  delay(200);

  for(int i = 100; i >= 40; i--)
  {
    servoDir.write(i);
    delay(10);
  }
  delay(200);
}

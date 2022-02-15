#include <Servo.h>

const uint8_t pinoServo = 6;
Servo servoMotor;

void setup() {
  // put your setup code here, to run once:
  
  servoMotor.attach(pinoServo);
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int pos = 0; pos <= 180; pos++)
  {
    servoMotor.write(pos);
    delay(5);
  }
  delay(1000);
  
  for(int pos = 180; pos >= 0; pos--)
  {
    servoMotor.write(pos);
    delay(5);
  }
  delay(1000);
}

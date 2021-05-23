#include <Servo.h>

Servo myservo;

void setup()
{
  myservo.attach(3, 500, 2500);
  myservo.write(0);
}

void loop(){
  myservo.write(90);
  delay(2000);
  myservo.write(180);
  delay(2000);
  myservo.write(0);
  delay(4000);
  
}

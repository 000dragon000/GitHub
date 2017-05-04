#include <Servo.h>
int pin1 = 8;
char b, a;
Servo s1, s2;

int pos = 1500;
void setup()
{
  Serial.begin(9600);
  s1.attach(pin1, 800, 2000);
  //s2.attach(pin2,1545,1646);

  //  delay(2000);
  //  s1.write(2000);
  //  delay(4000);
  //  s1.write(800);
  //  delay(2000);
}

void reverse()
{
  pos=Serial.parseInt();
  s1.writeMicroseconds(1500);
  s1.writeMicroseconds(pos);
  s1.writeMicroseconds(1500);
  s1.writeMicroseconds(pos);
}
void forward()
{
  pos=Serial.parseInt();
  s1.writeMicroseconds(pos);
}

void loop()
{

  while (Serial.available())
  {
   pos = Serial.parseInt();
    //b=Serial.read();
    
 if(pos>=1600)
    pos=1600;

    s1.write(pos);
//    delay(10);
    Serial.println(pos);
  }
}


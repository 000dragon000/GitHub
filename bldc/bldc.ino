#include <Servo.h>
int pin1 = 5 ;
char b = 'x';
Servo s1, s2;
int fwd, rev;
int f1, f2;

int pos = 1500;
void setup()
{
  Serial.begin(9600);
  s1.attach(pin1, 1500, 2000);
  //s2.attach(pin2,1545,1646);

  //  delay(2000);
  //  s1.write(2000);
  //  delay(4000);
  //  s1.write(800);
  //  delay(2000);


}

 
void loop()
{

  if (Serial.available())
  {

    pos = Serial.parseInt();
    //    b = Serial.read();
    //    if (b == 'y')
    //    {
    //      s1.writeMicroseconds(1500);
    //      delay(1);
    //      s1.writeMicroseconds(pos);
    //      delay(10);
    //      //      pos = pos - 10;
    //      //      s1.writeMicroseconds(pos);
    //      //     // s2.writeMicroseconds(pos);
    //      //      delay(10);
    ////    s1.writeMicroseconds(pos);
    ////    delay(10);
    //    }
    //    if (b == 'x')
    //    {
    //      s1.writeMicroseconds(pos);
    //      delay(10);
    //      //      pos = pos + 10;
    //      //      s1.writeMicroseconds(pos);
    //      //     // s2.writeMicroseconds(pos);
    //      //      delay(10);
    //      Serial.println("xyz");
    //    }
    //    Serial.println(b);
    s1.write(pos);
    delay(10);
    Serial.println(pos);
  }
}

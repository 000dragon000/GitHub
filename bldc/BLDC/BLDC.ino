#include <Servo.h>
int pin1 = 12;
char b, a;
Servo s1, s2;
int fwd, rev;
int s1, s2;

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
  s1=map(fwd, 1, 500, 1501, 2000);
  s2=map(rev, -1, -500, 1499, );

  while (Serial.available())
  {
//    pos = Serial.parseInt();
    b=Serial.read();
    
//    if(pos>=1590)
//     pos=1585;
//    b = Serial.read();
    
//    Serial.println(b);
    if (b == 'r')
    {
     reverse();
     }
    if(b=='f')
    {
      forward();
    }
      //      pos = pos + 10;
      //      s1.writeMicroseconds(pos);
      //     // s2.writeMicroseconds(pos);
      //      delay(10);//    }

//    if (b == 'y')
//    {
//      s1.writeMicroseconds(1500);
//      delay(10);
////      s1.writeMicroseconds(pos);
////      delay(10);
//      //      pos = pos - 10;
//      //      s1.writeMicroseconds(pos);
//      //     // s2.writeMicroseconds(pos);
//      //      delay(10);
//    }
    s1.write(pos);
//    delay(10);
    Serial.println(pos);
  }
}


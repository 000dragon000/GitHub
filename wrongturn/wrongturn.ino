#include <Servo.h>
int pht_swt = 20;
int o_p=0;
Servo myservo;
float def = 64;
float angle;
float wangle;
void setup() 
{
  pinMode(2,OUTPUT);
  pinMode(pht_swt,INPUT);
  myservo.attach(2);
  Serial.begin(115200);
  delay(1);
  angle = def;
  wangle = def;
}
float prev_angle = def;
float k = 0.95;
int f=0;
void loop()
{
  
o_p=digitalRead(pht_swt);
//Serial.println(o_p);
delay(1);
if(o_p==1&&f==0)
{
  angle=def;
}
else
{
  angle=def+78;f++;
}
wangle = prev_angle * k + angle*(1-k);
myservo.write((int)wangle);
prev_angle = wangle;
//Serial.println((int)wangle);
delay(10);
}

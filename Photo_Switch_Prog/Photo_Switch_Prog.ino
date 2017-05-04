#include <Servo.h>
int pht_swt = 20;
int o_p=0;
Servo myservo;
float def = 64;
float angle;
float w_angle;
void setup() 
{
  pinMode(2,OUTPUT);
  pinMode(pht_swt,INPUT);
  myservo.attach(2);
  Serial.begin(115200);
  delay(1);
  angle = def;
  w_angle = def;
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
w_angle = prev_angle * k + angle*(1-k);
myservo.write((int)w_angle);
prev_angle = w_angle;
//Serial.println((int)w_angle);
delay(10);
}

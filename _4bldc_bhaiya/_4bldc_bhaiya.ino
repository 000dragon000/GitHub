#define MIN 100
#define MAX 4000
#include <Servo.h>
Servo ESC;
Servo ESC2;
Servo ESC3;
Servo ESC4;
//int trig=8;
//int echo=10;
//--
void setup() {
  // put your setup code here, to run once:
  ESC.attach(5);//,900,2000);
  ESC.writeMicroseconds(1500);
  delay(100);
  ESC2.attach(7);//,900,2000);
  ESC2.writeMicroseconds(2000);
  delay(1);
  ESC3.attach(6);
  ESC3.writeMicroseconds(1500);
   ESC4.attach(4);
  ESC4.writeMicroseconds(1500);
  Serial.begin(115200);
  //delay(3000);
  //pinMode(trig,OUTPUT);
  //pinMode(echo,INPUT);
}
int k = 0;
//int rpm=0;
//double u_dis=0;
//double u_time=0;
void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(trig,0);
  //delayMicroseconds(10);
  if (Serial.available())
  {
    char ch = Serial.read();
    if (ch == '+')
      k += 10;
    if (ch == '-')
      k -= 10;
    if (ch == '1')
      k = MIN;
    if (ch == '2')
      k = MAX;
    k = k < MIN ? 1100 : k;
    k = k > MAX ? MAX : k;
    ESC.writeMicroseconds(k);
     delay(100);
    ESC2.writeMicroseconds(k);
    delay(100);
      ESC3.writeMicroseconds(k);
    delay(1);
     ESC4.writeMicroseconds(k);
    delay(1);
  Serial.println(k);
  }
  //digitalWrite(trig, 1);
  //delayMicroseconds(10); 
  //u_time = pulseIn(echo, 1);
  //u_dis = (u_time/2) / 29.1;
//  Serial.print(" ");
//  Serial.print(u_time);
//  delayMicroseconds(10);
//Serial.println(k);
  //Serial.print(" ");
  //Serial.print(u_dis);
  //Serial.println(" cm");
  delayMicroseconds(10);
}

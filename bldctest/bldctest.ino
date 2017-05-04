#include<Servo.h>
Servo bldc;
//Servo bldc2;
int bldcpin = 12;//5,12
int bldc2p = 5;
//DONO 1600 PE START HOTA HAI
int val;
//int val2;
void setup() {
  // put your setup code here, to run once:
  bldc.attach(bldcpin,800,3000);
  delay(5);
  //bldc2.attach(bldc2p, 800, 2000);
  delay(5);
  Serial.begin(9600);
}
//int base = 600;
void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available())
  { val = Serial.parseInt();
    bldc.writeMicroseconds(val);
    delay(5);
   // bldc2.writeMicroseconds(val+10);
    delay(5);
  Serial.println(val);
  }
}




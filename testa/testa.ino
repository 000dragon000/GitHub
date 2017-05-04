#include<Wire.h>
void setup() {
Serial.begin(9600);
Wire.begin();
pinMode(18,INPUT_PULLUP);       // Control for Test1
    pinMode(19,INPUT_PULLUP);
//pinMode(2,OUTPUT);
//digitalWrite(2,HIGH);
}
byte error=0x00,address=0x00;
void loop() {
  // put your main code here, to run repeatedly:
Serial.println("HEy ....");
 Wire.beginTransmission(0x00);
    error = Wire.endTransmission();
       Serial.println(error);
  
delay(100);
}

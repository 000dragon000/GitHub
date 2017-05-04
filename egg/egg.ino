int encA=30;
int encB=31;
int count=0;
void setup() {
 Serial.begin(9600);
 Serial3.begin(9600);
  attachInterrupt(digitalPinToInterrupt(encA),enc,RISING); }
 void enc()
 {if (digitalRead(encB))
 count++;
 else
 count--;
 }
void loop(){
Serial.println(count);
   Serial3.write(0);
  }

int rgb[]={6,7,5,4};

void setup() {
 for(int i=0;i<3;i++)
 {pinMode(rgb[i],OUTPUT);
 }
 pinMode(2,OUTPUT);
 digitalWrite(2,HIGH);
 digitalWrite(rgb[0],HIGH);
}
void loop() {
  analogWrite(rgb[1],255); 
  analogWrite(rgb[2],255); 
  analogWrite(rgb[3],0);
  delay(500);
  analogWrite(rgb[1],255); 
  analogWrite(rgb[2],0); 
  analogWrite(rgb[3],255);
  delay(500);
  analogWrite(rgb[1],0); 
  analogWrite(rgb[2],255); 
  analogWrite(rgb[3],255);
  delay(500);
}

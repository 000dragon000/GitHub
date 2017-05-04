int led[]={A0,A2,A5,A9,52,51,48,47,45,43,41,10,8,7,4,15,17};
  int touch[]={A1,A3,A4,A8,53,50,49,46,44,42,40,11,9,6,5,14,16};
void setup() {
  Serial.begin(9600);  
  for(int i=0;i<17;i++)
  pinMode(led[i],OUTPUT);
  for(int i=0;i<17;i++)
  pinMode(touch[i],INPUT);
randomSeed(analogRead(15));

}
int count=0;
void loop() {
int r=random(0,16);while(!digitalRead(touch[r])){digitalWrite(led[r],HIGH);}count++;Serial.print("count :");Serial.print(count);Serial.print("  ");Serial.print(" TIME: ");Serial.print(millis()/1000);Serial.println(" s ");digitalWrite(led[r],LOW);delay(1);

//for(int i=0;i<17;i++)
//{digitalWrite(led[i],HIGH);
//digitalWrite(touch[i],HIGH);
//delay(500);
//digitalWrite(led[i],LOW);
//digitalWrite(touch[i],LOW);
//delay(500);
//}
}

int pins[]={7,2,5};//L L B
void setup() {
  for(int i=0;i<3;i++)
  pinMode(pins[i],OUTPUT);
}

void loop() {
  analogWrite(pins[0],50);
  delay(1000);
    analogWrite(pins[0],100);
    delay(1000);
}

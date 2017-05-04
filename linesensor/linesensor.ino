int pins[] = {22, 21, 20, 19, 18,17,16,15,14};
int data[]={0,0,0,0,0};
void setup() {
  for(int i=0;i<5;i++)
  pinMode(pins[i],INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=0;i<9;i++)
{ Serial.print(analogRead(pins[i]));Serial.print(" ");
  }
  Serial.println();
}

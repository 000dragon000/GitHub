int la = 13;
void setup() 
{
  // put your setup code here, to run once:
  pinMode(la, OUTPUT);
  analogWrite(la, 0);
  Serial.begin(9600);
}
int val;
int base;
void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available())
  { val = Serial.parseInt();
//    if(val==1)
//      base+=5;
    propLower(val);
    Serial.println(val);
    delay(5);
  }
}
void propLower(int p)
{
  if (p > 255)x
    p = 255;
  if (p < 0)
    p = 0;
  analogWrite(la, p);
  delay(5);
}

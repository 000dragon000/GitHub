int l[7] = {13, 24, 25, 27, 28, 29,26};
byte a;
void setup()
{
  for (int i = 0; i < 7; i++)  pinMode(l[i], INPUT);
  Serial.begin(115200);
}
void loop()
{
 for (int i = 0; i < 7; i++){ a = !digitalRead(l[i]);
    Serial.print(a);
    Serial.print(" ");}
    Serial.println();
  delay(10);
}

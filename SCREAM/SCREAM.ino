int l[7] = {22, 37, 24, 43, 3, 27, 29};
void setup() 
{
  Serial.begin(115200);
}

int a;
void loop() {
  for (int i = 0; i < 7; i++)
  {
    a = !digitalRead(l[i]);
    Serial.print(a);
  }



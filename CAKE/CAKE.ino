

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
}
int p = 50;
void loop() {
  MA(p);
  delay(1);
  MB(p);
  delay(1);
  MC(p);
  delay(1);
}

void MA(int t)
{
  Serial1.write(map(t, 100, -100, 1, 127));
}

void MB(int t)
{
  Serial2.write(map(t, 100, -100, 1, 127));
}

void MC(int t)
{
  Serial2.write(map(t, -100, 100, 128, 255));
}

int t;
void setup()
{
  // put your setup code here, to run once:
  Serial2.begin(9600);
  Serial1.begin(9600);
  Serial.begin(9600);
}

void loop() 
{
   m1(50);
   m2(50);
   m3(50);
}
void m1(int p)
{
  t=map(p,100,-100,1,127);
  Serial1.write(t);
}
void m2(int p)
{
  t=map(p,100,-100,1,127);
  Serial2.write(t);
}
void m3(int p)
{
  t=map(p,-100,100,128,255);
  Serial2.write(t);
}

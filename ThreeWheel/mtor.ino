void motorA(int t)
{
  if (t > lim)
    t = lim;
  if (t < -lim)
    t = -lim;
  int var = map(t, 100, -100,-255, 255);
  if (var>0)
 {digitalWrite(motA,1);
 }
  Serial1.write(var);
}
void motorB(int t)
{
  if (t > lim)
    t = lim;
  if (t < -lim)
    t = -lim;
  int var = map(t, 100, -100, 128, 255);
  Serial2.write(var);
}
void motorC(int t)
{
  if (t > lim)
    t = lim;
  if (t < -lim)
    t = -lim;
  int var = map(t, 100, -100, 127, 1);
  Serial2.write(var);
}//5 6 7 pwm 6

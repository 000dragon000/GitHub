void encR()
{
  if (digitalRead(encR_B)) encR_pos++;
  else encR_pos--;
}
void encL()
{
  if (digitalRead(encL_B)) encL_pos++;
  else encL_pos--;
}
void flash()
{

  rrpm = encR_pos / 500;
  lrpm = encL_pos / 500;
//  encR_pos = 0;
//  encL_pos = 0;

  static boolean output = HIGH;

  digitalWrite(led_pin, output);
  output = !output;
}
void rev()
{
  a = (2 * PI * r * encR_pos) / 1024;
  b = (2 * PI * r * encL_pos) / 1024;
}

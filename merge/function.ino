void blinkLED(void)
{   
  if (ledState == LOW) {
    ledState = HIGH;
    blinkCount = blinkCount + 1;  // increase when LED turns on
  } else {
    ledState = LOW;
  }
  digitalWrite(led, ledState);
}
void rev()
{
 a=(2*PI*r*encR_pos)/1024;
 b=(2*PI*r*encL_pos)/1024;
} 
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

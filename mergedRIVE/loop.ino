void loop()
{ encoder();
}
void encoder()
{
  rev();
  Serial.print(rrpm); Serial.print(" "); Serial.println(lrpm);
  lastR = encR_pos;
  lastL = encL_pos;
  la = a;
  lb = b;
}

int pos = 0;
void pressure(){
      if (ps2x.ButtonPressed(PSB_PAD_RIGHT)) {
    if (ps2x.Button(PSB_PINK))
      pos += 2;
    else
      pos += 10;
    pos = constrain(pos, 0, 255);
    analogWrite(pressure_pin, pos);
 //   Serial.println(pos);
  }
  if (ps2x.ButtonPressed(PSB_PAD_LEFT)) {
    if (ps2x.Button(PSB_PINK))
      pos -= 2;
    else
      pos -= 10;
    pos = constrain(pos, 0, 255);
    analogWrite(pressure_pin, pos);
    //Serial.println(pos);
  }
}

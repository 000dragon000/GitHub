int pos = 0;

void pressure(){
      if (ps2_right) {
    if (ps2_square)
      pos += 2;
    else
      pos += 10;
    pos = constrain(pos, 0, 255);
    analogWrite(pressure_pin, pos);   
  // Serial.println(pos);
  }
  if (ps2_left){
    if (ps2_square)
      pos -= 2;
    else
      pos -= 10;
    pos = constrain(pos, 0, 255);
    analogWrite(pressure_pin, pos);
  Serial.println(pos);
  }
}

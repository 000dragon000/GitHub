void readButtons()
{
  ps2x.read_gamepad();
  LX = ps2x.Analog(PSS_LX) - 128;
  LY = ps2x.Analog(PSS_LY) - 128;

  up = ps2x.Button(PSB_PAD_UP);
  down = ps2x.Button(PSB_PAD_DOWN);
  left = ps2x.Button(PSB_PAD_LEFT);
  right = ps2x.Button(PSB_PAD_RIGHT);

  triangle = ps2x.Button(PSB_GREEN);
  circle = ps2x.Button(PSB_RED);
  cross = ps2x.Button(PSB_BLUE);
  sqr = ps2x.Button(PSB_PINK);

  r1 = ps2x.Button(PSB_R1);
  r2 = ps2x.Button(PSB_R2);
  l1 = ps2x.Button(PSB_L1);
  l2 = ps2x.Button(PSB_L2);
  Serial.print(LX);
  Serial.print(" ");
  Serial.println(LY);
  //delay(50);
}
void printState()
{
  //  Serial.print(up);
  //  Serial.print(" ");
  //  Serial.print(down);
  //  Serial.print(" ");
  //  Serial.print(" ");
  //  Serial.print(left);
  //  Serial.print(" ");
  //  Serial.print(right);
  //  Serial.print(" ");
  //  Serial.print(triangle);
  //  Serial.print(" ");
  //  Serial.print(circle);
  //  Serial.print(" ");
  //  Serial.print(cross);
  //  Serial.print(" ");
  //  Serial.print(sqr);
  //  Serial.print(" ");
  //  Serial.print(r1);
  //  Serial.print(" ");
  //  Serial.print(r2);
  //  Serial.print(" ");
  //  Serial.print(" ");
  //  Serial.print(l1);
  //  Serial.print(" ");
  //  Serial.print(l2);
  //  Serial.print(" ");
  //  Serial.print(r3);
  //  Serial.print(" ");
  //  Serial.print(l3);
  //  Serial.print(" ");
  //  Serial.print(RX);
  //  Serial.print(" ");
  //  Serial.print(RY);
  //  Serial.print(" ");
  //  Serial.print(fRX);
  //  Serial.print(" ");
  //  Serial.print(fRY);
  //  Serial.print(" ");
  //  Serial.print(LX);
  //  Serial.print(" ");
  //  Serial.print(LY);
  //  Serial.print(" ");
  //  Serial.print("x=");
  //  Serial.print(fLX);
  //  Serial.print("\ty=");
  //  Serial.print(fLY);
  //  Serial.print("\t mag= ");
  //  Serial.print(magnitude);
  //  Serial.print("\t theta = ");
  //  Serial.print(theta);
  //  Serial.print("\t");
  //  Serial.print(" ");
  //  Serial.print(start);
  //  Serial.print(" ");
  //  Serial.println(select);
}












void readButtons()
{
  ps2x.read_gamepad();
  up=ps2x.ButtonPressed(PSB_PAD_UP);
  down=ps2x.ButtonPressed(PSB_PAD_DOWN);
  left=ps2x.ButtonPressed(PSB_PAD_LEFT);
  right=ps2x.ButtonPressed(PSB_PAD_RIGHT);

  triangle=ps2x.ButtonPressed(PSB_GREEN);
  circle=ps2x.ButtonPressed(PSB_RED);
  cross=ps2x.ButtonPressed(PSB_BLUE);
  sqr=ps2x.ButtonPressed(PSB_PINK);

  r1=ps2x.ButtonPressed(PSB_R1);
  r2=ps2x.ButtonPressed(PSB_R2);
  l1=ps2x.ButtonPressed(PSB_L1);
  l2=ps2x.ButtonPressed(PSB_L2);

  r3=ps2x.ButtonPressed(PSB_R3);
  l3=ps2x.ButtonPressed(PSB_L3);

  RY=ps2x.Analog(PSS_RY);
  RX=ps2x.Analog(PSS_RX);

  LY=ps2x.Analog(PSS_LY);
  LX=ps2x.Analog(PSS_LX);

  start=ps2x.ButtonPressed(PSB_START);
  select=ps2x.ButtonPressed(PSB_SELECT);

}

void auto1()
{
  if((ps2x.ButtonPressed(PSB_L3))&&(ps2x.ButtonPressed(PSB_PAD_UP)))
  bldc.write(1720);
  if((ps2x.ButtonPressed(PSB_L3))&&(ps2x.ButtonPressed(PSB_PAD_DOWN)))
  bldc.write(1650);
}


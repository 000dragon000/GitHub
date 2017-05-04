int bldc_spd = 1500;
int bldc_limit = 1950;

void bldc_() {
  if (ps2x.ButtonPressed(PSB_GREEN) && bldc_spd == 1500) bldc_spd = 1550;
  if (ps2x.ButtonPressed(PSB_GREEN) && bldc_spd != 1500) bldc_spd += 10;
  if (ps2x.ButtonPressed(PSB_RED)) bldc_spd -= 10;

  if (bldc_spd > bldc_limit)
    bldc_spd = bldc_limit;

  if (ps2x.ButtonPressed(PSB_BLUE))
    bldc_spd = 1500;

  bldc.write(bldc_spd);
  auto1();
  //   Serial.println(bldc_spd);
}


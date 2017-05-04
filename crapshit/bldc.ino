
void bldc_() {
  if (ps2_triangle && bldc_spd == 1500){ bldc_spd = 1550; bldc.write(bldc_spd);}
  if (ps2_triangle && bldc_spd != 1500){ if(!ps2_square) bldc_spd += 10; else bldc_spd += 2; bldc.write(bldc_spd);}
  if (ps2_circle){ if(!ps2_square) bldc_spd -= 10; else bldc_spd -= 2; bldc.write(bldc_spd);}
  bldc_spd = constrain(bldc_spd, 1500, bldc_limit);
  if (ps2_cross)bldc_spd = 1500; bldc.write(1500);
  
}

void spin_bldc_() {
  if (ps2_left && spin_bldc_spd == 1500){ spin_bldc_spd = 1550; spin_bldc.write(spin_bldc_spd);}
  if (ps2_left && spin_bldc_spd != 1500){ if(!ps2_square) spin_bldc_spd += 10; else spin_bldc_spd += 2; spin_bldc.write(spin_bldc_spd);}
  if (ps2_right){ if(!ps2_square) spin_bldc_spd -= 10; else spin_bldc_spd -= 2; spin_bldc.write(spin_bldc_spd);}
  spin_bldc_spd = constrain(spin_bldc_spd, 1500, spin_bldc_limit);
//  if (ps2_right && ps2_left) spin_bldc_spd = 1500;
//  spin_bldc.write(spin_bldc_spd);

  if (ps2_cross)spin_bldc_spd = 1500;spin_bldc.write(1500);
  
  auto1();
 if(bldc_spd!=l_bldc||spin_bldc_spd!=l_s_bldc){
Serial.print(bldc_spd);Serial.print(' '); Serial.print(spin_bldc_spd);Serial.println();}
l_bldc=bldc_spd;l_s_bldc=spin_bldc_spd;
}


void auto1()
{
  if(ps2_triangle && ps2_right)
  {
  if(bldc_spd<1720)
  {
  while(bldc_spd<1720)
  bldc_spd+=10;
  }
   if(bldc_spd>1720)
  {
  while(bldc_spd>1720)
  bldc_spd-=10;
  }
  }
  if(ps2_circle && ps2_right)
  {
 if(bldc_spd<1650)
  {
  while(bldc_spd<1650)
  bldc_spd+=10;
  }
   if(bldc_spd>1650)
  {
  while(bldc_spd>1650)
  bldc_spd-=10;
  }
}
}


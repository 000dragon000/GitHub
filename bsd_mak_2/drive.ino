void drive(int y_analog, int x_analog){
  int def = map(y_analog,0,255,max_spd,-max_spd);

  int diff = map(x_analog,0,255,def,-def);

  int left = 64 - def + diff;
  int right = 192 + def + diff;

  if(left < 1) left = 1;
  if(left > 127) left = 127;
  if(right > 255) right = 255;
  if(right < 129) right = 129;
  
  Serial3.write(left);
  Serial3.write(right);
}

// 64 less --> left forward
// 64 greater --> left backward
// 192 less --> right backward
// 192 greater --> right forward

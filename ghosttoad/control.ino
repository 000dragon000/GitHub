void control()
{
  if(fLX<LX){
    fLX = fLX * a + LX * (1 - a);
    fLY = fLY * a + LY * (1 - a);  
  }
  else{
    fLX = fLX * 0.6 + LX * (1 - 0.6);
    fLY = fLY * 0.6 + LY * (1 - 0.6);
  }
    pwma = map(fLY, 128, -128, 90, -90);
    pwmb = map(fLX, 128, -128, 90, -90);
    //driveCorrect1();   
  Serial.print(pwma); Serial.print(" ");Serial.print(pwmb); 
    motorA(pwma - pwmb);
    motorB(pwma + pwmb);
  }


void off()
{
  motorA(0);
  motorB(0);
  delay(10);
}


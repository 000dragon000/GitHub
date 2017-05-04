void RP(){
  if(ps2x.Button(PSB_L2)){
    digitalWrite(roll_dirA,HIGH);
    digitalWrite(roll_dirB,LOW);
    analogWrite(roll_pwm,80);
  }
  else if(ps2x.Button(PSB_L1)){
    digitalWrite(roll_dirA,LOW);
    digitalWrite(roll_dirB,HIGH);
    analogWrite(roll_pwm,80);
  }
  else{
    digitalWrite(roll_dirA,HIGH);
    digitalWrite(roll_dirB,HIGH);
    analogWrite(roll_pwm,0);
  }

  if(ps2x.Button(PSB_R2)){
    digitalWrite(pitch_dirA,HIGH);
    digitalWrite(pitch_dirB,LOW);
    analogWrite(pitch_pwm,180);
  }
  else if(ps2x.Button(PSB_R1)){
    digitalWrite(pitch_dirA,LOW);
    digitalWrite(pitch_dirB,HIGH);
    analogWrite(pitch_pwm,200);
  }
  else{
    digitalWrite(pitch_dirA,HIGH);
    digitalWrite(pitch_dirB,HIGH);
    analogWrite(pitch_pwm,0);
  }
//  Serial.println(analogRead(roll_feedback));
}


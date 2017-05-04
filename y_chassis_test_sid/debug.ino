void debug_saber() {
  Serial.println("64 and 192");
  Serial3.write(64);
  Serial3.write(192);
  delay(4000);

  Serial.println("70 and 192");
  Serial3.write(70);
  Serial3.write(192);
  delay(4000);

  Serial.println("58 and 192");
  Serial3.write(58);
  Serial3.write(192);
  delay(4000);

  Serial.println("64 and 198");
  Serial3.write(64);
  Serial3.write(198);
  delay(4000);

  Serial.println("64 and 186");
  Serial3.write(64);
  Serial3.write(186);
  delay(4000);
}
//
void debug_hercules(){
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, LOW);
  analogWrite(pwm, 50);
  Serial.println("HIGH LOW");
  
  delay(4000);
  digitalWrite(dirA, LOW);
  digitalWrite(dirB, HIGH);
  analogWrite(pwm, 50);
  Serial.println("LOW HIGH");
  delay(4000);
}
//
//void debug_translate_x(){
//  int left = map(ps2x.Analog(PSS_LY),0,255,max_spd,-max_spd);
//  int right = map(ps2x.Analog(PSS_RY),0,255,max_spd,-max_spd);
//
//  Serial3.write(192 + );
//  Serial3.write(64 + );
//
//  if(ps2x.ButtonPressed(PSB_R2)){
//     Serial.print(left);Serial.print(' ');Serial.println(right);
//  }
//}
//
//void debug_translate_y(){
//  int hercules = map(ps2x.Analog(PSS_LY),0,255,100,-100);
//  int maxon = map(ps2x.Analog(PSS_RY),0,255,max_spd,-max_spd);
//
//  if(hercules > 0){
//    digitalWrite(dirA, );
//    digitalWrite(dirB, );
//    analogWrite(pwm, hercules);
//  }
//  else{
//    digitalWrite(dirA, );
//    digitalWrite(dirB, );
//    analogWrite(pwm, hercules);
//  }
//  
//  Serial3.write(192 + maxon);
//  Serial3.write(64 + maxon);  
//
//  if(ps2x.ButtonPressed(PSB_R2)){
//     Serial.print(hercules);Serial.print(' ');Serial.println(maxon);
//  }
//}

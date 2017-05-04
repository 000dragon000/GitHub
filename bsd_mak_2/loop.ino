
void loop() {
  ps2x.read_gamepad();

#ifndef DEBUG

/**************************************DRIVE**************************************/
  if(ps2x.ButtonPressed(PSB_PAD_UP)) max_spd = max_spd + 8;
  if(ps2x.ButtonPressed(PSB_PAD_DOWN)) max_spd = max_spd - 8;

  if(max_spd < 0) max_spd = 0;
  if(max_spd > 64) max_spd = 64;
  
  drive(ps2x.Analog(PSS_RY),ps2x.Analog(PSS_LX));

/*************************************BLDC********************************/
  if(ps2x.ButtonPressed(PSB_GREEN)) bldc_spd = bldc_spd + 5;
  if(ps2x.ButtonPressed(PSB_RED)) bldc_spd = bldc_spd - 5;

  if(bldc_spd > 1600) bldc_spd = 1600;
  if(bldc_spd < 1540) bldc_spd = 1540;

  if(ps2x.ButtonPressed(PSB_BLUE)) bldc_spd = 1540;
  
  bldc.write(bldc_spd);

/**********************************PRESSURE************************************/
  if(ps2x.ButtonPressed(PSB_PAD_LEFT)) pressure_pos = pressure_pos - 5;
  if(ps2x.ButtonPressed(PSB_PAD_RIGHT)) pressure_pos = pressure_pos + 5;

  if(pressure_pos < 0) pressure_pos = 0;
  
  analogWrite(pressure_pin,pressure_pos);  

/***********************************RP******************************************/
  if (ps2x.Button(PSB_L1)) {
    digitalWrite(roll_dir_1, HIGH);
    digitalWrite(roll_dir_2, LOW);
    analogWrite(roll_pwm, L1_pwm);
  }
  else if (ps2x.Button(PSB_L2)) {
    digitalWrite(roll_dir_1, LOW);
    digitalWrite(roll_dir_2, HIGH);
    analogWrite(roll_pwm, L2_pwm);
  }
  else {
    digitalWrite(roll_dir_1, HIGH);
    digitalWrite(roll_dir_2, HIGH);
  }

  if (ps2x.Button(PSB_R1)) {
    digitalWrite(pitch_dir_1, LOW);
    digitalWrite(pitch_dir_2, HIGH);
    analogWrite(pitch_pwm, R1_pwm);
  }
  else if (ps2x.Button(PSB_R2)) {
    digitalWrite(pitch_dir_1, HIGH);
    digitalWrite(pitch_dir_2, LOW);
    analogWrite(pitch_pwm, R2_pwm);
  }
  else {
    digitalWrite(pitch_dir_1, HIGH);
    digitalWrite(pitch_dir_2, HIGH);
  }

/**********************************8*/
#endif
   
#ifdef DEBUG
//  if(Serial.available()){
//    int c = Serial.parseInt();
//    switch(c){
//      case 0 :
//
//        break;
//      case 1 :
//        Serial.println("Enter ID : ");
//        int k = Serial.parseInt();
//        switch(k){
//          case 0 : debug_ps2(); break;
//          case 1 : debug_drive(); break;
//          case 2 : debug_RP(); break;
//          case 3 : debug_bldc(); break;
//          case 4 : debug_feed(); break;
//          case 5 : debug_pressure(); break;
//          default:
//            Serial.println("0 - PS2 debug");
//            Serial.println("1 - drive debug");
//            Serial.println("2 - RP debug");
//            Serial.println("3 - bldc debug");
//            Serial.println("4 - feed debug");
//            Serial.println("5 - pressure debug");
//            Serial.println();
//        }
//        break;
//      default:
//        Serial.println("0 - All debug functions");
//        Serial.println("1 - ID based debug");
//        Serial.println();
//    }
//  }
//  debug_ps2();
  debug_drive();
//  debug_RP();
//  debug_bldc();
//  debug_feed();
//  debug_pressure();
#endif
}


//  if(ps2x.ButtonPressed(PSB_L1)) pos = pos + 5;
//  if(ps2x.ButtonPressed(PSB_L2)) pos = pos - 5;
//
//  feed.write(pos);
//
//  Serial.println(pos);

//  if(Serial.available()){
//    p = Serial.parseInt();
//    analogWrite(pressure_pin,p);
//  }




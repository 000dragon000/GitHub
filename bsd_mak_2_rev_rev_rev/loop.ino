int override_flag = 0;
int prev_override_flag = 0;
bool override = false;

void loop() {
  ps2x.read_gamepad();
  
  buff[1]= 0b00 << 7 | ps2x.Button(PSB_R3) << 6 | ps2x.ButtonPressed(PSB_GREEN) << 5 | ps2x.ButtonPressed(PSB_RED) << 4 | ps2x.ButtonPressed(PSB_BLUE) << 3 | ps2x.ButtonPressed(PSB_PAD_RIGHT) << 2 | ps2x.ButtonPressed(PSB_PAD_LEFT) << 1 | ps2x.Button(PSB_PINK)<< 0;
   if(buff[1]!=buff[0]){
 // Serial.println(buff[1],BIN);
  //if(Serial.available() )
    Serial1.write(buff[1]);
 //    Serial1.write('\n');
  buff[0]=buff[1];} 
  
//i2c_scanner();
//  mpu();
//    feed_();
    RP();
//    bldc_();
//    pressure();
   drive();
}

//70 right forwarda
//200 left forward
// HIGH LOW front
// LOW HIGH back

/********override operation************
     if (ps2x.Button(PSB_PINK) && ps2x.Button(PSB_L1) && ps2x.Button(PSB_L2) && ps2x.Button(PSB_R1) && ps2x.Button(PSB_R2)) override_flag = 1;

  if (ps2x.ButtonReleased(PSB_PINK) ) override_flag = 0;

  if(override_flag == 1 && prev_override_flag = 0)
    override = true;

  if(override_flag
  if(override && prev_override_flag = 0)
    Serial.println("Override mode activated");
*/

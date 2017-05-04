//#define MAXON_TO_BANE 3.98
//
//int forward,rotation;
//int max_spd = 0;
//int translate = 0;
//bool fast_mode = false;
//int init_RX;
//float alpha = 0.9;
//
//void drive() {
//  if (ps2x.ButtonPressed(PSB_L3) && (ps2x.Analog(PSS_RX) == 0 || ps2x.Analog(PSS_RX) == 255)){
//    fast_mode = true;
//    init_RX = ps2x.Analog(PSS_RX);
//  }
//  
//  else if(ps2x.ButtonPressed(PSB_L3))
//    fast_mode = false;
//
//  if (!fast_mode) {
//    if (ps2x.ButtonPressed(PSB_PAD_UP))
//      max_spd += 8;
//
//    if (ps2x.ButtonPressed(PSB_PAD_DOWN))
//      max_spd -= 8;
//
//    max_spd = constrain(max_spd, 0, 64);
//
//    forward = map(ps2x.Analog(PSS_RX), 0, 255, max_spd, -max_spd);
//    rotation = map(ps2x.Analog(PSS_LX), 0, 255, ((forward == 0) ? max_spd : forward), (-forward == 0) ? -max_spd : -forward);
//
//    if (forward < 0) rotation *= -1;
//
//    if (ps2x.Analog(PSS_RY) < 128) {
//      digitalWrite(dirA, HIGH);
//      digitalWrite(dirB, LOW);
//      analogWrite(pwm, 100);
//      translate = 8;
//    }
//    else if (ps2x.Analog(PSS_RY) > 128) {
//      digitalWrite(dirA, LOW);
//      digitalWrite(dirB, HIGH);
//      analogWrite(pwm, 99);
//      translate = -6;
//    }
//    else {
//      digitalWrite(dirA, LOW);
//      digitalWrite(dirB, LOW);
//      analogWrite(pwm, 0);
//      translate = 0;
//    }
//
//    int left = constrain(192 - forward - rotation + translate,129,254);
//    int right = constrain(64 - forward + rotation - translate,1,127);
//
//    Serial3.write(left);
//    delay(1);
//    Serial3.write(right);
//    delay(1);
//  }
//  else {
//    int RX = ps2x.Analog(PSS_RX);
//    forward = constrain((init_RX ? 1 : -1)*map(RX, init_RX, 255 - init_RX, 0, 64),-63,63) * (1-alpha) + forward * alpha;
//    rotation = map(ps2x.Analog(PSS_LX), 0, 255, 12, -12);
//    
//    
//    Serial3.write(192 - forward - rotation);
//    delay(1);
//    Serial3.write(64 - forward + rotation);
//    delay(1);
//  }
//
//}

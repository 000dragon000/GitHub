
int bane_limit = 255;

void feed_() {
     if (ps2_r3){
      digitalWrite(dirB, LOW);
      digitalWrite(dirA, HIGH);
      analogWrite(pwm, 255);
    }
    else if (/*pps2[6] == 1 &&*/ ps2_r3 == 0) {
//      digitalWrite(dirB, HIGH);
//      digitalWrite(dirA, LOW);
//      analogWrite(pwm, 255);
//      delay(200);
      digitalWrite(dirA, HIGH);
      digitalWrite(dirB, HIGH);
      analogWrite(pwm, 0);
    }
//    if(ps2_r3 && bane_spd == 0) bane_spd = 5;
//   if(ps2_r3 && bane_spd != 0) bane_spd += 5;
//   if(ps2_square) bane_spd -= 5;
//bane_spd=constrain(bane_spd,0,255);
//   if(ps2_cross)bane_spd = 0;
//     digitalWrite(dirB, LOW);
//      digitalWrite(dirA, HIGH);
//      analogWrite(pwm, bane_spd);
  }



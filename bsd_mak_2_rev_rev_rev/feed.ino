  void feed_() {
     if (ps2x.Button(PSB_R3)) {
      digitalWrite(dir_1, LOW);
      digitalWrite(dir_2, HIGH);
      analogWrite(pwm_pin, 255);
    }
    else if (ps2x.ButtonReleased(PSB_R3)) {
      digitalWrite(dir_1, HIGH);
      digitalWrite(dir_2, LOW);
      analogWrite(pwm_pin, 255);
      delay(200);
    }
    else {
      digitalWrite(dir_1, HIGH);
      digitalWrite(dir_2, HIGH);
      analogWrite(pwm_pin, 0);
    }
  }


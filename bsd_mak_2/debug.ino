#ifdef DEBUG
int pos;
void debug_ps2() {
  ps2x.read_gamepad();

  Serial.print(ps2x.Button(PSB_PAD_UP)); Serial.print(' ');
  Serial.print(ps2x.Button(PSB_PAD_DOWN)); Serial.print(' ');
  Serial.print(ps2x.Button(PSB_PAD_LEFT)); Serial.print(' ');
  Serial.print(ps2x.Button(PSB_PAD_RIGHT)); Serial.print(' ');

  Serial.print(ps2x.Button(PSB_GREEN)); Serial.print(' ');
  Serial.print(ps2x.Button(PSB_RED)); Serial.print(' ');
  Serial.print(ps2x.Button(PSB_BLUE)); Serial.print(' ');
  Serial.print(ps2x.Button(PSB_PINK)); Serial.print(' ');

  Serial.print(ps2x.Button(PSB_R1)); Serial.print(' ');
  Serial.print(ps2x.Button(PSB_R2)); Serial.print(' ');
  Serial.print(ps2x.Button(PSB_L1)); Serial.print(' ');
  Serial.print(ps2x.Button(PSB_L2)); Serial.print(' ');

  Serial.print(ps2x.Button(PSB_R3)); Serial.print(' ');
  Serial.print(ps2x.Button(PSB_L3)); Serial.print(' ');

  Serial.print(ps2x.Analog(PSS_RY)); Serial.print(' ');
  Serial.print(ps2x.Analog(PSS_RX)); Serial.print(' ');

  Serial.print(ps2x.Analog(PSS_LY)); Serial.print(' ');
  Serial.print(ps2x.Analog(PSS_LX)); Serial.print(' ');

  Serial.print(ps2x.Button(PSB_START)); Serial.print(' ');
  Serial.println(ps2x.Button(PSB_SELECT));
}

void debug_drive() {

  if (Serial.available()) {
    int c = Serial.parseInt();
    switch (c) {
      case 0:
        Serial.println("Both stop");
        Serial3.write(64);
        delay(2);
        Serial3.write(192);
        delay(2);
        break;

      case 1:
        Serial.println("First motor less than 64");
        Serial3.write(55);
        delay(2);
        Serial3.write(192);
        delay(2);
        break;

      case 2:
        Serial.println("First motor greater than 64");
        Serial3.write(70);
        delay(2);
        Serial3.write(192);
        delay(2);
        break;

      case 3:
        Serial.println("Second motor less than 192");
        Serial3.write(64);
        delay(2);
        Serial3.write(185);
        delay(2);
        break;

      case 4:
        Serial.println("Second motor greater than 192");
        Serial3.write(64);
        delay(2);
        Serial3.write(202);
        delay(2);
        break;

      default:
        Serial.println("Choices : 0 - 4");
        Serial.println("0 - Both stop");
        Serial.println("1 - First motor less than 64");
        Serial.println("2 - First motor greater than 64");
        Serial.println("3 - Second motor less than 192");
        Serial.println("4 - Second motor greater than 192");
        Serial.println();
    }
  }
}

void debug_RP() {
  if (Serial.available()) {
    L1_pwm = Serial.parseInt();
    L2_pwm = Serial.parseInt();
    R1_pwm = Serial.parseInt();
    R2_pwm = Serial.parseInt();

    Serial.print(L1_pwm); Serial.print(' ');
    Serial.print(L2_pwm); Serial.print(' ');
    Serial.print(R1_pwm); Serial.print(' ');
    Serial.println(R2_pwm);
  }
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
    digitalWrite(pitch_dir_1, HIGH);
    digitalWrite(pitch_dir_2, LOW);
    analogWrite(pitch_pwm, R1_pwm);
  }
  else if (ps2x.Button(PSB_R2)) {
    digitalWrite(pitch_dir_1, LOW);
    digitalWrite(pitch_dir_2, HIGH);
    analogWrite(pitch_pwm, R2_pwm);
  }
  else {
    digitalWrite(pitch_dir_1, HIGH);
    digitalWrite(pitch_dir_2, HIGH);
  }
}

void debug_bldc() {
  bldc.writeMicroseconds(1500);
  delay(1000);
  bldc.writeMicroseconds(1550);
  delay(2000);
  bldc.writeMicroseconds(1570);
  delay(2000);
  bldc.writeMicroseconds(1590);
  delay(3000);
  bldc.writeMicroseconds(1500);
  delay(20000);
}
int a;
void debug_feed() {
  if (pos == 130) {
    a = 1;
    delay(1000);
  }
  if (pos == 80) a = -1;
  pos = pos - a;
  feed.write(pos);
  delay(10);
}

void debug_pressure() {
  analogWrite(pressure_pin, -1);
  delay(6000);
  analogWrite(pressure_pin, 0);
  delay(6000);
}
#endif

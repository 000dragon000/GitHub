/*******************************************MAIN SETUP********************************************/
void setup()
{
  setup_ps2();
  setup_drive();
  setup_RP();
  setup_bldc();
  setup_feed();
  setup_pressure();
  
  Serial.begin(BAUD_RATE);
}

/**************************************SETUP FUCTIONS**************************************/
void setup_ps2() {
  ps2x.config_gamepad(CLOCK, COMMAND, ATTENTION, DATA); // (clock(blue),command(orange), attention(yellow), data(brown))
}

void setup_drive() {
  Serial3.begin(9600);
  Serial3.write(64);
  Serial3.write(192);
}

void setup_RP() {
  pinMode(roll_dir_1, OUTPUT);
  pinMode(roll_dir_2, OUTPUT);
  pinMode(roll_pwm, OUTPUT);

  digitalWrite(roll_dir_1, HIGH);
  digitalWrite(roll_dir_2, HIGH);
  digitalWrite(roll_pwm, LOW);

  pinMode(pitch_dir_1, OUTPUT);
  pinMode(pitch_dir_2, OUTPUT);
  pinMode(pitch_pwm, OUTPUT);

  digitalWrite(pitch_dir_1, HIGH);
  digitalWrite(pitch_dir_2, HIGH);
  digitalWrite(pitch_pwm, LOW);
}

void setup_bldc(){
  bldc.attach(bldc_pin);
  bldc.writeMicroseconds(1500);
}

void setup_feed(){
  feed.attach(feed_pin);
  feed.write(130);
}

void setup_pressure(){
  pinMode(pressure_pin,OUTPUT);
  analogWrite(pressure_pin,0);
}


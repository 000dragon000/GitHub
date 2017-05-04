void setup() {
 Serial.begin(9600);
 Serial2.begin(9600);
setup_bldc();
setup_bane();
setup_spin_bldc();
// setup_mpu();
}

void setup_bldc() {
  bldc.attach(bldc_pin);
  bldc.write(1500);
  delay(250);
}

void setup_spin_bldc() {
  spin_bldc.attach(spin_bldc_pin);
  spin_bldc.write(1500);
  delay(250);
}

void setup_bane() {
  pinMode(pwm, OUTPUT);
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);

  digitalWrite(dirA, LOW);
  digitalWrite(dirB, LOW);
}

void setup_mpu() {
  Wire.begin();
  //Serial.begin(9600);

  check_MPU();
  check_mag();

  delay(1000);

//  get_accel_avg();
  get_gyro_avg();
//  get_mag_avg();

  prev_time = 0;
}


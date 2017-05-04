void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);

//  pinMode(13, OUTPUT);
//  pinMode(roll_feedback, INPUT); pinMode(A11, OUTPUT); digitalWrite(LOW, A11);
  
  setup_RP();
  setup_ps2();
  setup_bldc();
  setup_saber();
  setup_bane();
 // setup_feed();
  //  setup_mpu();

  // noInterrupts();
}

void setup_ps2() {
  error = ps2x.config_gamepad(CLOCK, COMMAND, ATTENTION, DATA, false, false);

  while (error != 0) {
    error = ps2x.config_gamepad(CLOCK, COMMAND, ATTENTION, DATA, false, false);
    Serial.println("Check PS2 Wiring");
  }
}

void setup_saber() {
  Serial3.begin(9600);

  Serial3.write(64);
  delay(2);
  Serial3.write(192);
  delay(2);
}

void setup_bane() {
  pinMode(pwm, OUTPUT);
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);

  digitalWrite(dirA, LOW);
  digitalWrite(dirB, LOW);
}

//void setup_feed() {
//  feed.attach(feed_pin);
//
//  feed.write(90);
//}

void setup_bldc() {
  bldc.attach(bldc_pin);

  bldc.write(1500);
  delay(1000);
}

void setup_RP() {
  pinMode(roll_dirA, OUTPUT);
  pinMode(roll_dirB, OUTPUT);
  pinMode(roll_pwm, OUTPUT);

  pinMode(pitch_dirA, OUTPUT);
  pinMode(pitch_dirB, OUTPUT);
  pinMode(pitch_pwm, OUTPUT);

  digitalWrite(roll_dirA, HIGH);
  digitalWrite(roll_dirB, HIGH);

  digitalWrite(pitch_dirA, HIGH);
  digitalWrite(pitch_dirB, HIGH);

  analogWrite(roll_pwm, 0);
  analogWrite(pitch_pwm, 0);
}

void setup_pressure() {
  pinMode(pressure_pin, OUTPUT);
  analogWrite(pressure_pin, 0);
}

void setup_mpu() {
  Wire.begin();
  TWBR = 12;  // 400 kbit/sec I2C speed

  byte c = readByte(MPU9250_ADDRESS, WHO_AM_I_MPU9250);  // Read WHO_AM_I register for MPU-9250
  Serial.print("MPU9250 "); Serial.print("I AM "); Serial.print(c, HEX); Serial.print(". I should be "); Serial.println(0x71, HEX);

  if (c == 0x71) // WHO_AM_I should always be 0x68
  {
    Serial.println("MPU9250 is online...");

    MPU9250SelfTest(SelfTest);
    calibrateMPU9250(gyroBias, accelBias);
    initMPU9250();
    byte d = readByte(AK8963_ADDRESS, WHO_AM_I_AK8963);  // Read WHO_AM_I register for AK8963
    Serial.print("AK8963 "); Serial.print("I AM "); Serial.print(d, HEX); Serial.print(" I should be "); Serial.println(0x48, HEX);
    initAK8963(magCalibration); Serial.println("AK8963 initialized for active data mode...."); // Initialize device for active mode read of magnetometer
    getMres();
    //    magcalMPU9250(magBias, magScale);

    magBias[0] = 249;
    magBias[1] = 47;
    magBias[2] = -270;

    magScale[0] = 19;
    magScale[1] = 33;
    magScale[2] = 60;
  }
  else
  {
    Serial.print("Could not connect to MPU9250: 0x");
    Serial.println(c, HEX);
    while (1) ; // Loop forever if communication doesn't happen
  }

  writeByte(MPU9250_ADDRESS, INT_ENABLE, 0x00);
  noInterrupts();
}


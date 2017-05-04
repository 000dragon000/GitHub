void setup()
{  //  front(30);
  //  delay(500);
  // brake();
  for (int i = 0; i < 3; i++)
  { pinMode(motL[i], OUTPUT);
    pinMode(motR[i], OUTPUT);
  }
  Wire.begin();
  pinMode(pot,INPUT);
  Serial.begin(9600);
  Serial.print("MU9250");

  // TWBR = 12;  // 400 kbit/sec I2C speed

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
    Serial.print("mx \t   "); 
    initAK8963(magCalibration);// Serial.println("AK8963 initialized for active data mode...."); // Initialize device for active mode read of magnetometer
    getMres();
    //      magcalMPU9250(magBias, magScale);
    //
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

}

//float declination = ;

void mpu() {
  //  while (Serial.available()) {
  //    Kp = Serial.parseFloat();
  //    Ki = Serial.parseFloat();
  //  }
  //  if (readByte(MPU9250_ADDRESS, INT_STATUS) & 0x01) {  // On interrupt, check if data ready interrupt
  readAccelData(accelCount);  // Read the x/y/z adc values
  getAres();

  // Now we'll calculate the accleration value into actual g's
  ax = (float)accelCount[0] * aRes; // - accelBias[0];  // get actual g value, this depends on scale being set
  ay = (float)accelCount[1] * aRes; // - accelBias[1];
  az = (float)accelCount[2] * aRes; // - accelBias[2];

  readGyroData(gyroCount);  // Read the x/y/z adc values
  getGres();

  // Calculate the gyro value into actual degrees per second
  gx = (float)gyroCount[0] * gRes; // get actual gyro value, this depends on scale being set
  gy = (float)gyroCount[1] * gRes;
  gz = (float)gyroCount[2] * gRes;

  readMagData(magCount);  // Read the x/y/z adc values
  getMres();
  mx = (float)magCount[0] * mRes * magCalibration[0] - magBias[0]; // get actual magnetometer value, this depends on scale being set
  my = (float)magCount[1] * mRes * magCalibration[1] - magBias[1];
  mz = (float)magCount[2] * mRes * magCalibration[2] - magBias[2];
  //  }

  Now = micros();
  deltat = ((Now - lastUpdate) / 1000000.0f); // set integration time by time elapsed since last filter update
  lastUpdate = Now;

  sum += deltat; // sum for averaging filter update rate
  sumCount++;
  //  MadgwickQuaternionUpdate(ax, ay, az, gx * PI / 180.0f, gy * PI / 180.0f, gz * PI / 180.0f,  my,  mx, mz);
  MahonyQuaternionUpdate(ax, ay, az, gx * PI / 180.0f, gy * PI / 180.0f, gz * PI / 180.0f, my, mx, mz);

  yaw   = atan2(2.0f * (q[1] * q[2] + q[0] * q[3]), q[0] * q[0] + q[1] * q[1] - q[2] * q[2] - q[3] * q[3]);
  pitch = -asin(2.0f * (q[1] * q[3] - q[0] * q[2]));
  roll  = atan2(2.0f * (q[0] * q[1] + q[2] * q[3]), q[0] * q[0] - q[1] * q[1] - q[2] * q[2] + q[3] * q[3]);
  pitch *= 180.0f / PI;
  yaw   *= 180.0f / PI;
  yaw   += 1.34; // Declination at Danville, California is 13 degrees 48 minutes and 47 seconds on 2014-04-04
  roll  *= 180.0f / PI;


  Serial.print("Yaw, Pitch, Roll: ");
  Serial.print(yaw, 2);
  Serial.print(", ");
  Serial.print(pitch, 2);
  Serial.print(", ");
  Serial.println(roll, 2);

  count = millis();
  sumCount = 0;
  sum = 0;
}


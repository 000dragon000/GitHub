void check_MPU() {
  byte data;

  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(WHO_AM_I);
  Wire.endTransmission(false);

  Wire.requestFrom(MPU_ADDRESS, 1);
  while (Wire.available())
    data = Wire.read();

  if (data != 0x71) {
    Serial.println("Check MPU wiring..."); while (1);
  } else {
    Serial.println("mpu working bitch");
  }
}

void check_mag() {
  byte data;

  Wire.beginTransmission(MAG_ADDRESS);
  Wire.write(WHO_AM_I_MAG);
  Wire.endTransmission(false);

  Wire.requestFrom(MAG_ADDRESS, 1);
  data = Wire.read();

  if (data != 0x48) {
    Serial.print(data, HEX); Serial.print(' ');
    Serial.println("some weird shit wrong with magnetometer"); while (1);
  } else {
    Serial.println("magnetometer working bitch");
  }
}
/**************************************************************ACCEL DATA**************************************/

void get_accel_data() {
  byte i = 0;
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(ACCEL_XOUT_H);
  Wire.endTransmission(false);

  Wire.requestFrom(MPU_ADDRESS, 6);
  while (Wire.available())
    wire_buffer[i++] = Wire.read();

  accel_x = (((int16_t)wire_buffer[0] << 8) | wire_buffer[1]);
  accel_y = (((int16_t)wire_buffer[2] << 8) | wire_buffer[3]);
  accel_z = (((int16_t)wire_buffer[4] << 8) | wire_buffer[5]);

  if (SERIAL_DEBUG) {
    Serial.print(accel_x); Serial.print('\t');
    Serial.print(accel_y); Serial.print('\t');
    Serial.print(accel_z); Serial.print('\t');
    Serial.println(sqrt(accel_x * accel_x + accel_y * accel_y + accel_z * accel_z));
  }
}

void get_accel_avg() {
  i = 0;
  while (i <= 100) {
    get_accel_data();
    accel_x_avg += accel_x;
    accel_y_avg += accel_y;
    accel_z_avg += accel_z;
    i++;
  }
  accel_x_avg /= 100;
  accel_y_avg /= 100;
  accel_z_avg /= 100;
}

/*******************************************GYRO DATA *************************************/
void get_gyro_data() {
  byte i = 0;

  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(GYRO_XOUT_H);
  Wire.endTransmission(false);

  Wire.requestFrom(MPU_ADDRESS, 6);
  while (Wire.available())
    wire_buffer[i++] = Wire.read();

  gyro_x = (((int16_t)wire_buffer[0] << 8) | wire_buffer[1]);
  gyro_y = (((int16_t)wire_buffer[2] << 8) | wire_buffer[3]);
  gyro_z = (((int16_t)wire_buffer[4] << 8) | wire_buffer[5]);


  if (SERIAL_DEBUG) {
    Serial.print(gyro_x); Serial.print('\t');
    Serial.print(gyro_y); Serial.print('\t');
    Serial.print(gyro_z); Serial.println('\t');
  }
}

void get_gyro_avg() {
  i = 0;
  while (i <= 100) {
    get_gyro_data();
    gyro_x_avg += gyro_x;
    gyro_y_avg += gyro_y;
    gyro_z_avg += gyro_z;
    i++;
  }
  gyro_x_avg /= 100;
  gyro_y_avg /= 100;
  gyro_z_avg /= 100;
}

/********************************************************MAG DATA*********************************************/

void get_mag_data() {
  byte i = 0;
  Wire.beginTransmission(MAG_ADDRESS);
  Wire.write(MAG_XOUT_L);
  Wire.endTransmission(false);

  Wire.requestFrom(MAG_ADDRESS, 7);
  while (Wire.available()) {
    wire_buffer[i++] = Wire.read();
    //    Serial.print(wire_buffer[i-1],BIN);Serial.print('\t');
  }
  mag_x = (((int16_t)wire_buffer[1] << 8) | wire_buffer[0]);
  mag_y = (((int16_t)wire_buffer[3] << 8) | wire_buffer[2]);
  mag_z = (((int16_t)wire_buffer[5] << 8) | wire_buffer[4]);

  if (SERIAL_DEBUG) {
    Serial.print(mag_x); Serial.print('\t');
    Serial.print(mag_y); Serial.print('\t');
    Serial.print(mag_z); Serial.println('\t');
  }
}

void get_mag_avg() {
  i = 0;
  while (i <= 100) {
    get_mag_data();
    mag_x_avg += mag_x;
    mag_y_avg += mag_y;
    mag_z_avg += mag_z;
    i++;
  }
  mag_x_avg /= 100;
  mag_y_avg /= 100;
  mag_z_avg /= 100;
}

/*******************************************************FILTER*******************************************/

void MahonyQuaternionUpdate(float ax, float ay, float az, float gx, float gy, float gz, float mx, float my, float mz)
{
  float q1 = q[0], q2 = q[1], q3 = q[2], q4 = q[3];   // short name local variable for readability
  float norm;
  float hx, hy, bx, bz;
  float vx, vy, vz, wx, wy, wz;
  float ex, ey, ez;
  float pa, pb, pc;

  // Auxiliary variables to avoid repeated arithmetic
  float q1q1 = q1 * q1;
  float q1q2 = q1 * q2;
  float q1q3 = q1 * q3;
  float q1q4 = q1 * q4;
  float q2q2 = q2 * q2;
  float q2q3 = q2 * q3;
  float q2q4 = q2 * q4;
  float q3q3 = q3 * q3;
  float q3q4 = q3 * q4;
  float q4q4 = q4 * q4;

  // Normalise accelerometer measurement
  norm = sqrtf(ax * ax + ay * ay + az * az);
  if (norm == 0.0f) return; // handle NaN
  norm = 1.0f / norm;        // use reciprocal for division
  ax *= norm;
  ay *= norm;
  az *= norm;

  // Normalise magnetometer measurement
  norm = sqrtf(mx * mx + my * my + mz * mz);
  if (norm == 0.0f) return; // handle NaN
  norm = 1.0f / norm;        // use reciprocal for division
  mx *= norm;
  my *= norm;
  mz *= norm;

  // Reference direction of Earth's magnetic field
  hx = 2.0f * mx * (0.5f - q3q3 - q4q4) + 2.0f * my * (q2q3 - q1q4) + 2.0f * mz * (q2q4 + q1q3);
  hy = 2.0f * mx * (q2q3 + q1q4) + 2.0f * my * (0.5f - q2q2 - q4q4) + 2.0f * mz * (q3q4 - q1q2);
  bx = sqrtf((hx * hx) + (hy * hy));
  bz = 2.0f * mx * (q2q4 - q1q3) + 2.0f * my * (q3q4 + q1q2) + 2.0f * mz * (0.5f - q2q2 - q3q3);

  // Estimated direction of gravity and magnetic field
  vx = 2.0f * (q2q4 - q1q3);
  vy = 2.0f * (q1q2 + q3q4);
  vz = q1q1 - q2q2 - q3q3 + q4q4;
  wx = 2.0f * bx * (0.5f - q3q3 - q4q4) + 2.0f * bz * (q2q4 - q1q3);
  wy = 2.0f * bx * (q2q3 - q1q4) + 2.0f * bz * (q1q2 + q3q4);
  wz = 2.0f * bx * (q1q3 + q2q4) + 2.0f * bz * (0.5f - q2q2 - q3q3);

  // Error is cross product between estimated direction and measured direction of gravity
  ex = (ay * vz - az * vy) + (my * wz - mz * wy);
  ey = (az * vx - ax * vz) + (mz * wx - mx * wz);
  ez = (ax * vy - ay * vx) + (mx * wy - my * wx);
  if (Ki > 0.0f)
  {
    eInt[0] += ex;      // accumulate integral error
    eInt[1] += ey;
    eInt[2] += ez;
  }
  else
  {
    eInt[0] = 0.0f;     // prevent integral wind up
    eInt[1] = 0.0f;
    eInt[2] = 0.0f;
  }

  // Apply feedback terms
  gx = gx + Kp * ex + Ki * eInt[0];
  gy = gy + Kp * ey + Ki * eInt[1];
  gz = gz + Kp * ez + Ki * eInt[2];

  // Integrate rate of change of quaternion
  pa = q2;
  pb = q3;
  pc = q4;
  q1 = q1 + (-q2 * gx - q3 * gy - q4 * gz) * (0.5f * deltat);
  q2 = pa + (q1 * gx + pb * gz - pc * gy) * (0.5f * deltat);
  q3 = pb + (q1 * gy - pa * gz + pc * gx) * (0.5f * deltat);
  q4 = pc + (q1 * gz + pa * gy - pb * gx) * (0.5f * deltat);

  // Normalise quaternion
  norm = sqrtf(q1 * q1 + q2 * q2 + q3 * q3 + q4 * q4);
  norm = 1.0f / norm;
  q[0] = q1 * norm;
  q[1] = q2 * norm;
  q[2] = q3 * norm;
  q[3] = q4 * norm;

  yaw   = atan2(2.0f * (q[1] * q[2] + q[0] * q[3]), q[0] * q[0] + q[1] * q[1] - q[2] * q[2] - q[3] * q[3]);
  pitch = -asin(2.0f * (q[1] * q[3] - q[0] * q[2]));
  roll  = atan2(2.0f * (q[0] * q[1] + q[2] * q[3]), q[0] * q[0] - q[1] * q[1] - q[2] * q[2] + q[3] * q[3]);

  pitch *= 180.0f / PI;
  yaw   *= 180.0f / PI;
  yaw   += 1.25; // Declination at chennai mothafukaz @11:54 p.m ps: zombie mode 1 month before competition ;(
  roll  *= 180.0f / PI;
}

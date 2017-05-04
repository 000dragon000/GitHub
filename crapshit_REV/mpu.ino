void mpu(){
  get_accel_data();

  get_gyro_data();
  get_mag_data();

  real_accel_x = (accel_x - accel_x_avg) * accel_res; real_accel_y = (accel_y - accel_y_avg) * accel_res; real_accel_z = (accel_z - accel_z_avg) * accel_res;
  real_gyro_x = (gyro_x - gyro_x_avg) * gyro_res; real_gyro_y = (gyro_y - gyro_y_avg) * gyro_res; real_gyro_z = (gyro_z - gyro_z_avg) * gyro_res;
  real_mag_x = (mag_x - mag_x_avg) / mag_res; real_mag_y = (mag_y - mag_y_avg) / mag_res; real_mag_z = (mag_z - mag_z_avg) / mag_res;

  if (SERIAL_DEBUG) {
    Serial.print(real_accel_x, 3); Serial.print('\t');
    Serial.print(real_accel_y, 3); Serial.print('\t');
    Serial.print(real_accel_z, 3); Serial.print('\t');

    Serial.print(real_gyro_x, 3); Serial.print('\t');
    Serial.print(real_gyro_y, 3); Serial.print('\t');
    Serial.print(real_gyro_z, 3); Serial.print('\t');

    Serial.print(real_mag_x, 3); Serial.print('\t');
    Serial.print(real_mag_y, 3); Serial.print('\t');
    Serial.print(real_mag_z, 3); Serial.println(' ');
  }

  deltat = (millis() - prev_time)/1000.0;
//  Serial.print(deltat,5);Serial.print(' ');
  prev_time = millis();
  MahonyQuaternionUpdate(real_accel_x, real_accel_y, real_accel_z, real_gyro_x * PI / 180.0f, real_gyro_y * PI / 180.0f, real_gyro_z * PI / 180.0f, real_mag_y, real_mag_x, real_mag_z);
 roll=roll*(1-alpha) +p_roll*(alpha);
  pitch=pitch*(1-alpha) +p_pitch*(alpha);
  yaw=yaw*(1-alpha) +p_yaw*(alpha);
 // if(ps2_right)
  {Serial.print(round(roll)); Serial.print(' '); Serial.print(round(pitch)); Serial.print(' '); Serial.print(round(yaw));Serial.print(' '); Serial.print(bldc_spd);Serial.print(' '); Serial.print(bane_spd);Serial.println();}
}

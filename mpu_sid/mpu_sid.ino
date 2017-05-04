#include <Wire.h>

#define SERIAL_DEBUG 0

#define MPU_ADDRESS 0x68
#define MAG_ADDRESS 0x0C

#define WHO_AM_I 0x75
#define WHO_AM_I_MAG 0x00

#define ACCEL_XOUT_H 0x3B
#define  GYRO_XOUT_H 0x43
#define MAG_XOUT_L 0x03

float accel_x = 0, accel_y = 0, accel_z = 0;
float gyro_x = 0, gyro_y = 0, gyro_z = 0;
float mag_x = 0, mag_y = 0, mag_z = 0;

float real_accel_x = 0, real_accel_y = 0, real_accel_z = 0;
float real_gyro_x = 0, real_gyro_y = 0, real_gyro_z = 0;
float real_mag_x = 0, real_mag_y = 0, real_mag_z = 0;

float accel_x_avg = 0, accel_y_avg = 0, accel_z_avg = 0;
float gyro_x_avg = 0, gyro_y_avg = 0, gyro_z_avg = 0;
float mag_x_avg = 0, mag_y_avg = 0, mag_z_avg = 0;

float accel_res = 2.0 / 32768.0, gyro_res = 250.0 / 32768.0, mag_res = 6;

byte data;
byte wire_buffer[7];
byte i = 0;

float roll, pitch, yaw;
float q[4]={1.0f, 0.0f, 0.0f, 0.0f};
float Kp = 11.5, Ki = 0.001;
float eInt[3]={0.0,0.0,0.0};
float deltat, prev_time;

void setup() {
  Wire.begin();
  Serial.begin(9600);

  check_MPU();
  check_mag();

  delay(1000);

//  get_accel_avg();
  get_gyro_avg();
//  get_mag_avg();

  prev_time = 0;
}

void loop() {
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

  Serial.print(roll); Serial.print(' '); Serial.print(pitch); Serial.print(' '); Serial.print(yaw); Serial.println();


}

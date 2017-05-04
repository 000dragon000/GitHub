#include <PS2X_lib.h>
#include <Servo.h>
#include <Wire.h> 
int l_bldc=0,l_s_bldc=0;
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
int alpha=0.8;
float roll, pitch, yaw;
float p_roll, p_pitch,p_yaw;
float q[4]={1.0f, 0.0f, 0.0f, 0.0f};
float Kp = 11.5, Ki = 0.001;
float eInt[3]={0.0,0.0,0.0};
float deltat, prev_time;
#define ps2_right ps2[2] 
#define ps2_left ps2[1]
#define ps2_circle ps2[4]
#define ps2_triangle ps2[5]
#define ps2_square ps2[0]
#define ps2_r3 ps2[6]
#define ps2_cross ps2[3]
uint8_t  ps2[]={0,0,0,0,0,0,0,0};
uint8_t  pps2[]={0,0,0,0,0,0,0,0};
Servo bldc,spin_bldc;
int pressure_pin=8;
int bldc_pin=7;
int spin_bldc_pin = 6;
int bane_spd = 0;
int pwm = 5, dirA = 17, dirB = 16;
uint8_t dataa;
int bldc_spd = 1500, spin_bldc_spd = 1500;
int bldc_limit = 1900, spin_bldc_limit = 1800;

void setup();
void loop();


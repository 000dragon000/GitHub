//#define DEBUG

#include<Servo.h>
#include<PS2X_lib.h>

//PS2 controller pins

#define CLOCK 40      //blue
#define ATTENTION 42  //green A9
#define DATA  44      //22//red A8
#define COMMAND 38    //24//yellow A7

#define BAUD_RATE 9600

PS2X ps2x;

int roll_dir_1 = 9;
int roll_dir_2 = 10;
int roll_pwm = 8;

int pitch_dir_1 = 6;
int pitch_dir_2 = 7;
int pitch_pwm = 13;

#ifdef DEBUG
int L1_pwm = 0, L2_pwm = 0, R1_pwm = 0, R2_pwm = 0;
#endif

#ifndef DEBUG
int L1_pwm = 25, L2_pwm = 70, R1_pwm = 90, R2_pwm = 200;
#endif

int bldc_pin = 3;
Servo bldc;
int bldc_spd = 1545;

int feed_pin = 4;
Servo feed;

int pressure_pin = 2;
int pressure_pos = 0;

int max_spd = 0;


/*
   SETUP FUNCTIONS

   setup_ps2
   setup_drive
   setup_RP
*/

/*
   DEBUG FUNCTIONS

   debug_ps2
   debug_drive
   debug_RP
*/

#include<PS2X_lib.h>
#include <Servo.h>
//=============================================================================
//PS2 SETUP
#define CLOCK A13
#define ATTENTION A10
#define DATA A12
#define COMMAND A11
#define BAUD_RATE 9600
//=============================================================================
int spd1 = 1500, spd2 = 1500;
Servo s1, s2, ser;
int i=0;
int pin1 = 12, pin2 = 8;
int serpin = 9;
int flag1 = 0, flag2 = 0;
int f1 = 0, f2 = 0;
int fl1 = 0, fl2 = 0;
PS2X ps2x;
boolean up = 0;
boolean down = 0;

boolean left = 0;
boolean right = 0;

boolean triangle = 0;
boolean sqr = 0;
boolean cross = 0;
boolean circle = 0;

boolean r1 = 0;
boolean r2 = 0, p_r2 = 0;

boolean l1 = 0;
boolean l2 = 0, p_l2 = 0;
boolean r3 = 0;
boolean l3 = 0;

int RY = 0;
int RX = 0;

int LY = 0;
int LX = 0;
int d = 0;
boolean start = 0;
boolean select = 0;

boolean start_flag = 0;

void readButtons();// to check the value of PS2 buttons
void incL();
void setup() {
  // put your setup code here, to run once:
  ps2x.config_gamepad(CLOCK, COMMAND, ATTENTION, DATA); // (clock(blue),command(orange), attention(yellow), data(brown))
  Serial.begin(BAUD_RATE);
  s1.attach(pin1, 800, 2000);
  s2.attach(pin2, 800, 2000);
  ser.attach(serpin);
}

void loop() {
  // put your main code here, to run repeatedly:
  control();
}

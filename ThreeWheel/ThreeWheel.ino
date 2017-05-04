#include<PS2X_lib.h>
//=============================================================================
//PS2 SETUP
int ps2_pins[4] = {A1, A2, A3, A4};

//int CLOCK = ps2_pins[3], COMMAND = ps2_pins[2], ATTENTION = ps2_pins[0], DATA = ps2_pins[1];

int CLOCK=A5, COMMAND=A4, ATTENTION=A6, DATA=A3;
#define BAUD_RATE 9600
//=============================================================================
PS2X ps2x;
#define dcv 30
#define lim 100
#define lim1 120

char ch;
int la1 = 6, la2 = 8, pwm_la = 7;
boolean up = 0, down = 0, left, right, triangle = 0, sqr = 0, cross = 0, circle = 0, r1 = 0, r2 = 0, p_r2 = 0, l1 = 0, l2 = 0, p_l2 = 0, r3 = 0, l3 = 0, start = 0, select = 0;
int RY = 0, RX, LY = 0, LX = 0;
int cl1 = 0, cl2 = 0;
float pw, fpw;
float ra = 0.47; //weight for turn X,Y
float fRY, fRX, fLY, fLX;
float a = 0.946; //weight for X,Y
float magnitude = 30, theta;
float delta = 1;
void readButtons();// to check the value of PS2 buttons
void printState(); // to print/read the value of PS2 buttons

int pwmA = 0, pwmB = 0, pwmC = 0;
int TRN_PWM = 65;
static int dir = 1;
float rpwm = 0, rpma = 0.35, frpwm = 0;
int mp_flg = 0;
boolean flag_move = 0;
static int flag = 0, rflag = 0;
static int p = 50;

float fheading, ma = 0.82;
int type = 1;

void setup()
{
  type = ps2x.config_gamepad(CLOCK, COMMAND, ATTENTION, DATA); // (clock(blue),command(orange), attention(yellow), data(brown))
  pinMode(la1, OUTPUT);
  pinMode(la2, OUTPUT);
  pinMode(pwm_la, OUTPUT);
  Serial.begin(BAUD_RATE);
  Serial1.begin(9600);
  Serial2.begin(9600);
  type = ps2x.readType();
  delay(1000);
}

void loop()
{
  type = ps2x.readType();
  if (type != 1)
  {
    off();
    while (type == 0)
    {
      type = ps2x.config_gamepad(CLOCK, COMMAND, ATTENTION, DATA);
      delay(1);
    }
  }
  else
  {
    readButtons();
    if (r1 || r2)
      pw = r1 > r2 ? TRN_PWM : -TRN_PWM;
    else
      pw = 0;
    omni();
    control(theta);
    if (up)
    {
      rpwm = rpwm + 2;
      if (rpwm > 90)
        rpwm = 90;
      //racket(rpwm);
    }
    if (down)
    {
      rpwm = rpwm - 2;
      if (rpwm <= 0)
        rpwm = 0;
      //  racket(rpwm);
    }
    frpwm = frpwm * rpma + rpwm * (1 - rpma);
    if (circle)
    {
      digitalWrite(dcv, HIGH);
      delay(1000);
      digitalWrite(dcv, LOW);
      delay(1000);
    }
    if (l1) //Raising linear actuator
    {
      linear_actuator_on1();
      cl1++;
    }
    if (l2) //Lowering linear actuator
    {
      linear_actuator_on2();
      cl2++;
    }
  }
}




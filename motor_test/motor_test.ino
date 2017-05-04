#include<PS2X_lib.h>
#include <Motor_h.h>

#define bldc_pin 12

Motor power(8, 6, 7 );
Motor sex(30, 32, 5);

PS2X ps2x;

int ps2_pins[4] = {A7, A6, A5, A4};
int CLOCK = ps2_pins[1], COMMAND = ps2_pins[2], ATTENTION = ps2_pins[0], DATA = ps2_pins[3];

void setup() {
  int error = ps2x.config_gamepad(CLOCK, COMMAND, ATTENTION, DATA);

  Serial.begin(9600);
}

void loop() {
  ps2x.read_gamepad();

  if (ps2x.Button(PSB_L1)) {                                      //Left hercules up
    power.set_direction(FRONT);
    if ( ps2x.Button(PSB_PINK))
      power.set_pwm(250);
    if (ps2x.Button(PSB_BLUE))
      power.set_pwm(60);
    else
      power.set_pwm(80);
  }
  else if (ps2x.Button(PSB_L2)) {                                 //Left hercules down
    power.set_direction(BACK);
    if ( ps2x.Button(PSB_PINK))
      power.set_pwm(250);
    if (ps2x.Button(PSB_BLUE))
      power.set_pwm(60);
    else
      power.set_pwm(80);
  }

  if (ps2x.Button(PSB_R1)) {                                      //Right polulu up
    sex.set_direction(BACK);
    if ( ps2x.Button(PSB_BLUE))
      sex.set_pwm(40);
    if(ps2x.Button(PSB_PINK))
      sex.set_pwm(200);
    else
      sex.set_pwm(100);
  }
  else if (ps2x.Button(PSB_R2)) {                                 //Right polulu down
    sex.set_direction(FRONT);
    if(ps2x.Button(PSB_BLUE))
    sex.set_pwm(254);
    else
    sex.set_pwm(120);
  }
  else
    sex.set_pwm(0);


}

#include <PS2X_lib.h>

PS2X ps2x;
int CLOCK = A4, COMMAND = A6, ATTENTION = A5, DATA = A7;
//int ps2_pins[4] = {A0,A1,A2,A3};

int pwm = 6,dirA = 5,dirB = 7;
int max_spd = 0;

void setup() {
  Serial3.begin(9600);
  Serial.begin(9600);
  
//  auto_detect(ps2_pins);
  int error = ps2x.config_gamepad(CLOCK, COMMAND, ATTENTION, DATA, false, false);
  if(error){ Serial.println("Check wiring"); while(1);}

  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);
  pinMode(pwm, OUTPUT);
}

void loop() {
//  debug_saber();
//  debug_hercules();
//while(Serial.available()){
//  int spd = Serial.parseInt();
//  digitalWrite(dirA, LOW);
//  digitalWrite(dirB, HIGH);
//  analogWrite(pwm, spd);
//}

  ps2x.read_gamepad();
  
  if (ps2x.ButtonPressed(PSB_PAD_UP))
    max_spd += 8;
  if (ps2x.ButtonPressed(PSB_PAD_DOWN))
    max_spd -= 8;

  max_spd = constrain(max_spd,0,64);
  int forward = map(ps2x.Analog(PSS_RX), 0, 255, max_spd, -max_spd);
  int rotation = map(ps2x.Analog(PSS_LX), 0, 255, ((forward == 0) ? max_spd : forward), ((-forward == 0) ? -max_spd : -forward));

  Serial.print(max_spd);Serial.print(' ');Serial.println(forward);
  
  int left = constrain(192 + forward - rotation,129,255);
  int right = constrain(64 - forward - rotation,1,127);
  Serial3.write(left);
  delay(1);
  Serial3.write(right);
  delay(1);
}


//70 backwards  58 forwards
//198 forward  186 backward
//HIGH LOW left LOW HIGH right



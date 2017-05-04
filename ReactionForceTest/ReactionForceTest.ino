#include <Servo.h>
Servo lin;
int pwm = 0;
int IR_pins[6] = {A0, A1, A2, A3, A4, A5};
int force = A7;
void setup() {
  pinMode(force, INPUT);
  for (int i = 0; i < 6; i++)
    pinMode(IR_pins[i], INPUT);

  pinMode(11, OUTPUT);
  Serial.begin(9600);//7

  //lin.attach(9);
} int flag = 0;

void loop() {

  //Serial.println(i);
  while (Serial.available())
  { //pwm=Serial.parseInt();
    flag = Serial.parseInt();
  }

  if (flag == 1) {
//
//    for (int j = 0; j < 5; j++) {
//      for (int i = 0; i <= 255; i = i + 5)
//      {
        analogWrite(11, 255);
//        delay(1);
//        int j = analogRead(force);
//        Serial.print(i); Serial.print(" ");
//        Serial.print(j); Serial.print(" ");
//        for (int m = 0; m < 6; m++) {
//          
//          Serial.print(analogRead(IR_pins[m])); Serial.print(' ');delay(1);
//        }
//        Serial.println();
//      }
//      flag = 0;
//      analogWrite(11, 0);
//      delay(100);
//    }
  }
}

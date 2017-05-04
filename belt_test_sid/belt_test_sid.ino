#include <Servo.h>

Servo servo_left,servo_right;
int servo_left_pin = 12, servo_right_pin= 8;

void setup() {
  servo_left.attach(servo_left_pin,800,2000);
  servo_right.attach(servo_right_pin,800,2000);

  Serial.begin(9600);

  servo_left.writeMicroseconds(1500);
  servo_right.writeMicroseconds(1500);
}

void loop() {
  if(Serial.available()){
    int left_spd = Serial.parseInt();
    int right_spd = Serial.parseInt();

    servo_left.writeMicroseconds(left_spd);
    servo_right.writeMicroseconds(right_spd);
  }

}

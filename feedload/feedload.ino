#include <Servo.h>

Servo s1;
int a = 4, b = 5, pwm = 6;
int p = 7, q = 72, pwm1 = 9;
bool autoload = LOW;

void setup() {

  
  Serial.begin(9600);

  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(pwm, OUTPUT);
pinMode(12, INPUT);
  pinMode(p, OUTPUT);
  pinMode(q, OUTPUT);
  pinMode(pwm1, OUTPUT);

  digitalWrite(a, LOW);
  digitalWrite(b, LOW);

  digitalWrite(p, LOW);
  digitalWrite(q, LOW);

  s1.attach(8);

  s1.write(1500);

  analogWrite(pwm, 255);
  analogWrite(pwm1, 255);
}

void loop() {
  if(autoload==HIGH)
  {
  analogWrite(pwm, 80);
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  delay(1200);
  analogWrite(pwm, 255);
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  delay(400);
  digitalWrite(a, 0);
  digitalWrite(b, 0);
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  delay(200);
  digitalWrite(a, 0);
  digitalWrite(b, 0);
  }
  int aa=digitalRead(12);
  if(aa==0){
  Serial.print(aa); Serial.println("  k");}
  if (Serial.available())
  {
    //    int spd = Serial.parseInt();
    //
    //    s1.write(spd);

    char ch = Serial.read();

    if (ch == 's') {
      //      int spd = Serial.parseInt();
      int spd = 1500;
      s1.write(spd);
      Serial.println(spd);
    }
    if (ch == 'b') {
      //      int spd = Serial.parseInt();
      int spd = 1600;
      s1.write(spd);
      Serial.println(spd);
    }
    if (ch == 'l') {
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      delay(800);
      digitalWrite(a, 0);
      digitalWrite(b, 0);
      Serial.print(HIGH); Serial.print(' '); Serial.println(LOW);
    }
    if (ch == 'f') {
      digitalWrite(p, HIGH);
      digitalWrite(q, LOW);
      delay(1062);
      digitalWrite(p, 0);
      digitalWrite(q, 0);
      Serial.print(LOW); Serial.print(' '); Serial.println(HIGH);
    }
    if (ch == 'r') {
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      delay(200);
      digitalWrite(a, 0);
      digitalWrite(b, 0);
      Serial.print(LOW); Serial.print(' '); Serial.println(HIGH);
    }
  }
}




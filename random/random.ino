void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial3.begin(9600);
}
int x=0;
void loop() {
  // put your main code here, to run repeatedly:
  x=random(50);
Serial.println(x);
Serial3.write(64+x);
delay(1);
x=random(50);
Serial3.write(192+x);
delay(1);
 x=random(50);
Serial3.write(64-x);
delay(1);
x=random(50);
Serial3.write(192-x);
delay(1);
}

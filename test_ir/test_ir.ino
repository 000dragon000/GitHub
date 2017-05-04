void setup() {
 Serial.begin(115200);
 pinMode(A0,INPUT);
 pinMode(A1,INPUT);
 pinMode(A2,INPUT);
 pinMode(A3,INPUT);
 pinMode(A4,INPUT);
 pinMode(A5,INPUT);
 pinMode(A6,INPUT);
  pinMode(13,OUTPUT);//A2,A4,A0,A5,A6,A3,A1
}

void loop() {
//
//  Serial.print(digitalRead(A0));
//
//  Serial.print(' ');Serial.print(analogRead(A0)); Serial.print(' ');Serial.print(digitalRead(A1));Serial.print(' ');Serial.print(analogRead(A1)); Serial.print(' ');Serial.print(digitalRead(A2));Serial.print(' ');Serial.print(analogRead(A2)); Serial.print(' '); 
//Serial.print(digitalRead(A3));Serial.print(' ');Serial.print(analogRead(A3)); Serial.print(' '); Serial.print(digitalRead(A4));Serial.print(' ');Serial.print(analogRead(A4)); Serial.print(' ');Serial.print(digitalRead(A5));Serial.print(' ');Serial.print(analogRead(A5));Serial.print(' ');
//Serial.print(digitalRead(A6));Serial.print(' ');Serial.println(analogRead(A6));

digitalWrite(13,1);
Serial.print(analogRead(A2));Serial.print(' ');
Serial.print(analogRead(A4));Serial.print(' ');
Serial.print(analogRead(A0));Serial.print(' ');
Serial.print(analogRead(A5));Serial.print(' ');
Serial.print(analogRead(A6));Serial.print(' ');
Serial.print(analogRead(A3));Serial.print(' ');
Serial.print(analogRead(A1));Serial.print(' ');
Serial.println();
delayMicroseconds(100);
}

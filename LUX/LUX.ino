void setup() {
//String a[]={A0,A1,A2,A3,A4};

pinMode(A1,INPUT);//a3  a4 a1 a0
pinMode(A0,INPUT);
pinMode(A3,INPUT);
pinMode(A4,INPUT);


Serial.begin(9600);
}
void loop(){

Serial.print(analogRead(A3));Serial.print(" ");
Serial.print(analogRead(A4));Serial.print(" ");
Serial.print(analogRead(A1));Serial.print(" ");
Serial.print(analogRead(A0));Serial.print(" ");Serial.print(" kite  ");Serial.print(" ");
Serial.print(digitalRead(A3));Serial.print(" ");
Serial.print(digitalRead(A4));Serial.print(" ");
Serial.print(digitalRead(A1));Serial.print(" ");
Serial.print(digitalRead(A0));Serial.print(" ");
Serial.println();
}

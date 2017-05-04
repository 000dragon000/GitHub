void setup() {
  pinMode(51,OUTPUT);
  digitalWrite(51,1);
pinMode(53,INPUT_PULLUP);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(digitalRead(53));
delay(10);
}

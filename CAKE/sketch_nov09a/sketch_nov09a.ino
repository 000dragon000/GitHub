void setup() {
 pinMode(31,INPUT);
 Serial.begin(9600);
}


void loop() {
Serial.println(digitalRead(31));
}

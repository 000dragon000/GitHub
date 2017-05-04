
void setup() {
  Serial.begin(9600);
  pinMode(44,OUTPUT);//pwn
   pinMode(40,OUTPUT);//40
    pinMode(38,OUTPUT);//
     pinMode(A3,INPUT);//
        digitalWrite(40, HIGH);
    digitalWrite(38, LOW);
      analogWrite(44, 50);
}

void loop() {
  int volatge = analogRead(A3);
  float voltage = voltage * (5.0 / 1023.0);
  Serial.println(voltage);

     delay(1000);
}

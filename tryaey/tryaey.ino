void setup() {
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    int  spd = Serial.parseInt();
    spd = constrain(spd, 0, 254);

    digitalWrite(6, HIGH);
    digitalWrite(4, LOW);
    analogWrite(5, spd);
    
    delay(map(spd,0,255,1000,400));
    
    digitalWrite(6, HIGH);
    digitalWrite(4, HIGH);
    analogWrite(5, 0);
  }
}



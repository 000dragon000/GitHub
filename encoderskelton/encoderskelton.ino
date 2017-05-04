int q=21;
int w=20;
int e=22;
int r=23 ;

void setup() {
 pinMode(q,INPUT_PULLUP);
 pinMode(w,INPUT_PULLUP);
 pinMode(e,INPUT_PULLUP);
 pinMode(r,INPUT_PULLUP);
 Serial.begin(9600);
}
void loop() {
 Serial.print(digitalRead(q));
 Serial.print(digitalRead(w));
  Serial.print(" ");
   Serial.print(digitalRead(e));
    Serial.print(digitalRead(r));
      Serial.println();
      delay(1);

}

int an_pins[4] = {A1, A3, A4,A8};
void setup() {
for(int i=0;i<3;i++)
pinMode(an_pins[i],INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=0;i<4;i++){
int k=analogRead(an_pins[i]);
Serial.print(k);Serial.print(' ');}
Serial.println();
delay(100);
}


void setup() {
  Serial.begin(9600);
int c=0;
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(c);
c++;
delay(100);
if c>300
c=0;
}

      void setup() {
 for (int i=34;i<=47;i++)
 pinMode(i,INPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
for (int i=34;i<=47;i++)
{Serial.print(digitalRead(i));Serial.print(" ");}
Serial.println();
}

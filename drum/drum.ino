void setup() {
String a[]={A0,A1,A2,A3,A4};
for(int i=0;i<4;i++)
pinMode(a[i],INPUT);
Serial.begin(9600);
}
void loop(){
for(int i=0;i<4;i++)
{Serial.print(analogRead(a[i]));Serial.print(" ");}
for(int i=0;i<4;i++)
{Serial.print(digitalRead(a[i]));Serial.print(" ");}
Serial.println();
}

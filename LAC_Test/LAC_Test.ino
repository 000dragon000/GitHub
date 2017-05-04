int lin1=2;
//int lin2=7;
void setup() {
 pinMode(lin1,OUTPUT);
  //pinMode(lin2,OUTPUT);
 Serial.begin(9600);
}
int pos1=0;
int pos2=0;
void loop() {
  if(Serial.available())
 { pos1=Serial.parseInt();
  //pos2=Serial.parseInt();
  Serial.println(pos1);//Serial.print(" ");Serial.println(pos2);}
  analogWrite(lin1,pos1);
  //analogWrite(lin2,pos2);
 }}

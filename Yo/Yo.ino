int flag=420;
//Sail test code 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(18,OUTPUT);
  pinMode(19,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(21),hey,RISING);
  attachInterrupt(digitalPinToInterrupt(20),bye,FALLING);
  

}
double lt,pt,t;
void hey()
{
  flag=1;
  
  
}
void bye()
{
  flag=0;
  //Serial.println("Go");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.print(digitalRead(21));Serial.print("    ");
  //Serial.println(digitalRead(20));
  if(flag==1)
  {
    pt=millis();
    Serial.print(pt,4);Serial.print("   ");
    flag=420;
  }
  
  if(flag==0)
  {lt=millis();
    t=lt-pt;
  Serial.print(lt,4);  Serial.print(" ");  Serial.println(t/1000,4);
  flag=420;  
}
}

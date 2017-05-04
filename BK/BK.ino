
int l[9]={15,22,23,21,20,19,18,13,14,A14};


Servo servo;

void setup() 
{
  for(int i=0;i<9;i++)  
    pinMode(l[i],INPUT); 
  
  Serial.begin(9600);
  }

void loop() 
{    
or(int i=0;i<9;i++)
{ Serial.print(digitalRead(l[i]));
delay(10);
}
Serial.print();
}


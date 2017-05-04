

int l[9]={14,13,19,18,20,21,23,22,15};
int a[9];



void setup() 
{
  for(int i=0;i<9;i++)  
    pinMode(l[i],INPUT_PULLUP); 
    Serial.begin(9600);
}
void loop() 
{    
for(int i=0;i<9;i++)
{ 
 Serial.print(digitalRead(l[i]));
}
Serial.println();
}




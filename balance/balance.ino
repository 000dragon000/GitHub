double transx=0;
int rt=0;
void setup()
{ Serial.begin(9600);  
  gyrosetup();
  setuppid();
  servosetup();
}
void loop()
{
  gyro();
  pid(transx);
  servoloop(rt);  
}

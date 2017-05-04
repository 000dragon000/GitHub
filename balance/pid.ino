#include <PID_v1.h>
double Setpoint, Input, Output;
//Specify the links and initial tuning parameters
int x;
PID myPID(&Input, &Output, &Setpoint,0.3,0.6,0.1, DIRECT);
void setuppid()
{
  //initialize the variables we're linked to
    Setpoint = 90;
  //turn the PID on
  myPID.SetMode(AUTOMATIC);
}

void pid(int k)
{
  Input = k;
  myPID.Compute();
  rt=Output;
}



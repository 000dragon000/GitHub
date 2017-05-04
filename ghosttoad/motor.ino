void motorA(int t)
{
  if(t!=0){
    t = t-5;
  }
  if(t>lim)
    t=lim;
  if(t<-lim)
    t=-lim;
  int var=map(t,100,-100,0,127);
  Serial3.write(var);
}
void motorB(int t)
{
  if(t>lim)
    t=lim;
  if(t<-lim)
    t=-lim;
  int var=map(t,100,-100,128,255);
  Serial3.write(var);
}


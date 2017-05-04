#include <TimerOne.h>
#define encR_A 21
#define encR_B 20
#define encL_A 22
#define encL_B  23
int lim=30;
volatile  int encR_pos = 0;
volatile  int encL_pos = 0;
int lastR;
int lastL;
const int led = LED_BUILTIN;    // the number of the LED pin
int ledState = LOW;
volatile unsigned long blinkCount = 0;
/// Variables will change :
            // ledState used to set the LED
// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated
// constants won't change :
const long interval = 1000;           // interval at which to blink (milliseconds)
double l=36.5;
double r=6.125;
double tt;
double a=0;
double b=0;
double rr;
double x;
double y;
double bx;
double by;
double ax;
double ay;
double bb;
double aa;
unsigned long bblinkCopy=0;
double time1;
 double time2;
 double pt1;
  double pt2;
  double kpa=1,kpb=1;
  double pida=0,pidb=0;
  double errora,errorb;
int cpr;
int cpm;
void setup() {
  Serial3.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(encR_B, INPUT);
  pinMode(encR_A, INPUT);
  pinMode(encL_B, INPUT);
  pinMode(encL_A, INPUT);
  attachInterrupt(digitalPinToInterrupt(encR_A), encR, RISING);
  attachInterrupt(digitalPinToInterrupt(encL_A), encL, RISING);
  Serial.begin (115200);
  Serial.println("start");
  delay(10);
  Timer1.initialize(1000);
  Timer1.attachInterrupt(blinkLED);
  int ledState = LOW;
volatile unsigned long blinkCount = 0;
  //  Serial1.write(32);
}
void blinkLED(void)
{   
  if (ledState == LOW) {
    ledState = HIGH;
    blinkCount = blinkCount + 1;  // increase when LED turns on
  } else {
    ledState = LOW;
  }
  digitalWrite(led, ledState);
}
void rev()
{
 a=(2*PI*r*encR_pos)/3326;
 b=(2*PI*r*encL_pos)/3326;
} 
void encR()
{
  if (digitalRead(encR_B)) encR_pos++;
  else encR_pos--;
}
void encL()
{
  if (digitalRead(encL_B)) encL_pos++;
  else encL_pos--;
}
//void xxyy()
//{
//  if (a!=b)
//  {rr=(a*l)/(b-a);
//  tt=(b-a)/l;
//  y=(l/2+rr)*sin(tt); 
//  x=(l/2+rr)*cos(tt);
//  ay=rr*sin(tt);
//  ax=rr*cos(tt);
//  bx=(rr+l)*cos(tt);
//  by=(rr+l)*sin(tt);
//  } 
//}
 
void loop()
{  unsigned long blinkCopy=0; 
   rev();
  // xxyy();   
   //xxyy();

  lastR = encR_pos;
  lastL = encL_pos;
   noInterrupts();
   blinkCopy = blinkCount;
  interrupts();
  //
  double k=blinkCopy;
  aa=(317*k-424780)/29480;
  bb=(203*k-272020)/22110;
 // aa=((317)*(k)−424780)/29480);
  //bb=((203*k-272020)/22110);
  if (blinkCopy<1340)
  {aa=0;bb=0;}
  if (blinkCopy>10184)
  {aa=95.1;bb=(406/5);}
  errora=aa-a;
  errorb=bb-b;
  pida=kpa*errora;
  pidb=kpb*errorb;
   if (pida<-20)
  {pida=-20;}
  if (pida>20)
  {pida=20;} 
  if (pidb<-20)
  {pidb=-20;}
  if (pidb>20)
  {pidb=20;}
 motorA(pida);
 motorB(pidb);
   if (!(bblinkCopy==blinkCount)&&(blinkCount<=60000))
  {
  // Serial.print(blinkCopy);Serial.print(" ");Serial.print(encR_pos); Serial.print(" "); Serial.print(encL_pos); Serial.print(" ");  Serial.print(a); Serial.print(" "); Serial.print(b);Serial.print(" "); Serial.print(x); Serial.print(" "); Serial.print(y);Serial.print(" "); Serial.print(ax); Serial.print(" "); Serial.print(ay);Serial.print(" "); Serial.print(bx); Serial.print(" "); Serial.println(by);
 Serial.print(blinkCopy);Serial.print(" ");  Serial.print(aa); Serial.print(" "); Serial.print(a);Serial.print(" ");  Serial.print(pida); Serial.print(" "); Serial.println(pidb);
  }
  bblinkCopy=blinkCopy;
  
  //Serial.print(digitalRead(encR_A)); delayMicroseconds(10); Serial.println(digitalRead(encR_B)); delayMicroseconds(10);Serial.print('\t');
  //Serial.print(digitalRead(encL_A)); delayMicroseconds(10); Serial.println(digitalRead(encL_B)); delayMicroseconds(10

}





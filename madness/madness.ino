#include <Servo.h>
 double angle=90;
double y,x;
int z=0;
 double air[]={0,0,0,0,0,0};
     int  a1 =   2.663e+04 ;
     int  b1 =   5.899e-05 ;
     int  c1 =     -0.3707 ;
      int a2 =   1.178e+04 ;
     int   b2 =   8.543e-05 ;
      int  c2 =       -4.06 ;
      int  a3 =   3.334e+04 ;
     int  b3 =   0.0004004 ;
      int c3 =      -4.159 ;
      int  a4 =   3.305e+04 ;
     int  b4 =   0.0004018 ;
     int   c4 =      -7.287 ;
      int  a5 =       140.9 ;
      int b5 =   0.0009693 ;
   int    c5 =     -0.9966 ;
       int a6 =       135.1 ;
     int  b6 =    0.001193 ;
   int    c6 =     -0.0531 ;
       int a7 =       81.43 ;
     int  b7 =    0.001854 ;
  int     c7 =      -2.398 ;
      int a8 =       89.76 ;
   int    b8 =    0.002894 ;
int     c8 =     -0.3543 ;

int q=7;
int w=6;
int e=9;
int r=8;
int key=0;
int lcountl=0,lcountr=0;
#define trigPin 4
#define echoPin 3
#define ser 5
int pos = 0;
int flag = 0;
int ls = 60 ;
int rs = 120 ;
int pn = ls;
int t = 123;
int k=0,count;
volatile int countL = 0;//4100 6000 4000
volatile int countR = 0;
Servo steer;
void setup() {
 pinMode(q,INPUT_PULLUP);
 pinMode(w,INPUT_PULLUP);
 pinMode(e,INPUT_PULLUP);
 pinMode(r,INPUT_PULLUP);
 Serial.begin(115200);
 attachInterrupt(digitalPinToInterrupt(6), doEncoder1, RISING);
 attachInterrupt(digitalPinToInterrupt(8), doEncoder2, RISING);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(ser, OUTPUT);
  steer.attach(5);
// while(countL>-4100&&countR>-4100)
// { steer.write(80);//calibrating to actual 90
//  delay(10);}
 
 }
void doEncoder1()
{
  if (digitalRead(7))
    countR++;
  else
    countR--;
}

void doEncoder2()
{
  if (digitalRead(9))
    countL--;
  else
    countL++;
}
void loop() {

  while(lcountl-countL==0&&lcountr-countR==0);
  angle=(countL-countR)/(2*43.2);
  Serial.print(countL);Serial.print("  ");  Serial.print(countR); Serial.print("  ");  Serial.println(angle); 
 delay(1);
  lcountl=countL;
  lcountr=countR;
  
}

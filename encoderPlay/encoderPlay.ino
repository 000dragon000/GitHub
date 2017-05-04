#include <TimerOne.h>
#include <spline.h>
#include <SD.h>
#include <SPI.h>
String s[3];
int count=0;
Spline aCurve;
Spline bCurve;
 //float bs[23] ={0,0,54.4, 78.95 ,124.9 ,193.12, 210.2 ,269.86, 315.06 ,363.16, 426.97, 478.82, 585.35, 684.05, 752.53, 787.29, 821.23,   826.41,  851.44, 897.98, 936.35, 989.01 ,1032.11 };
 //float as[23] ={ 0,  0.04 , 54.97 ,78.15 ,  124.81,  199.67,  218.41 , 281.78 , 334.65 , 380.9 ,  457.28 , 509.56 , 606.96,  694.18 , 758.53  ,771.66  ,774.92  ,777.6,   797.32,  840.75,  911.05,  929.12,  973.48 };
 //float ts[23]={0,7729 ,11199, 12086 ,14014,15865 ,16294 ,17678, 18526, 19329, 20454 ,21393, 23192, 24812, 25853, 26509 ,27253 ,27355, 28164, 29092, 30404, 31136,31946 };

float ts[51]={0,6865,9130,10036,11496,11770,12181,12500,13048,13733,14280,14828,15558,16289,16471,16562,16973,17384,17521,18069,18479,18616,18844,19164,19575,19712,20259,20670,20896,21127,21400,21811,22176,22405,22633,22952,23637,23956,24322,24687,25234,25965,26193,26649,27106,27562,28064,28521,29023,29525,29844};
float os[51]={0,0.03 ,1.71 ,-0.87 ,0.41 ,2.77 ,9.04 ,14.43 ,15.89, 14.52, 20.76, 27.02 ,30.7 ,33.25, 37.74, 40.08, 47.31, 45.63, 44.38 ,45.63 ,41.7 ,36.99 ,29.11 ,26.37 ,25.8 ,28.42 ,31.17 ,29.67 ,27.39 ,20.48 ,13.06, 9.85, 9.16 ,10.53 ,11.84 ,-3.8, -30.35 ,-47.9 ,-62.58 ,-80.94 ,-93 ,-92.65, -88.14 ,-84.49 ,-78.94 ,-67.41 ,-53.57 ,-45.81 ,-42.7 ,-42.54 ,-43.29};
float rs[51]={0,-26.74 ,-72.49 ,-102.12 ,-156.58 ,-172.22 ,-191.92 ,-203.67 ,-232.87 ,-265.71 ,-295.55 ,-322.38 ,-368.36 ,-415.54 ,-427.3 ,-432.93 ,-458.56 ,-483.3 ,-491.29 ,-526.91, -553.93 ,-561.64 ,-573.39 ,-586.84 ,-604.92 ,-610.61 ,-634.79 ,-654.36, -665.9 ,-679.74 ,-694.39 ,-717.25 ,-741.02, -755.87, -768.67, -779.59 ,-805.71 ,-813.37 ,-828.76 ,-843.22, -876.14 ,-924.16 ,-942.05 ,-981.09 ,-1024.41 ,-1064.93 ,-1105.65 ,-1144.74 ,-1180.86 ,-1203.69 ,-1213.15};
float as[51];
float bs[51];

#define encR_A 20
#define encR_B 21
#define encL_A 23
#define encL_B  22
int lim=30;
volatile  int encR_pos = 0;
volatile  int encL_pos = 0;
int lastR;
int lastL;
const int led = LED_BUILTIN;    // the number of the LED pin
int ledState = LOW;
volatile unsigned long blinkCount = 0;unsigned long previousMillis = 0;        // will store last time LED was updated
// constants won't change :
const long interval = 1000;           // interval at which to blink (milliseconds)
float l=36.5;
float r=6.125;
float tt;
float a=0;
float b=0;
double rr;
double x;
double y;
double bx;
double by;
double ax;
double ay;
float bb;
float aa;
unsigned long bblinkCopy=0;
double time1;
 double time2;
 double pt1;
  double pt2;
  double kpa=5,kpb=5;
  double pida=0,pidb=0;
  double errora,errorb;
int cpr;
int cpm;
void setup() {
// for(int i=0;i<23;i++)
//{ts[i]=ts[i]/1;
//}
//for (int i=0;i<51;i++)
//{as[i]=rs[i]-l*os[i]*PI/2/180;
// bs[i]=rs[i]+l*os[i]*PI/2/180;
//  }
//  aCurve.setPoints(ts,as,23);
//  aCurve.setDegree( Catmull );
//  bCurve.setPoints(ts,bs,23);
//  bCurve.setDegree( Catmull );
  Serial3.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(encR_B, INPUT_PULLUP);
  pinMode(encR_A, INPUT_PULLUP);
  pinMode(encL_B, INPUT_PULLUP);
  pinMode(encL_A, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encR_A), encR, RISING);
  attachInterrupt(digitalPinToInterrupt(encL_A), encL, RISING);
  Serial.begin (115200);
  Serial.println("start");
  delay(10);
  Timer1.initialize(1000);
  Timer1.attachInterrupt(blinkLED);
  int ledState = LOW;
volatile unsigned long blinkCount = 0;
   File dataFile = SD.open("datalog.txt");
  // if the file is available, write to it:
  if (dataFile) {
    while (dataFile.available()) {
      int c=dataFile.read();
      
       if((c!='\n')&&(c!=','))
      {    
        s[count]+=(char)c;
       }
      else{Serial.print(s[count].toFloat());Serial.print(",");count++;if(count==3){Serial.println();count=0;}s[count]="";}
      }
    dataFile.close();
  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  } 
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
 a=(2*PI*r*encR_pos)/3261;
 b=(2*PI*r*encL_pos)/3275;
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
// 
//double a1 = 3.00813804831251E+02;
//double b1 = -1.09350886376057E+00;
//double c1 = 6.77485093365134E-04;
//double d1 = 5.84888889958375E-07;
//double e1 = -7.59303592017213E-10;
//double f1 = 3.13460249966972E-13;
//double g1 = -6.52482564602787E-17;
//double h1 = 7.75419254649868E-21;
//double i1 = -5.35295604221793E-25;
//double j11 = 2.00077953766350E-29;
//double k1 = -3.13261096435191E-34;
//
//double a2 =  9.84625592191116E+05;
//double b2 = -1.82047952807883E+03;
//double c2 = 1.50296054102942E+00;
//double d2 = -7.27452245526671E-04;
//double e2 = 2.26750096694569E-07;
//double f2 = -4.64963373718772E-11;
//double g2 = 5.89208078602510E-15;
//double h2 = -2.94528077140121E-19;
//double i2 = -4.49683101433591E-23;
//double j2 = 1.18479425696094E-26;
//double k2 = -1.37977578103336E-30;
//double l2 = 1.00802268307598E-34;
//double m2 = -4.86037460826407E-39;
//double n2 = 1.50758778773571E-43;
//double o2 = -2.72985073545359E-48;
//double p2 = 2.19005338651512E-53;
//
//double a3 =1.34615507200580E+06;
//double b3 =-2.60559284489223E+03;
//double c3 =2.28713168907361E+00;
//double d3 =-1.20533791053678E-03;
//double e3 =4.25494454417484E-07;
//double f3 =-1.06253856119006E-10;
//double g3 =1.93143585595944E-14;
//double h3 =-2.58837846423158E-18;
//double i3 =2.55834403366937E-22;
//double j3 =-1.84281604526665E-26;
//double k3 =9.40783135438360E-31;
//double l3 =-3.22522188538710E-35;
//double m3 =6.65878384410135E-40;
//double n3 =-6.25659732155628E-45;


//float o2 = 4.26327331722223E-48;




void loop()
{  unsigned long blinkCopy=0; 
   
  
   noInterrupts();
   blinkCopy = blinkCount;
  interrupts();
 a=(2*PI*r*encR_pos)/3450;
 b=(2*PI*r*encL_pos)/3450;
  float k=blinkCopy;
  //y =PW:a+bx+cx2 +dx3
  //aa=a1+b1*k+c1*k*k+d1*k*k*k+e1*pow(k,4)+f1*pow(k,5)+g1*pow(k,6)+h1*pow(k,7)+i1*pow(k,8)+j11*pow(k,9)+k1*pow(k,10);
 // bb=a2+b2*k+c2*k*k+d2*k*k*k+e2*pow(k,4)+f2*pow(k,5)+g2*pow(k,6)+h2*pow(k,7)+i2*pow(k,8)+j2*pow(k,9)+k2*pow(k,10)+l2*pow(k,11)+m2*pow(k,12)+n2*pow(k,13)+o2*pow(k,14)+p2*pow(k,15);
 // aa=a3+b3*k+c3*k*k+d3*k*k*k+e3*pow(k,4)+f3*pow(k,5)+g3*pow(k,6)+h3*pow(k,7)+i3*pow(k,8)+j3*pow(k,9)+k3*pow(k,10)+l3*pow(k,11)+m3*pow(k,12)+n3*pow(k,13);//+o3*pow(k,14)+p3*pow(k,15);
  //aa=(317*k-424780)/29480;
  //bb=(203*k-272020)/22110;
 // aa=((317)*(k)−424780)/29480);
  //bb=((203*k-272020)/22110);
  // aa=aa-12.73;
  //bb=bb-180.63; 
  aa=aCurve.value(k);
  bb=bCurve.value(k);
 //Serial.print(aa); Serial.print(" "); Serial.print(bb); Serial.print(" "); Serial.println(k); 
  if (k<6865)
  aa=as[1];
  else if (k>29844)
  aa=as[52];
  if (k<6865)
  bb=bs[1];
  else if (k>29844)
  bb=bs[52];
  errora=aa-a;
  errorb=bb-b;
  pida=kpa*errora;    
  pidb=kpb*errorb;
   if (pida<-30)
  {pida=-30;}
  if (pida>30)
  {pida=30;} 
  if (pidb<-30)
  {pidb=-30;}
  if (pidb>30)
  {pidb=30;}
  motorA(-pida);
  motorB(-pidb);
   if (!(bblinkCopy==blinkCount)&&(blinkCount<=60000))
  {
  // Serial.print(blinkCopy);Serial.print(" ");Serial.print(encR_pos); Serial.print(" "); Serial.print(encL_pos); Serial.print(" ");  Serial.print(a); Serial.print(" "); Serial.print(b);Serial.print(" "); Serial.print(x); Serial.print(" "); Serial.print(y);Serial.print(" "); Serial.print(ax); Serial.print(" "); Serial.print(ay);Serial.print(" "); Serial.print(bx); Serial.print(" "); Serial.println(by);
 //Serial.print(blinkCopy);Serial.print(" ");  Serial.print(encR_pos); Serial.print(" "); Serial.print(encL_pos);Serial.print(" ");  Serial.print(a); Serial.print(" "); Serial.print(b);Serial.print(" ");  Serial.print(aa); Serial.print(" "); Serial.print(bb);Serial.print(" ");  Serial.print(pida); Serial.print(" "); Serial.println(pidb);
  }
  bblinkCopy=blinkCopy; 
    //Serial.print(digitalRead(encR_A)); delayMicroseconds(10); Serial.println(digitalRead(encR_B)); delayMicroseconds(10);Serial.print('\t');
  //Serial.print(digitalRead(encL_A)); delayMicroseconds(10); Serial.println(digitalRead(encL_B)); delayMicroseconds(10
lastR = encR_pos;
  lastL = encL_pos;
}





#include <Servo.h>
double angle = 90;

#define trigPin 4
#define echoPin 3
#define trigPin1 11
#define echoPin1 12
int En1A = 8;
int En1B = 9;
int En2A = 7;
int En2B = 6;
int lcountl, lcountr;
volatile int count1 = 0;
volatile int count2 = 0;

double pi = 3.14159271, wheelDiameter = 74, trackWidth = 432 , countsPerRevolution = 1000;
double  Distance = 0, radiansPerCount = 0.00057468, countsPerRotation = 0, Heading = 0, X = 0, Y = 0, tHeading = 0, absHead = 0;
float thetaD = 55;

double distancePerCount = 0.2356;
int z = 0;
int q = 7;
int w = 6;
int e = 9;
int r = 8;
int i = 0;
#define ser 5
int pos = 0;
int flag = 0;
int ls = 60 ;
int rs = 120 ;
int pn = ls;
int t = 123;
int k = 0, count;
int ll = 0;
volatile int countL = 0;//4100 6000 4000
volatile int countR = 0;
Servo steer;
void setup() {
  pinMode(q, INPUT_PULLUP);
  pinMode(w, INPUT_PULLUP);
  pinMode(e, INPUT_PULLUP);
  pinMode(r, INPUT_PULLUP);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(6), doEncoder1, RISING);
  attachInterrupt(digitalPinToInterrupt(8), doEncoder2, RISING);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(ser, OUTPUT);
  steer.attach(5);
  countL = 0;
  countR = 0;
   while (countL < 3000 && countR < 3000)
    steer.write(83);//calibrating to actual 90
  delay(100);
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
  // Serial.print(digitalRead(q));
  // Serial.print(digitalRead(w));
  // Serial.print(" ");
  // Serial.print(digitalRead(e));
  // Serial.print(digitalRead(r));
  // Serial.println();
  //if (count<6)
  //{
  ////Serial.print(countL);Serial.print(" ");Serial.println(countR);
  //

  Distance = ((countL + countR) / 2) * distancePerCount;
  //countsPerRotation = (trackWidth / wheelDiameter) * countsPerRevolution;
  // radiansPerCount = Pi * (wheelDiameter/trackWidth) / countsPerRevolution ;
  Heading = (countL - countR) * radiansPerCount;

  Y = (Distance * cos(Heading)) / 10;
  X = (Distance * sin(Heading)) / 10;

  tHeading = ((Heading * 180 ) / 3.1415927);
//
//  Serial.print(X);
//  Serial.print("\t");
//  Serial.print(Y);
//  Serial.print("\t");
//  Serial.println(tHeading);



  //-------------------------------------------------
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;//loop dis
  long duration1, distance1;
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1 / 2) / 29.1;//loop dis
  //while (lcountl - countL == 0 && lcountr - countR == 0);
  angle = (countL - countR) / 43.4;
int c=0;
 Serial.print(countL); Serial.print("  ");  Serial.print(countR); Serial.print("  "); Serial.print(distance); Serial.print("  "); Serial.print(distance1); Serial.print("  "); Serial.println(angle);
  int l = distance1;
  int r = distance;
  if ((1<9&&r<9))
  { steer.write(85-i);
      i++;c=1;
      if (angle>36)
      c=0;
       }
  if (l < 9&&c==0)
   { steer.write(85-17);}
     else
    steer.write(85 + 17);
  if (r < 10&&c==0)
    steer.write(85 + 17);
  else
    steer.write(85 - 17);
    
    
//  if (countL > 25410 && countR > 25460 && k == 0)
//  { steer.write(85 - 60); delay(50);
//    k = 1;
    
    while(Y>600&&Y<620)
      { 
        steer.write(75-i);
       i++;
       if(i==60)
       break;
      }
      steer.write(85);
//    while (angle < 72 && l )
//      steer.write(85 + i);
//    i++;
//  }

  ll = l;
}





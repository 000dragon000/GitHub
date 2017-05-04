#include <Servo.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

#define BNO055_SAMPLERATE_DELAY_MS (100)
Adafruit_BNO055 bno = Adafruit_BNO055(55);

double angle = 90;
double angle1=90;
int lcountl = 0, lcountr = 0;
#define trigPin 4
#define echoPin 3
#define trigPin1 11
#define echoPin1 12
int En1A = 8;
int En1B = 9;
int En2A = 7;
int En2B = 6;
int lcountL,lcountR;
volatile int count1 = 0;
volatile int count2 = 0;

double pi = 3.14159271, wheelDiameter = 74, trackWidth =432 , countsPerRevolution = 1000;
double  Distance = 0, radiansPerCount = 0.006283, countsPerRotation = 0, Heading = 0, X = 0, Y = 0, tHeading = 0, absHead = 0;
float thetaD = 55;
double distancePerCount = 0.2356;
int z = 0;
int q = 7;
int w = 6;
int e = 9;
int r = 8;
#define ser 5
int pos = 0;
int flag = 0;
int ls = 60 ;
int rs = 120 ;
int pn = ls;
int t = 123;
int k = 0, count;
volatile int countL = 0;//4100 6000 4000
volatile int countR = 0;
Servo steer;

void setup() 
{
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
 // while(countL<3000&&countR<3000)
  steer.write(83);//calibrating to actual 90
  
//  Serial.begin(9600);
  Serial.println("");
  Serial.println("Orientation Sensor Test"); 
  Serial.println("");
  if(!bno.begin())
  {
    Serial.print("Error!");
    while(1);
  }

  delay(1000);
//  displaySensorDetails();
//  displaySensorStatus();
  bno.setExtCrystalUse(true);
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

//void displaySensorStatus(void)
//{
//  uint8_t system_status, self_test_results, system_error;
//  system_status = self_test_results = system_error = 0;
//  bno.getSystemStatus(&system_status, &self_test_results, &system_error);
//  Serial.println("");
//  Serial.print("System Status: 0x");
//  Serial.println(system_status, HEX);
//  Serial.print("Self Test:     0x");
//  Serial.println(self_test_results, HEX);
//  Serial.print("System Error:  0x");
//  Serial.println(system_error, HEX);
//  Serial.println("");
//  delay(500);
//}
//
//void displayCalStatus(void)
//{
//  uint8_t system, gyro, accel, mag;
//  system = gyro = accel = mag = 0;
//  bno.getCalibration(&system, &gyro, &accel, &mag);
//  Serial.print("\t");
////  if (!system)
////  {
////    Serial.print("! ");
////  }
////  Serial.print("Sys:");
////  Serial.print(system, DEC);
////  Serial.print(" G:");
////  Serial.print(gyro, DEC);
////  Serial.print(" A:");
////  Serial.print(accel, DEC);
////  Serial.print(" M:");
////  Serial.print(mag, DEC);
//}

void loop() 
{
  // Serial.print(digitalRead(q));
  // Serial.print(digitalRead(w));
  // Serial.print(" ");
  // Serial.print(digitalRead(e));
  // Serial.print(digitalRead(r));
  // Serial.println();
  //if (count<6)
  //{
  ////Serial.print(countL);Serial.print(" ");Serial.println(countR);
  
  sensors_event_t event;
  bno.getEvent(&event);
  
  Serial.print("X - Horizontal: ");
  Serial.print(event.orientation.x, 4);
  Serial.print("\tY - Vertical: ");
  Serial.print(event.orientation.y, 4);
  Serial.print("\tZ - Twist: ");
  Serial.print(event.orientation.z, 4);
  Serial.print(" "); 
  delay(100);
  
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
  angle=(countL-countR)/43.4;
  //while (lcountl - countL == 0 && lcountr - countR == 0);
   
//   Distance = ((countL + countR) / 2) * distancePerCount;
//  //countsPerRotation = (trackWidth / wheelDiameter) * countsPerRevolution;
//  Heading = (countL - countR )* radiansPerCount;
//   Y = Distance * cos(Heading);
//  X = Distance * sin(Heading);
//  tHeading = (Heading * 180 / 3.1415927);
   
  
  int l=distance1;
  int r=distance;
 
//angle=(countL-countR)/43.2;
//angle1=atan((lcountL-Y)/(lcountR-X));
Serial.print("L: ");
Serial.print(countL); 
Serial.print(" R: ");  
Serial.print(countR);
Serial.print(" Dist1: "); 
Serial.print(distance);
Serial.print(" Dist2: "); 
Serial.print(distance1);
Serial.print(" Angle: "); 
Serial.print(angle);
Serial.print(" Y: "); 
Serial.print(Y);
Serial.print(" X: "); 
Serial.println(X);
//Serial.print(" AngleRad: ");
//Serial.println(angle1*180/PI);

if(l<10)
steer.write(85-17);
else
steer.write(85+17);

if(r<10)
steer.write(85+17);
else
steer.write(85-17);

if(countL>25410&&countR>25460&&k==0)
  {steer.write(85-60);delay(1000);
  k=1;
while(angle<72)
steer.write(85);
  }

lcountL=Y;
lcountR=X;
  
}

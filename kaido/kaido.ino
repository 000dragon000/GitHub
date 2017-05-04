#include <Servo.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#define BNO055_SAMPLERATE_DELAY_MS (100)
Adafruit_BNO055 bno = Adafruit_BNO055(55);
double angle = 90;
#define trigPin 4
#define echoPin 3
#define trigPin1 11
#define echoPin1 12
int lcountl=0,lcountr=0;
long lll,rrr;
double langle=85;
int c = 0;
int kite = 0;
double pi = 3.14159271, wheelDiameter = 74, trackWidth = 432 , countsPerRevolution = 1000;
double  Distance = 0, radiansPerCount = 0.00057468, countsPerRotation = 0, Heading = 0, X = 0, Y = 0, tHeading = 0, absHead = 0;
float thetaD = 55;
double distancePerCount = 0.2356;
int ew = 0;
int ab = 0;
int cd = 0;
int ef = 0;
int gh = 0;
int ij = 0;
int z = 0;
int qa = 7;
int wa = 6;
int ea = 9;
int ra = 8;
int i = 0;
int l = 0;
double yy=0;
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
double aa=3.06867362131226E+01;
double bb=4.37753762425296E+01;
double cc=1.68673241220334884E-03;
double dd=2.428965099526473E+00;
Servo steer;
void setup() {
  Serial.begin(115200);
  /* Initialise the sensor */
  if (!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while (1);
  }
  delay(1000);
  /* Display some basic information on this sensor */
  displaySensorDetails();
  /* Optional: Display current status */
  //displaySensorStatus();
  bno.setExtCrystalUse(true);
  pinMode(qa, INPUT_PULLUP);
  pinMode(wa, INPUT_PULLUP);
  pinMode(ea, INPUT_PULLUP);
  pinMode(ra, INPUT_PULLUP);
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
 // while (countL < 1500 && countR < 1500)
  steer.write(83);//calibrating to actual 90
  delay(100);
}
void doEncoder1()
{  if (digitalRead(7))countR++;else countR--;
}
void doEncoder2()
{ if (digitalRead(9))countL--;else  countL++;
}
void steerf(double a)
{ int low=0.97;
  steer.write(a*(1-low)+langle*(low)) ;
}
void loop() {

  Distance = ((countL + countR) / 2) * distancePerCount;
  //countsPerRotation = (trackWidth / wheelDiameter) * countsPerRevolution;
  // radiansPerCount = Pi * (wheelDiameter/trackWidth) / countsPerRevolution ;
  Heading = (countR - countL) * radiansPerCount;
  Y = (Distance * cos(Heading)) / 10;
  X = (Distance * sin(Heading)) / 10;
  tHeading = ((Heading * 180 ) / 3.1415927);
  //  Serial.print(Distance);Serial.print(" ");
   while (lcountl == countL  && lcountr == countR );
  Serial.print(Distance); Serial.print(" ");  Serial.print(tHeading); Serial.print(" ");
  /* Get a new sensor event */
  sensors_event_t event;
  bno.getEvent(&event);

  /* Display the floating point data */
  Serial.print("X: ");
  double angbuff=event.orientation.x;
  if (event.orientation.x>180)
  angbuff=angbuff-360;
  Serial.print(angbuff, 4);
  /* Optional: Display calibration status */
 // displayCalStatus();
  /* Optional: Display sensor status (debug only) */
  //displaySensorStatus();
  /* New line for the next sample */
  lll=pingL();
      rrr=pingL();
      yy=aa+bb*cos(cc*Distance+dd);
//    Serial.print(" ");Serial.print(lll); Serial.print(" ");Serial.print(rrr); Serial.print(" ");
// Serial.print("  "); Serial.print(yy);Serial.println("");
//--------------------------------------------------
c=1;  
  if (lll < 10 && c == 0)             //ping general
    steer.write(85 - 17 );
  else if (c == 0)
    steer.write(85 + 17 );
  if (rrr < 10 && c == 0)
    steer.write(85 + 17 );
  else if (c == 0)
    steer.write(85 - 17 );
if (Distance > 5600 && k == 0)      // 90 degree//6055 -11
  {
    steerf(45);
    delay(10);
    c = 1;
    flag = 1;
  }
  if (tHeading > 100 && flag == 1)      // 90 degree ke baad straight
  {
    steerf(85);
    delay(10);
    c = 0;
    k = 1;
    flag = 0;
    z = 1;
  }
  steerf(88+yy);




























lcountl=countL;
lcountr=countR;
langle=(angle+angbuff)/2;
}





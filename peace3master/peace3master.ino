#include <TimerOne.h>
#define encR_A 20
#define encR_B 21
#define encL_A 23
#define encL_B  22
#include <SD.h>
#include <SPI.h>

// On the Ethernet Shield, CS is pin 4. Note that even if it's not
// used as the CS pin, the hardware CS pin (10 on most Arduino boards,
// 53 on the Mega) must be left as an output or the SD library
// functions will not work.

// change this to match your SD shield or module;
// Arduino Ethernet shield: pin 4
// Adafruit SD shields and modules: pin 10
// Sparkfun SD shield: pin 8
// Teensy audio board: pin 10
// Wiz820+SD board: pin 4
// Teensy 2.0: pin 0
// Teensy++ 2.0: pin 20
int cnt=0;
const int chipSelect = 4;
String s[3];
int count=0;
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
   Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
        // don't do anything more:
    return;
  } 
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt");
  // if the file is available, write to it:
  if (dataFile) {
    while (dataFile.available()) {
      int c=dataFile.read();
      
       if((c!='\n')&&(c!=','))
      {    
        s[count]+=(char)c;
       }
      else{Serial.print(s[count].toFloat());Serial.print(",");count++;if(count==3){Serial.println();count=0;cnt++;}s[count]="";}
      }
    dataFile.close();
  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  } 
  Serial3.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(encR_B, INPUT);
  pinMode(encR_A, INPUT);
  pinMode(encL_B, INPUT);
  pinMode(encL_A, INPUT);
  attachInterrupt(digitalPinToInterrupt(encR_A), encR, RISING);
  attachInterrupt(digitalPinToInterrupt(encL_A), encL, RISING);
  Serial.begin (115200);
  Serial.println(cnt);
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
 a=(2*PI*r*encR_pos)/3261     ;
 b=(2*PI*r*encL_pos)/3275;
} 
void encR()
{
   if (digitalRead(encR_A) == HIGH) {   // found a low-to-high on channel A
    if (digitalRead(encR_B) == LOW) {  // check channel B to see which way
                                             // encoder is turning
      encR_pos--;         // CCW
    } 
    else {
      encR_pos++;         // CW
    }
  }
  else                                        // found a high-to-low on channel A
  { 
    if (digitalRead(encR_B) == LOW) {   // check channel B to see which way
                                              // encoder is turning  
      encR_pos++;          // CW
    } 
    else {
      encR_pos = encR_pos--;          // CCW
    }
}}
void encL()
{
   if (digitalRead(encL_A) == HIGH) {   // found a low-to-high on channel A
    if (digitalRead(encL_B) == LOW) {  // check channel B to see which way
                                             // encoder is turning
      encL_pos --;         // CCW
    } 
    else {
      encL_pos ++;         // CW
    }
  }
  else                                        // found a high-to-low on channel A
  { 
    if (digitalRead(encL_B) == LOW) {   // check channel B to see which way
                                              // encoder is turning  
      encL_pos++;          // CW
    } 
    else {
      encL_pos--;          // CCW
    }
}

}
//void encR()
//{
//  if (digitalRead(encR_B)) encR_pos++;
//  else encR_pos--;
//}
//void encL()
//{
//  if (digitalRead(encL_B)) encL_pos++;
//  else encL_pos--;
//}
void xxyy()
{
  if (a!=b)
  {rr=(a*l)/(b-a);
  tt=(b-a)/l;
  y=(l/2+rr)*sin(tt); 
  x=(l/2+rr)*cos(tt);
  ay=rr*sin(tt);
  ax=rr*cos(tt);
  bx=(rr+l)*cos(tt);
  by=(rr+l)*sin(tt);
  } 
}
 
void loop()
{  unsigned long blinkCopy=0;
rev();
xxyy();
   while(Serial.available())
   {char m=Serial.read();
  if ('m'==m)
  { encL_pos=0;
  encR_pos=0;a=0;b=0;}
   } 
  
   noInterrupts();
   blinkCopy = blinkCount;
  interrupts();
 
   if (!((lastL == encL_pos)&&(lastR ==encR_pos)))
  {
  Serial.print(blinkCopy);Serial.print(" ");Serial.print(encR_pos); Serial.print(" "); Serial.print(encL_pos); Serial.print(" "); Serial.print((b-a)/l); Serial.print(" "); Serial.println((a+b)/2);//Serial.print(" "); Serial.print(x); Serial.print(" "); Serial.print(y);Serial.print(" "); Serial.print(ax); Serial.print(" "); Serial.print(ay);Serial.print(" "); Serial.print(bx); Serial.print(" "); Serial.println(by);
 //Serial.print(blinkCopy);Serial.print(" ");  Serial.print(aa); Serial.print(" "); Serial.print(a);Serial.print(" ");
 }
  bblinkCopy=blinkCopy;
   lastR = encR_pos;
  lastL = encL_pos;
  //Serial.print(digitalRead(encR_A)); delayMicroseconds(10); Serial.println(digitalRead(encR_B)); delayMicroseconds(10);Serial.print('\t');
  //Serial.print(digitalRead(encL_A)); delayMicroseconds(10); Serial.println(digitalRead(encL_B)); delayMicroseconds(10

}





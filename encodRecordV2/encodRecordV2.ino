#include <MsTimer2.h>
#define REAR 0
#define FRONT 2
#define RIGHT 1
#define LEFT 3
int left_A = 12, left_B = 8, left_pwm = 10;
//11 7 9
//12 8 10
int right_A = 11, right_B = 7, right_pwm = 9;



// Switch on LED on and off each half second

#if ARDUINO >= 100
const int led_pin = LED_BUILTIN;  // 1.0 built in LED pin var
#else
const int led_pin = 13;     // default to pin 13
#endif

#define encR_A 1//21
#define encR_B 2//20
#define encL_A 5
#define encL_B  6
int lim = 30;
#include <SD.h>
#include <SPI.h>
volatile  double encR_pos = 0;
volatile  double encL_pos = 0;
int lastR;
int lastL;
const int chipSelect = 4;
const int led = LED_BUILTIN;    // the number of the LED pin
int ledState = LOW;
volatile unsigned long blinkCount = 0;
/// Variables will change :
// ledState used to set the LED
// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated
// constants won't change :
const long interval = 5;           // interval at which to blink (milliseconds)
double l = 41.5;
double r = 3.656;

double tt;
double a = 0;
double la = 0;
double lb = 0;
double b = 0;
double rr;
double x;
double y;
double bx;
double by;
double ax;
double ay;
double bb;
double aa;


unsigned long bblinkCopy = 0;
double time1;
double time2;
double pt1;
double pt2;
double kpa = 1, kpb = 1;
double pida = 0, pidb = 0;
double errora, errorb;
int cpr;
int cpm;
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
//void encR()
//{
//   if (digitalRead(encR_A) == HIGH) {   // found a low-to-high on channel A
//    if (digitalRead(encR_B) == LOW) {  // check channel B to see which way
//                                             // encoder is turning
//      encR_pos--;         // CCW
//    }
//    else {
//      encR_pos++;         // CW
//    }
//  }
//  else                                        // found a high-to-low on channel A
//  {
//    if (digitalRead(encR_B) == LOW) {   // check channel B to see which way
//                                              // encoder is turning
//      encR_pos++;          // CW
//    }
//    else {
//      encR_pos = encR_pos--;          // CCW
//    }
//}}
//void encL()
//{
//   if (digitalRead(encL_A) == HIGH) {   // found a low-to-high on channel A
//    if (digitalRead(encL_B) == LOW) {  // check channel B to see which way
//                                             // encoder is turning
//      encL_pos --;         // CCW
//    }
//    else {
//      encL_pos ++;         // CW
//    }
//  }
//  else                                        // found a high-to-low on channel A
//  {
//    if (digitalRead(encL_B) == LOW) {   // check channel B to see which way
//                                              // encoder is turning
//      encL_pos++;          // CW
//    }
//    else {
//      encL_pos--;          // CCW
//    }
//}
//
//}
void setup() {
  pinMode(led_pin, OUTPUT);

  MsTimer2::set(10, flash); // 500ms period
  MsTimer2::start();

  pinMode(encR_B, INPUT_PULLUP);
  pinMode(encR_A, INPUT_PULLUP);
  pinMode(encL_B, INPUT_PULLUP);
  pinMode(encL_A, INPUT_PULLUP);
   pinMode(left_A, OUTPUT); pinMode(left_B, OUTPUT); pinMode(left_pwm, OUTPUT);
  pinMode(right_A, OUTPUT); pinMode(right_B, OUTPUT); pinMode(right_pwm, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(encR_A), encR, RISING);
  attachInterrupt(digitalPinToInterrupt(encL_A), encL, RISING);
  Serial.begin (9600);
  Serial.println("start");
  delay(10);
  //  Timer1.initialize(1000);
  //  Timer1.attachInterrupt(blinkLED);
  int ledState = LOW;
  volatile unsigned long blinkCount = 0;
  //Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  //  if (!SD.begin(chipSelect)) {
  //    Serial.println("Card failed, or not present");
  //    // don't do anything more:
  //    return;
  //  }
  //  Serial.println("card initialized.");
  //  //  Serial1.write(32);
  //}
}
double rrpm = 0;
double lrpm = 0;

void flash()
{

  rrpm = encR_pos / 5;
  lrpm = encL_pos / 5;
  encR_pos = 0;
  encL_pos = 0;

  static boolean output = HIGH;

  digitalWrite(led_pin, output);
  output = !output;
}
//void blinkLED(void)
//{
//  if (ledState == LOW) {
//    ledState = HIGH;
//    blinkCount = blinkCount + 1;  // increase when LED turns on
//  } else {
//    ledState = LOW;
//  }
//  digitalWrite(led, ledState);
//}
void rev()
{
  a = (2 * PI * r * encR_pos) / 1024;
  b = (2 * PI * r * encL_pos) / 1024;
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
//
void loop()
{ 
  unsigned long blinkCopy = 0;
  rev();
  // xxyy();
  //xxyy();
  while (Serial.available())
  { char m = Serial.read();
    if ('m' == m)
    { encL_pos = 0;
      encR_pos = 0;
    }
  }
  //  blinkLED();
  //   noInterrupts();
  //  blinkCopy = blinkCount;
  /// interrupts();
  //
  // if (!((lastL == encL_pos)&&(lastR ==encR_pos)))
  double r = (a - la); //(blinkCopy-bblinkCopy);
  double g = (b - lb); //(blinkCopy-bblinkCopy);
  //  String dataString =(String)blinkCopy+" "+(String)encR_pos+" "+(String)encL_pos+" "+(String)a+" "+(String)b+" ";//+(String)r+" "+(String)g ;
  ///File dataFile = SD.open("datalog.txt", FILE_WRITE);
  // if the file is available, write to it:
  //  if (dataFile) {
  //    dataFile.println(dataString);
  //    dataFile.close();
  //    // print to the serial port too:
  //    Serial.println(dataString);
  //  }
  //   else {
  //    Serial.println("error opening datalog.txt");
  //  }
  Serial.print(blinkCopy); Serial.print(" "); Serial.print(rrpm); Serial.print(" "); Serial.print(lrpm); Serial.print(" ");  Serial.print(a); Serial.print(" "); Serial.print(b); Serial.print(" "); Serial.print(r); Serial.print(" "); Serial.println(g); //Serial.print(" ");// Serial.print(x); Serial.print(" "); Serial.print(y);Serial.print(" "); Serial.print(ax); Serial.print(" "); Serial.print(ay);Serial.print(" "); Serial.print(bx); Serial.print(" "); Serial.println(by);
  //Serial.print(blinkCopy);Serial.print(" ");  Serial.print(encR_pos); Serial.print(" "); Serial.println(encL_pos);//Serial.print(" ");  //Serial.print(pida); Serial.print(" "); Serial.println(pidb);
  forward();
  bblinkCopy = blinkCopy;
  lastR = encR_pos;
  lastL = encL_pos;
  la = a;
  lb = b;
}
void forward() {
  digitalWrite(left_A, HIGH);
  digitalWrite(left_B, LOW);
  analogWrite(left_pwm, 255);

  digitalWrite(right_A, HIGH);
  digitalWrite(right_B, LOW);
  analogWrite(right_pwm, 255);
}








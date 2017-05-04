#include <MsTimer2.h>

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
volatile  int encR_pos = 0;
volatile  int encL_pos = 0;
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
//const long interval = 100;           // interval at which to blink (milliseconds)
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
double rrpm = 0;
double lrpm = 0;


#include <TimerOne.h>
#include <SD.h>
#include <SPI.h>
const int chipSelect = 4;
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
volatile unsigned long blinkCount = 0;
/// Variables will change :
            // ledState used to set the LED
// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated
// constants won't change :
const long interval = 1000;           // interval at which to blink (milliseconds)
double l=41.5;
double r=3.592662337;
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
void setup()
{
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  Serial.print("Initializing SD card...");
  
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
   //pinMode(led, OUTPUT);
  pinMode(encR_B, INPUT);
  pinMode(encR_A, INPUT);
  pinMode(encL_B, INPUT);
  pinMode(encL_A, INPUT);
  
}

void loop()
{
  // make a string for assembling the data to log:
  String dataString = "";

  // read three sensors and append to the string:
  for (int analogPin = 0; analogPin < 3; analogPin++) {
    int sensor = analogRead(analogPin);
    dataString += String(sensor);
    if (analogPin < 2) {
      dataString += ","; 
    }
  }

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  } 
}










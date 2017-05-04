/*
  SD card file dump
 
 This example shows how to read a file from the SD card using the
 SD library and send it over the serial port.
   
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4
 
 created  22 December 2010
 by Limor Fried
 modified 9 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.
   
 */

#include <SD.h>
#include <SPI.h>
int cnt=0;
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
const int chipSelect = 4;
String s[3];
int count=0;
void setup()
{
 // Open serial communications and wait for port to open:
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
    Serial.println(cnt);
  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  } 
}

void loop()
{
}

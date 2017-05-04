/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 1500;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(5,1500,2800);  // attaches the servo on pin 9 to the servo object 
Serial.begin(9600);
myservo.write(1500);
} 
 
void loop() 
{ 
    if (Serial.available())
    {// in steps of 1 degree 
      pos=Serial.parseInt();
      if(pos>1700)
      pos=1550;
      Serial.println(pos);
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    }
} 


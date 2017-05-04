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
 Servo myservo1;
int pos = 1500;//13 5    // variable to store the servo position 
 int pos1 = 1500;
void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(12);  
// myservo1.attach(5);// attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
    while(Serial.available()){
       pos=Serial.parseInt();   
    // pos1=Serial.parseInt();   

         Serial.println(pos);
   // in steps of 1 degree 
   myservo.write(pos);     
    //  myservo1.write(pos1);  // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
    }
 
} 


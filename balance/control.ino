#include <Servo.h> 
Servo myservo; 
void servosetup() 
{ 
  myservo.attach(9);  
} 
 void servoloop(int y) 
{ 
                                  
    myservo.write(y);              
                    
} 



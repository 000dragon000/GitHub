#include <SPI.h>  
#include <Pixy.h>
#include <Servo.h>
Servo myservo;  
Servo myservo2;  


Pixy pixy;
//void dox(int x)
//{ int val =x;            
//  val = map(val,305,1, 50, 135);    
// myservo.write(val);                 
//Serial.print(val);   Serial.print(" ");   
// }
//void doy(int y)
//{ int val =y ;           
//  val = map(val,170,1,60,135),
//myservo2.write(val);                 
//   Serial.print(val); Serial.println();
//}        
void setup()
{
  Serial.begin(9600);
  myservo.attach(9); 
  myservo2.attach(12);
  pixy.init();
  myservo.write(90);                 
  myservo2.write(90);           
delay(3000)  ;
   
}
void loop()
{ int temp=0;
  uint16_t blocks;
  double err=0;
  blocks = pixy.getBlocks();
  if (blocks)
  {  

   while(pixy.blocks[0].signature!=1)
   {}
   int sum=0;
   int sum2=0;
   int x=0,y=0;
   double ax=0,ay=0;
   for(int i=0,j=0;i<5;i++,j++)
   {x=pixy.blocks[0].x;
    y=pixy.blocks[0].y;
    sum=sum+x;
    sum2=sum2+y;
   } 
   x=sum/5;
   y=sum2/5;
  ax=map(x,300,1,30,150);
//Serial.print(x); Serial.print(" "); Serial.println(ax);
err=ax-temp;
temp=ax;
Serial.println(err);
myservo.write(ax-err*0.9);
delay(500);
  }
 }
 



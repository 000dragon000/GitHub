#include <SPI.h>  
#include <Pixy.h>
#include <Servo.h>
Servo myservo;  
Servo myservo2;  
#define X_CENTER    160L
#define Y_CENTER    100L
#define RCS_MIN_POS     0L
#define RCS_MAX_POS     1000L
#define RCS_CENTER_POS	((RCS_MAX_POS-RCS_MIN_POS)/2)
int count=93;
int count2=90;//a 0-187 //delta shift 7
class ServoLoop
{
public:
  ServoLoop(int32_t pgain, int32_t dgain);

  void update(int32_t error);
   
  int32_t m_pos;
  int32_t m_prevError;
  int32_t m_pgain;
  int32_t m_dgain;
};
ServoLoop panLoop(500, 800);
ServoLoop tiltLoop(700, 900);
ServoLoop::ServoLoop(int32_t pgain, int32_t dgain)
{
  m_pos = RCS_CENTER_POS;
  m_pgain = pgain;
  m_dgain = dgain;
  m_prevError = 0x80000000L;
}
void ServoLoop::update(int32_t error)
{
  long int vel;
  char buf[32];
  if (m_prevError!=0x80000000)
  {	
    vel = (error*m_pgain + (error - m_prevError)*m_dgain)>>10;
    //sprintf(buf, "%ld\n", vel);
    //Serial.print(buf);
    m_pos += vel;
    if (m_pos>RCS_MAX_POS) 
      m_pos = RCS_MAX_POS; 
    else if (m_pos<RCS_MIN_POS) 
      m_pos = RCS_MIN_POS;
    //cprintf("%d %d %d\n", m_axis, m_pos, vel);
  }
  m_prevError = error;
}
Pixy pixy;
int sum=0;
int sum2=0;
void dox(int x)
{int  val =x;            
  val = map(val, 0, 1023, 0, 180);    
  myservo.write(val);                 
  delay(1);     
 }
void doy(int y)
{int  val =y ;           
  val = map(val, 0, 1023, 0, 180);     
  myservo.write(val);                 
  delay(1);    
} 
         

void setup()
{
  Serial.begin(9600);
  Serial.print("Starting...\n");
  myservo.attach(9); 
  myservo2.attach(12);
  pixy.init();
  myservo.write(90);
  myservo2.write(90);
}

void loop()
{ 
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32]; 
  int32_t panError, tiltError;
  
  blocks = pixy.getBlocks();
  
  if (blocks)
  {
    panError = X_CENTER-pixy.blocks[0].x;
    tiltError = pixy.blocks[0].y-Y_CENTER;
    
    panLoop.update(panError);
    tiltLoop.update(tiltError);
    
    pixy.setServos(panLoop.m_pos, tiltLoop.m_pos);
    
    i++;
    
    if (i%50==0)
    {
      sprintf(buf, "Detected %d:\n", blocks);
      Serial.print(buf);
      
      for (j=0; j<blocks; j++)
      {
       sprintf(buf, "  block %d: ", j);
        Serial.print(buf); 
      pixy.blocks[j].print();
      while(pixy.blocks[j].signature==1)
      {
        int y,t=0;
     for(int i=0;i<5;i++)
   { int y=pixy.blocks[0].y;
    int t=pixy.blocks[0].x;
    sum=sum+t;
    sum2=sum2+y;
   } 
   t=sum/5;
   y=sum2/5;
       
         Serial.print(t);Serial.print(" ");Serial.print(y);
            
       while(t>118)
       {
         myservo.write(count);
         count++;
         Serial.print(count);Serial.print(" ");Serial.println(t);
          
      
       }
         while(t<122)
       {
         myservo.write(count);
         count--;
          Serial.print(count);Serial.print(" ");Serial.println(t);
          if(t>=122||count<30)
          break;
          delay(5);
       }
//              while(y<83)
//       {
//         myservo2.write(count2);
//         count2++;
//         Serial.print(count2);Serial.print(" ");
//          delay(50);
//       }
//        while(y<88)
//       {
//         myservo2.write(count2);
//         count2--;
//         Serial.print(count2);Serial.println();
//         delay(50);
//       }
      }               
                
         
      }
    }
  }  
}


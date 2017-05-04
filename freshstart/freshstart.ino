#define trigPin 9
#define echoPin 8
#define ser 10
#include<Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(3, 4, 23, 22, 21,20);
Servo steer;
void setup() {
  Serial.begin (9600);
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ser, OUTPUT);
  steer.attach(10);  
  steer.write(90-40);
  delay(3000);
}
void steerang(int a)
{steer.write(a-40);
}
long dis()
{  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  lcd.setCursor(0, 1);
  if(distance<1000)
 { 
    lcd.clear();
 lcd.print(distance);
 }
   return distance;
   
}
long distance=0;
int k=0,flag=0;int t=89; int count=0;
void loop()
{
  distance=dis();
   if ((25 < distance) && (distance < 29))//hill1
    k = 10  ;
 else if ((45 < distance) && (distance < 47)) //hill2
    k = 10;
  else if ((64 < distance) && (distance < 67) )//slop3 -hille3
  {
    if (count<2)
    {k=-25;count++;
    t=0;
    }
     else
     k = 15;
    }
  else
   { 
     k = 0;
   }
 
  if (flag == 0) {
    if (t == 0)
    { steerang(55 + k);
      t = 324;
      delay(4000);
    }
    else
   { steerang(55 + k);
    delay(10);}
  }
  if (flag == 1) {
    steerang(125 - k);
    delay(10);

  }


  }



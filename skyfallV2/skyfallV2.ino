#include <Servo.h>
double angle = 90;
double y, x;
int z = 0;
int q = 7;
int w = 6;
int e = 9;
int r = 8;
int key = 0;
int lcountl = 0, lcountr = 0;
#define trigPin 4
#define echoPin 3
#define ser 5
int pos = 0;
int flag = 0;
int ls = 60 ;
int rs = 120 ;
int pn = ls;
int t = 123;
int k = 0, count;
volatile int countL = 0;//4100 6000 4000
volatile int countR = 0;
Servo steer;
void setup() {
  pinMode(q, INPUT_PULLUP);
  pinMode(w, INPUT_PULLUP);
  pinMode(e, INPUT_PULLUP);
  pinMode(r, INPUT_PULLUP);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(6), doEncoder1, RISING);
  attachInterrupt(digitalPinToInterrupt(8), doEncoder2, RISING);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ser, OUTPUT);
  steer.attach(5);
  while(countL<3000&&countR<3000)
  steer.write(85);//calibrating to actual 90
    delay(10);
}
void doEncoder1()
{
  if (digitalRead(7))
    countR++;
  else
    countR--;
}

void doEncoder2()
{
  if (digitalRead(9))
    countL--;
  else
    countL++;
}
void loop() {
  // Serial.print(digitalRead(q));
  // Serial.print(digitalRead(w));
  // Serial.print(" ");
  // Serial.print(digitalRead(e));
  // Serial.print(digitalRead(r));
  // Serial.println();
  //if (count<6)
  //{
  ////Serial.print(countL);Serial.print(" ");Serial.println(countR);
  //
  //if (countL>4100&&countR>4100)
  // steer.write(105);
  // delay(10);
  //-------------------------------------------------
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;//loop dis
  while (lcountl - countL == 0 && lcountr - countR == 0);
  Serial.print(countL); Serial.print("  ");  Serial.println(countR);
  x = countR;
  if (distance < 15)
    flag = 1;
  else if (distance < 69)
  { flag = 0;
  }

  if ((25 < distance) && (distance < 29))//hill1
    k = 10;
  else if ((45 < distance) && (distance < 47)) //hill2
    k = 10;
  else if ((69 < distance) && (distance < 74) )//slop3 -hille3
  {
    if (count < 2)
    { k = -15; count++;
      t = 0;
    }
    else
      k = 5;
  }
  else
  {
    k = 0;
  }
  if (countL < -26329 && countR < -26031)
  { steer.write(20);
    delay(1000);
    steer.write(87);
    countL = 0; countR = 0;
    key = 1;
  }
  if (countL < 5075 && countR < -5912 && key == 1)
  { steer.write(30);
    delay(750);
    steer.write(87);
    countL = 0; countR = 0;
    key = 2;
  }
  if (countL < -9306 && countR < -950 && key == 3)
  { steer.write(33);
    delay(750);
    steer.write(150);
    delay(100);
    ;
    countL = 0; countR = 0;
    key = 3;
  }
  //   if (key==3)
  //   flag=~flag;
  if (countL < -1131 && countR < -1307 && key == 2)
  { steer.write(40);
    delay(500);
    steer.write(90);
    countL = 0; countR = 0;
    key = 4;
  }


  if (flag == 0) {
    if (t == 0)
    { steer.write(60 + k); //
      t = 324;
      delay(4000);
    }
    steer.write(70 + k);
    delay(10);
  }
  if (flag == 1) {
    steer.write(120 - k);
    delay(10);
  }




    // delay(1);
    //   }
    lcountl=countL;
      lcountr=countR;
  
}





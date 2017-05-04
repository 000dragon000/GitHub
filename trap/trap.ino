
#define res1 5000
#define res2 5000
#define r 3.55
#define l 43
#define encR_A  20
#define encR_B  23
#define encL_A 21
#define encL_B 22
volatile  int encR_pos = 0, encL_pos = 0;//23 RB  20
volatile int cR = 0, cL = 0;
int lastL, lastR;
void setup() {
  pinMode(encR_B, INPUT);
  pinMode(encR_A, INPUT);
  pinMode(encL_A, INPUT);
  pinMode(encL_B, INPUT);
  attachInterrupt(digitalPinToInterrupt(encR_A), encR, RISING);
  attachInterrupt(digitalPinToInterrupt(encL_A), encL, RISING);
  Serial.begin (9600);
  //  Serial1.begin(9600);
  Serial.println("start");
  delay(10);
  //  Serial1.write(32);
}
double a,b;
void loop() {

   while (lastL == encL_pos && lastR == encR_pos);
//  Serial.print(encL_pos); Serial.print(" "); Serial.print(cL); Serial.print(" "); Serial.print(encR_pos); Serial.print(" "); Serial.println(cR);
  a=encL_pos/(2*PI*r);
  b=encR_pos/(2*PI*r);
  x=(-l/2)*((a+b)/(a-b))*cos((b-a)/l);
  y=(-l/2)*((a+b)/(a-b))*sin((b-a)/l);
  //
  //  lastL = encL_pos;
  //  lastR = encR_pos;
Serial.print(xSerial.print(" ");Serial.println(y);
 // Serial.print(digitalRead(encR_A)); delayMicroseconds(10); Serial.println(digitalRead(encR_B)); delayMicroseconds(10);Serial.print('\t'); 
  //Serial.print(digitalRead(encL_A)); delayMicroseconds(10); Serial.println(digitalRead(encL_B)); delayMicroseconds(10);
}

void encR()
{
  if (digitalRead(encR_B)) encR_pos++;
  else encR_pos--;
}
void encL()
{
  if (digitalRead(encL_B)) encL_pos++;
  else encL_pos--;
}
//void encR()
//{
//  if (!(PINA & B10000000 == B10000000))
//    encR_pos++;
//  else
//    encR_pos--;
//  if(encR_pos >=6000){cR++;encR_pos-=6000;}
//
//}
//
//void encL()
//{
//  if (PINF & B10000000 == B10000000)
//    encL_pos++;
//  else
//    encL_pos--;
//      if(encL_pos >=6000){cL++;encL_pos-=6000;}
//
//  //  Serial.print(digitalRead(encL_A));Serial.print(" ");Serial.println(digitalRead(encL_B));
//
//}

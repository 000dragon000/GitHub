#define MAX_ADDR1 0x70
#define MAX_ADDR 0x4A
#include<Wire.h>
unsigned long int st=micros();
unsigned long int lt=micros();
double x[]={0,0,0,0,0,0,0};
double y[]={0,0,0,0,0,0,0};
double mn[]={0,0,0,0,0,0,0};
double mx[]={0,0,0,0,0,0,0};
void setup() {
  pinMode(22,OUTPUT);
  Serial.begin(9600);
  Wire.begin();
  digitalWrite(22,HIGH);
 
 WriteMAX(B00000001, MAX_ADDR1 );
// WriteMAX(B11111111, 0x02, MAX_ADDR );
delay(10);
 x[0]= g(B00000001);
  x[1]= g(B00000010);
x[2]= g(B00000100);
  x[3]=  g(B00001000);
   x[4]= g(B00010000);
   x[5]= g(B00100000);
   x[6]= g(B01000000);
   for (int i=0;i<7;i++)
{mn[i]=x[i];mx[i]=x[i];}
   delay(1000);
}
void WriteMAX(byte data, int addr )
{
    Wire.beginTransmission(addr);
    Wire.write(data);   
    Wire.endTransmission();
    delay(1);
}double lux;
long double g(byte gg)
{ WriteMAX(gg, MAX_ADDR1 );
byte rHigh=readI2CAddr(0x03);
short rLow=readI2CAddr(0x04);
double expo=8*((rHigh>>7)&(0x01))+4*((rHigh>>6)&0x01)+2*((rHigh>>5)&0x01)+((rHigh>>4)&0x01);
double man=128*((rHigh>>3)&(0x01))+64*((rHigh>>2)&(0x01))+32*((rHigh>>1)&(0x01))+16*((rHigh)&(0x01))+8*((rLow>>3)&(0x01))+4*((rLow>>2)&(0x01))+2*((rLow>>1)&(0x01))+((rLow)&(0x01));
//Serial.print(expo);Serial.print(" ");
//Serial.print(man);Serial.print(" ");
return pow(2,expo)*man*0.045;
  }
  
void loop() {
st=micros();
// WriteMAX(B00000001, MAX_ADDR1 );
//byte rHigh=readI2CAddr(0x03);
//short rLow=readI2CAddr(0x04);
//double expo=8*((rHigh>>7)&(0x01))+4*((rHigh>>6)&0x01)+2*((rHigh>>5)&0x01)+((rHigh>>4)&0x01);
//double man=128*((rHigh>>3)&(0x01))+64*((rHigh>>2)&(0x01))+32*((rHigh>>1)&(0x01))+16*((rHigh)&(0x01))+8*((rLow>>3)&(0x01))+4*((rLow>>2)&(0x01))+2*((rLow>>1)&(0x01))+((rLow)&(0x01));
////Serial.print(expo);Serial.print(" ");
////Serial.print(man);Serial.print(" ");
//double lux=pow(2,expo)*man*0.045;
//
// WriteMAX(B00000010, MAX_ADDR1 );
//byte rrHigh=readI2CAddr(0x03);
//short rrLow=readI2CAddr(0x04);
//double eexpo=8*((rrHigh>>7)&(0x01))+4*((rrHigh>>6)&0x01)+2*((rrHigh>>5)&0x01)+((rrHigh>>4)&0x01);
//double mman=128*((rrHigh>>3)&(0x01))+64*((rrHigh>>2)&(0x01))+32*((rrHigh>>1)&(0x01))+16*((rrHigh)&(0x01))+8*((rrLow>>3)&(0x01))+4*((rrLow>>2)&(0x01))+2*((rrLow>>1)&(0x01))+((rrLow)&(0x01));
////Serial.print(expo);Serial.print(" ");
////Serial.print(man);Serial.print(" ");
//double lux2=pow(2,eexpo)*mman*0.045;
//Serial.print(1000000/(st-lt));Serial.print(" ");Serial.print(lux);Serial.print(" ");Serial.print(lux2);//Serial.print(" ");//red

//  // analogWrite(rgb[4],255);
////Serial.print(rHigh,BIN);Serial.print(" ");
////Serial.print(rLow,BIN);Serial.print(" ");
////double lux=pow(2,expo)*man*0.045*0.001;
//Serial.println(); //red
for (int i=0;i<7;i++)
y[i]=g(1<<(i));
for (int i=0;i<7;i++)
{mn[i]=mn[i]>y[i]?y[i]:mn[i];
mx[i]=mx[i]<y[i]?y[i]:mx[i];
}
//  y[0]= g(B00000001);
//   y[1]= g(B00000010);
//   y[2]= g(B00000100);
//  y[3]= g(B00001000);
//   y[4]= g(B00010000);
//   y[5]= g(B00100000);
//   y[6]= g(B01000000);
   //  while(Serial.available())
 //  {char m=Serial.read();
   //if ('m'==m)
 // { 

Serial.print(1000000/(st-lt));Serial.print(mx[0]);Serial.print(" ");Serial.print(mx[1]);Serial.print(" ");Serial.print(mx[2]);Serial.print(" ");Serial.print(mx[3]);Serial.print(" ");Serial.print(mx[4]);Serial.print(" ");Serial.print(mx[5]);Serial.print(" ");Serial.print(mx[6]);Serial.print(" ----- ");Serial.print(mn[0]);Serial.print(" ");Serial.print(mn[1]);Serial.print(" ");Serial.print(mn[2]);Serial.print(" ");Serial.print(mn[3]);Serial.print(" ");Serial.print(mn[4]);Serial.print(" ");Serial.print(mn[5]);Serial.print(" ");Serial.print(mn[6]);Serial.print("----");Serial.print(y[0]);Serial.print(" ");Serial.print(y[1]);Serial.print(" ");Serial.print(y[2]);Serial.print(" ");Serial.print(y[3]);Serial.print(" ");Serial.print(y[4]);Serial.print(" ");Serial.print(y[5]);Serial.print(" ");Serial.println(y[6]);
lt=micros();
 // }
 // }
  }
 

 int readI2CAddr(int addr)
{ 
Wire.beginTransmission(MAX_ADDR);
Wire.write(addr);
Wire.endTransmission();
Wire.requestFrom(MAX_ADDR,1);
if(Wire.available())
return Wire.read();
}

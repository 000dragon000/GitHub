#include <Wire.h>

const int MAX_addr=0x41;

int k=24;
void setup() {
 // put your setup code here, to run once:
  Wire.begin(); 
  Serial.begin(115200);
}

void loop() 
{


   WriteMAX(0x67,0x02,MAX_addr);// write 0x67 by 0x2 register. 
   k=ReadMAX(MAX_addr, 0x02);
   Serial.println(k);//read 0
 
}

 void WriteMAX(byte data, byte reg, int addr )
{
    Wire.beginTransmission(addr);
    Wire.write(reg);
    Wire.write(data);   
    Wire.endTransmission();
    delay(100);
}

 int ReadMAX(int addr, byte reg)
{
    Wire.beginTransmission(addr);
    Wire.write(reg);  
    Wire.endTransmission();
    delay(100);
    Wire.requestFrom(addr, 1);
    int r=Wire.read();
    return r;
}

#define MAX_ADDR1 0x70
#define MAX_ADDR 0x4A
#include<Wire.h>
unsigned long int st=micros();
unsigned long int lt=micros();
void setup() {
  pinMode(2,OUTPUT);
  Serial.begin(9600);
  Wire.begin();
  digitalWrite(2,HIGH);
 
 WriteMAX(B0010000, MAX_ADDR1 );
 //WriteMAX(B11111111, 0x02, MAX_ADDR );

}
void WriteMAX(byte data, int addr )
{
    Wire.beginTransmission(addr);
    Wire.write(data);   
    Wire.endTransmission();
    delay(1);
}


void loop() {
//st=micros();
byte error, address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for(address = 1; address < 127; address++ ) 
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");

      nDevices++;
    }
    else if (error==4) 
    {
      Serial.print("Unknow error at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");

  delay(500); 
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

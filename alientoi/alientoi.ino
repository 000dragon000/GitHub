#include <SoftwareSerial.h>
char val;
SoftwareSerial BTSerial(10, 11); // RX | TX
String a=":my name is aakanksha,";
void setup()
{
  Serial.begin(9600);
  BTSerial.begin(9600);  // HC-05 default speed in AT command more
}

void loop()
{

  // Keep reading from HC-05 and send to Arduino Serial Monitor
//  if (BTSerial.available())
//   Serial.write(BTSerial.read());
  
//   Keep reading from Arduino Serial Monitor and send to HC-05
//  if (Serial.available())
    if (BTSerial.available())
    {
    val=BTSerial.read();
    Serial.println(val);
    if(val=='a')
    {
    BTSerial.print(a);
    delay(100);
    }
    }   
    val='b';
    
}

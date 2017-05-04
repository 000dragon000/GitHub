void loop()
{ 
// mpu();
 while(Serial2.available()){
  dataa=Serial2.read();
  int index=0;
//  for(int i=0;i<8;i++)
//  {ps2[i]=(data&(i+1))>>i;}
ps2[0]=dataa&0b00000001;
ps2[1]=(dataa&0b00000010)>>1;
ps2[2]=(dataa&0b00000100)>>2;
ps2[3]=(dataa&0b00001000)>>3;
ps2[4]=(dataa&0b00010000)>>4;
ps2[5]=(dataa&0b00100000)>>5;
ps2[6]=(dataa&0b01000000)>>6;
ps2[7]=(dataa&0b10000000)>>7;
     for(int i=0;i<7;i++)
     {Serial.print(ps2[i]);
      }
      Serial.println();
        
bldc_();
spin_bldc_();
feed_() ;
// pressure();
 for(int i=0;i<8;i++)
 pps2[i]=ps2[i];
 }
// bldc_();
// feed_() ;
// pressure();

}
//
//1680 1560
//
//1830 1570


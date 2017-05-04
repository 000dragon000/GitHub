int CSN=53;//PB0
int CLK=21;//PD0
int PROG=28;//PA6
char data[54];
void CLEAR_CSN(){digitalWrite(CSN,LOW); }
void SET_CSN(){digitalWrite(CSN,HIGH);}
void CLEAR_CLK(){digitalWrite(CLK,LOW);}
void SET_CLK(){digitalWrite(CLK ,HIGH);}
void CLEAR_PROG(){digitalWrite(PROG,LOW);}
void SET_PROG(){digitalWrite(PROG,HIGH);}
void PROG_HIGH_IMPED() {} //P0MDOUT   = 0x5F; PROG = 1;} while(0) // Pushpull disabled, Hi-Z }
void PROG_LOW_IMPED() {}
void setup()
{
Serial.begin(9600);
pinMode(CLK, OUTPUT);
pinMode(PROG, INPUT);
pinMode(CSN, OUTPUT);
 unsigned char PPTrimBuffer[7]; 
   pptrimRead(PPTrimBuffer, 54);
   delay(200);
    pptrimWrite(PPTrimBuffer, 54);
    pinMode(PROG, INPUT);
    delay(200);      
     pptrimRead(PPTrimBuffer, 54);
   
   
}
#define PPTRIMDelay 200 
static void pptrimDelay(volatile unsigned int value) 
{ 
 for(value; value>0; value--); 
 { 
   unsigned char foo = 30; 
   while(foo--); 
 } 
}  
void initPPTRIM() 
{ 
   PROG_LOW_IMPED(); 
 CLEAR_PROG(); 
} 
static void clkPulses(unsigned char num) 
{ 
  unsigned char i; 
  for(i = 0; i < num; i++) 
  { 
     SET_CLK();     pptrimDelay(PPTRIMDelay); 
CLEAR_CLK();   pptrimDelay(PPTRIMDelay); 
  } 
}  
static void REclk(unsigned char num) 
{ 
  unsigned char i; 
  for(i = 0; i < num; i++) 
  { CLEAR_CLK();   pptrimDelay(PPTRIMDelay); 
     SET_CLK();     pptrimDelay(PPTRIMDelay); 

  } 
}  
unsigned char reversebits(unsigned char value) // Endian switch 
{ 
 unsigned char i=0, result=0; 
 while (i<8) 
 { 
   result += (value<<i)&0x80; 
  if (i<7) result = result >> 1; 
  i++; 
 }  
 return result; 
}
static void setupCondition()  
{ 
  CLEAR_CSN(); 
  pptrimDelay(PPTRIMDelay); 
  CLEAR_CLK(); 
  pptrimDelay(PPTRIMDelay); 
  SET_PROG(); 
  pptrimDelay(PPTRIMDelay); 
  SET_CSN(); 
  pptrimDelay(PPTRIMDelay);   
  CLEAR_CSN(); 
  pptrimDelay(PPTRIMDelay);   
  SET_CLK(); 
  pptrimDelay(PPTRIMDelay); 
  CLEAR_CLK(); 
  pptrimDelay(PPTRIMDelay); 
}  
static void exitCondition() 
{ 
  PROG_LOW_IMPED(); 
  pptrimDelay(PPTRIMDelay); 
  CLEAR_CSN(); 
  pptrimDelay(PPTRIMDelay); 
  SET_CLK(); 
  pptrimDelay(PPTRIMDelay); 
  CLEAR_CLK(); 
  pptrimDelay(PPTRIMDelay); 
  SET_CLK(); 
  pptrimDelay(PPTRIMDelay); 
  SET_CSN(); 
  pptrimDelay(PPTRIMDelay); 
  CLEAR_PROG(); 
  pptrimDelay(PPTRIMDelay); 
} 
void pptrimLoad(unsigned char num_bits) 
{ 
  setupCondition(); 
  operationModeLoad(); 
  clkPulses(num_bits); 
  exitCondition(); 
}   
void pptrimRead(unsigned char *buffer, unsigned char num_bits) 
{ 
   unsigned char current_byte = 0; 
   unsigned char current_bit = 0; 
  unsigned char temp = 0; 
   pinMode(PROG,INPUT); 
  if(!num_bits) return;  
  current_byte = num_bits >> 3; 
  current_bit = num_bits & ~0x07;  
  setupCondition(); 
  operationModeRead(); 
  clkPulses(1);  
  //PPTRIMDelay=200; 
  for(int i=53;i>=0;i--)
  { data[i]=digitalRead(PROG);
  //pptrimDelay(200); 
  clkPulses(1);
    }
//  data[0]
//   temp = 0;  
//   temp += (digitalRead(PROG)) ? 1 : 0;  
//   for(current_bit = num_bits; current_bit; current_bit--) 
//   { 
//     if(((current_bit - 1) & 0x07) == 0) 
//     { 
//       buffer[current_bit >> 3] = temp;  
//       temp = 0; 
//     } 
//     if (current_bit) 
//  { 
//    temp <<= 1;  
//      SET_CLK(); 
//      pptrimDelay(200); 
//      temp += (digitalRead(PROG)) ? 1 : 0; 
//       CLEAR_CLK(); 
//      pptrimDelay(200); 
//  } 
//   } 
  exitCondition(); 

   for(int i=0;i<54;i++)
  { Serial.print(data[i],BIN);
  //pptrimDelay(200); 
    }
    Serial.println();
    }
 
static void operationModeLoad() 
{ 
  CLEAR_PROG(); 
  pptrimDelay(PPTRIMDelay); 
  SET_CSN(); 
  pptrimDelay(PPTRIMDelay); 
  clkPulses(4); 
}  
static void operationModeRead() 
{
  CLEAR_PROG(); 
  pptrimDelay(PPTRIMDelay); 
  SET_CLK();   
  pptrimDelay(PPTRIMDelay); 
  SET_CSN(); 
  pptrimDelay(PPTRIMDelay); 
  CLEAR_CLK(); 
  pptrimDelay(PPTRIMDelay); 
  clkPulses(1); 
  PROG_HIGH_IMPED(); 
}  
static void operationModeWrite() 
{ pinMode(PROG,OUTPUT);
  
  SET_PROG();
  CLEAR_CLK();
  SET_CSN();
  pptrimDelay(PPTRIMDelay);   
  clkPulses(3);   
}  
static void operationModeProg() 
{ 
  SET_CLK(); 
  pptrimDelay(PPTRIMDelay);   
  SET_CSN(); 
  pptrimDelay(PPTRIMDelay);   
  CLEAR_CLK(); 
  pptrimDelay(PPTRIMDelay);   
  clkPulses(4); 
}
void pptrimWrite(unsigned char *buffer, unsigned char num_bits) 
{ 
//  unsigned char *current_byte; 
// unsigned char current_bit = 0; 
// unsigned char temp = 0;  
// current_byte = buffer + ((num_bits-1)>>3); 
// temp = *current_byte; 
// if(num_bits % 8) 
//  temp <<= 8 - (num_bits % 8);  
//  s e tupCondition(); 
// operationModeWrite();  
// //-- send OTP Data 
// for(current_bit = num_bits; current_bit; current_bit--) 
// { 
//  if(temp & 0x80) 
//   SET_PROG(); 
//  else 
//   CLEAR_PROG();  
//   
//  pptrimDelay(100); 
//  SET_CLK(); 
//  pptrimDelay(300);// delay, tzapp=2us(typ.) 
//  CLEAR_CLK(); 
//  pptrimDelay(PPTRIMDelay);  
//  temp <<= 1; 
//  if(((current_bit-1) & 0x07) == 0) 
//  { 
//   temp = *(--current_byte); 
//  } 
// } 
// SET_PROG(); 
// pptrimDelay(100);  
// clkPulses(1); // data latched  
// // END OTP-Write 
setupCondition(); 
operationModeWrite();
clkPulses(4);
data[49]=1;
for(int i=53;i<=0;i++)
{
  if (data[i]=='1')
  digitalWrite(PROG,HIGH);
  else
 digitalWrite(PROG,LOW);
  //pptrimDelay(200); 
  clkPulses(1);
    }
  SET_PROG(); 
pptrimDelay(100);  
clkPulses(1); // data latched  
// // END OTP-Write
exitCondition(); 

 
}
void loop()
{
   }


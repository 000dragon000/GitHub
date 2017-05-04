#include <avr/io.h>
#include <util/delay.h>


int main(void)//binaryblink
{ int x=0;
  byte count=0;
  DDRA=0xff;
  DDRB=0x00;
 
    while(1)
  {
    PORTA=count<<PA0;
    _delay_ms(100);
    count++;
    if(count==255)
    count=0;
     PORTA&=~count<<PA0;
    _delay_ms(100);

  }
  return(0);
}



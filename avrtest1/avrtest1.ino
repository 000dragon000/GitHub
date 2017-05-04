#include <avr/io.h>
#include <util/delay.h>
int main(void)
{DDRA=0xff;
  while(1)
  {PORTA=0xff;
  _delay_ms(30);
  PORTA=(0X00);
   _delay_ms(30);
  }
  return(0);
}


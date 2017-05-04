#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
void inint0()
{
  PCMSK0|=(1<<PCINT1);
  PCICR=(1<<PCIE0);
  sei();
}

ISR(PCINT0_vect)
{
if(PINB&(1<<PB1))
{PORTD|=(1<<PD1);
}else PORTD&=~((1<<PD1));
}


int main(void)
{
  DDRC=0b00000001;
  DDRD=0b00000011;
 
  inint0();
  while(1)
  {
    PORTC^=(1<<PC0);
    _delay_ms(100);
     }
  return 0;
}

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void initInterrupt0(void) {
EIMSK |= (1 << INT0); /* enable INT0 */
EICRA |= (1 << ISC00); /* trigger when button changes */
sei(); /* set (global) interrupt enable bit */
}
ISR(INT0_vect){ 
if (PIND&(1<<PD0)) {
PORTB |= ( 1 << PB2);
}
else {
PORTB &= ~(1 << PB2);
}}

int main(void)
{ DDRB |=(1<<PB1);
  DDRB |=(1<<PB2);
  initInterrupt0();
  while(1)
  {
    _delay_ms(100);
  PORTB^= (1 << PB1);
  }
  return (0);
}

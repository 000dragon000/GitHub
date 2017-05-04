#include <avr/interrupt.h>
#include <avr/power.h>
#include "C:\Users\DELL3537\Documents\Arduino\libraries\Downloads\Compressed\AVR-Programming-master\AVR-Programming-Library\USART.H"
#define SENSE_TIME   50;
#define THRESHOLD    12000;
int count = 0;
uint16_t high;
uint8_t low;
ISR(TIMER1_OVF_vect)
{
  count++;
}
ISR(TIMER1_CAPT_vect)
{
  high = (((high | ICR4H) << 8) | (ICR4L));
}
int main (void)
{ clock_prescale_set(clock_div_1);                       /* full speed */
  Serial.begin(9600);
  //read ICR
  //indicate ICF
  SREG |= 0b10000000; //global interrput
  TIMSK4 |= 0b00100001;
  TCCR4B |= 0b01000111;
  DDRA=0xff;
  PORTA|=0b00000001;
  //TCCR1B |= (1 << CS11) | (1 << CS10)|(1<<CS12); //prescaler to external clcok
  while (1)
  { Serial.print(count * 256 + TCNT4); Serial.print(" "); Serial.println(high);
  }
  return 0;
}


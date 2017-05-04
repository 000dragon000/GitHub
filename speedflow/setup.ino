void setup(){

  Serial.begin(9600);
  setup_reed();
  setup_flowmeter();
  
}
void setup_reed()
{ 
  reedCounter = maxReedCounter;
  circumference = 2*3.14*radius;
  pinMode(reed, INPUT);
  // TIMER SETUP- the timer interrupt allows precise timed measurements of the reed switch
  //for more info about configuration of arduino timers see http://arduino.cc/playground/Code/Timer1
  cli();//stop interrupts
  //set timer1 interrupt at 1kHz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;
  // set timer count for 1khz increments
  OCR1A = 1999;// = (1/1000) / ((1/(16*10^6))*8) - 1
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS11 bit for 8 prescaler
  TCCR1B |= (1 << CS11);   
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  sei();//allow interrupts
  //END TIMER SETUP
  
  //Serial.begin(9600);
}
void setup_flowmeter()
{
    pinMode(hallsensor, INPUT); //initializes digital pin 2 as an input
 // Serial.begin(9600); //This is the setup function where the serial port is initialised,
  attachInterrupt(digitalPinToInterrupt(hallsensor), rpm, RISING); //and the interrupt is attached
}

  

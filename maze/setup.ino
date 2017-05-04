void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  setup_motors();
  setup_sensors();
}
void setup_motors()
{  
  pinMode(pwmm,OUTPUT);   
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
   pinMode(pwm2,OUTPUT);   
  pinMode(aa,OUTPUT);
  pinMode(bb,OUTPUT);
}
void setup_sensors() {
  for (int i = 0; i < 5; i++)
    pinMode(pins[i], INPUT);
}


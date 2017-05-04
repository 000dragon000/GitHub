const byte ledPin = 13;
const byte interruptPin = 21;
volatile byte state = LOW;
int count=0,lcount=0;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT);
  pinMode(18,OUTPUT);
   digitalWrite(18, LOW);
     pinMode(24,OUTPUT);
   digitalWrite(24, LOW);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, RISING);
Serial.begin(9600);
}

void loop() {

 if(count!=lcount)
 Serial.println(count);
 lcount=count;
 
 }

void blink() {
  // Serial.println(" YFJHV ");
 count++;
}

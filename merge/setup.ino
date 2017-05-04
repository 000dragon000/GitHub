void setup()
{
setup_encoder();
}
void setup_encoder()
{

  pinMode(led, OUTPUT);
  pinMode(encR_B, INPUT_PULLUP);
  pinMode(encR_A, INPUT_PULLUP);
  pinMode(encL_B, INPUT_PULLUP);
  pinMode(encL_A, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encR_A), encR, RISING);
  attachInterrupt(digitalPinToInterrupt(encL_A), encL, RISING);
  Serial.begin (9600);
  Serial.println("start");
  delay(10);
  Timer1.initialize(1000);
  Timer1.attachInterrupt(blinkLED);
  int ledState = LOW;
  volatile unsigned long blinkCount = 0;
}


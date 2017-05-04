void setup()
{
}
void setup_encoder()
{
   pinMode(led_pin, OUTPUT);

  MsTimer2::set(500, flash); // 500ms period
  MsTimer2::start();

  pinMode(encR_B, INPUT_PULLUP);
  pinMode(encR_A, INPUT_PULLUP);
  pinMode(encL_B, INPUT_PULLUP);
  pinMode(encL_A, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encR_A), encR, RISING);
  attachInterrupt(digitalPinToInterrupt(encL_A), encL, RISING);
  Serial.begin (9600);
  Serial.println("start");
  delay(10);
//  Timer1.initialize(1000);
//  Timer1.attachInterrupt(blinkLED);
  int ledState = LOW;
//volatile unsigned long blinkCount = 0;
 //Serial.print("Initializing SD card...");
  
  // see if the card is present and can be initialized:
//  if (!SD.begin(chipSelect)) {
//    Serial.println("Card failed, or not present");
//    // don't do anything more:
//    return;
//  }
//  Serial.println("card initialized.");
//  //  Serial1.write(32);
//}
  }

#define encL_A  21
#define encL_B  20

#define encR_A 22
#define encR_B 23
volatile  int encR_pos = 0, encL_pos = 0;
volatile int cR = 0, cL = 0;
int lastL, lastR;
void setup() {
  pinMode(encR_B, INPUT);
  pinMode(encR_A, INPUT);
  pinMode(encL_A, INPUT);
  pinMode(encL_B, INPUT);
  attachInterrupt(digitalPinToInterrupt(encR_A), encR, RISING);
  attachInterrupt(digitalPinToInterrupt(encL_A), encL, RISING);
  Serial.begin (9600);
  //  Serial1.begin(9600);
  Serial.println("start");
  delay(10);
  //  Serial1.write(32);
}

void loop() {

  while (lastL == encL_pos && lastR == encR_pos);
  Serial.print(encL_pos); Serial.print(" "); Serial.println(encR_pos);
//  delayMicroseconds(10);
  lastL = encL_pos;
  lastR = encR_pos;
}
void encR()
{
  if (digitalRead(encR_B)) encR_pos++;
  else encR_pos--;
}
void encL()
{
  if (digitalRead(encL_B)) encL_pos++;
  else encL_pos--;
}


#define REAR 0
#define FRONT 2
#define RIGHT 1
#define LEFT 3

int sharp_IR[] = {17, 16, 15, 14};
int sharp_IR_size = sizeof(sharp_IR) / 2;

int line_sensor[] = {22, 21, 20, 19, 18};
int line_sensor_size = sizeof(line_sensor) / 2;

int left_A = 12, left_B = 8, left_pwm = 10;
//11 7 9
//12 8 10
int right_A = 11, right_B = 7, right_pwm = 9;

const int ledPin =  13;
// Variables will change:
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated
long interval = 1000;

void setup() {
  sharp_IR_size /= 2;
  line_sensor_size /= 2;

  pinMode(left_A, OUTPUT); pinMode(left_B, OUTPUT); pinMode(left_pwm, OUTPUT);
  pinMode(right_A, OUTPUT); pinMode(right_B, OUTPUT); pinMode(right_pwm, OUTPUT);

  for (int i = 0; i < sharp_IR_size; i++)
    pinMode(sharp_IR[i], INPUT);

  for (int i = 0; i < line_sensor_size; i++)
    pinMode(line_sensor[i], INPUT);

  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);

  //  Serial.print(sharp_IR_size);Serial.print(line_sensor_size);
}

void loop() {
  blink_w_o_delay();

  //  digitalWrite(left_A, HIGH);
  //  digitalWrite(left_B, LOW);
  //  analogWrite(left_pwm, 255);

  //  digitalWrite(right_A, HIGH);
  //  digitalWrite(right_B, LOW);
  //  analogWrite(right_pwm, 255);

//    while (Serial.available()) {
//      int x = Serial.parseInt();
//  
//      digitalWrite(left_A, HIGH);
//      digitalWrite(left_B, LOW);
//      analogWrite(left_pwm, 100);
//  
//      digitalWrite(right_A, LOW);
//      digitalWrite(right_B, HIGH);
//      analogWrite(right_pwm, 100);
//  
//      delay(x);
//  
//      analogWrite(left_pwm, LOW);
//      analogWrite(right_pwm, LOW);
//    }

//  Serial.println(analogRead(sharp_IR[FRONT]));

    if (analogRead(sharp_IR[FRONT]) > 600)
      turn_left();
    else
      forward();

  //  for(int i=0;i<sharp_IR_size;i++){
  //    Serial.print(analogRead(sharp_IR[i]));Serial.print('\t');}
  //
  //  Serial.println();

//  digitalWrite(left_A, LOW);
//  digitalWrite(left_B, HIGH);
//  analogWrite(left_pwm, 100);
//
//  digitalWrite(right_A, HIGH);
//  digitalWrite(right_B, LOW);
//  analogWrite(right_pwm, 100);
//
//  delay(138);
//
//  analogWrite(left_pwm, LOW);
//  analogWrite(right_pwm, LOW);
}

void blink_w_o_delay()
{ unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}

void turn_left() {
  digitalWrite(left_A, LOW);
  digitalWrite(left_B, HIGH);
  analogWrite(left_pwm, 100);

  digitalWrite(right_A, HIGH);
  digitalWrite(right_B, LOW);
  analogWrite(right_pwm, 100);

  delay(138);

  analogWrite(left_pwm, LOW);
  analogWrite(right_pwm, LOW);
}

void turn_right() {
  digitalWrite(left_A, HIGH);
  digitalWrite(left_B, LOW);
  analogWrite(left_pwm, 100);

  digitalWrite(right_A, LOW);
  digitalWrite(right_B, HIGH);
  analogWrite(right_pwm, 100);

  delay(113);

  analogWrite(left_pwm, LOW);
  analogWrite(right_pwm, LOW);
}

void forward() {
  digitalWrite(left_A, HIGH);
  digitalWrite(left_B, LOW);
  analogWrite(left_pwm, 255);

  digitalWrite(right_A, HIGH);
  digitalWrite(right_B, LOW);
  analogWrite(right_pwm, 255);
}


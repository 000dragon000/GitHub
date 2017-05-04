void back()
{
digitalWrite(bb,HIGH); 
digitalWrite(aa,LOW);
analogWrite(pwm2,255);
digitalWrite(b,HIGH); 
digitalWrite(a,LOW);
analogWrite(pwmm,255);
}
void front()
{
digitalWrite(bb,LOW); 
digitalWrite(aa,HIGH);
analogWrite(pwm2,255);
digitalWrite(b,LOW); 
digitalWrite(a,HIGH);
analogWrite(pwmm,255);
}
//void rear(){
//   digitalWrite(mot[2], HIGH);
//  digitalWrite(mot[1], LOW);
//  analogWrite(mot[0], spd);
//  digitalWrite(mot2[2], HIGH);
//  digitalWrite(mot2[1], LOW);
//  analogWrite(mot2[0], spd);
//}
//void left()
//{ digitalWrite(mot[2], HIGH);
//  digitalWrite(mot[1], LOW);
//  analogWrite(mot[0], spd);
//  digitalWrite(mot2[2], HIGH);
//  digitalWrite(mot2[1], LOW);
//  analogWrite(mot2[0], 0);
//}
//void right()
//{
//   digitalWrite(mot[2], HIGH);
//  digitalWrite(mot[1], LOW);
//  analogWrite(mot[0], 0);
//  digitalWrite(mot2[2], HIGH);
//  digitalWrite(mot2[1], LOW);
//  analogWrite(mot2[0], spd);
//}
//void brake()
//{
//   digitalWrite(mot[2], HIGH);
//  digitalWrite(mot[1], HIGH);
//  analogWrite(mot[0], 0);
//  digitalWrite(mot2[2], HIGH);
//  digitalWrite(mot2[1], HIGH);
//  analogWrite(mot2[0], 0);
//}
//void stops()
//{ digitalWrite(mot[2], LOW);
//  digitalWrite(mot[1],LOW);
//  analogWrite(mot[0], 0);
//  digitalWrite(mot2[2], LOW);
//  digitalWrite(mot2[1], LOW);
//  analogWrite(mot2[0], 0);
//  }
void blinkwd()
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

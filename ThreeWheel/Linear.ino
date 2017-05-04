void linear_actuator_on1()
{
  if (cl1 % 2 != 0)
  {
    digitalWrite(la1, HIGH);
    digitalWrite(la2, LOW);
    analogWrite(pwm_la, 150);
  }
  else
  {
    linear_actuator_off();
  }
}

void linear_actuator_on2()
{
  if (cl2 % 2 != 0)
  {
    digitalWrite(la1, LOW);
    digitalWrite(la2, HIGH);
    analogWrite(pwm_la, 150);
  }
  else
  {
    linear_actuator_off();
  }
}

void linear_actuator_off()
{
  digitalWrite(la1, LOW);
  digitalWrite(la2, LOW);
  analogWrite(pwm_la, 0);
}

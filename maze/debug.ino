void debug_sensor(){
  for(int i=0;i<9;i++)
{ Serial.print(analogRead(pins[i]));Serial.print(" ");
  }
  Serial.println();
}


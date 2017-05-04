void loop() {
  // put your main code here, to run repeatedly:
  if (SERIAL_DEBUG)
  {
    debug_sensor();
  }
  blinkwd();
  //back();
  front();

}

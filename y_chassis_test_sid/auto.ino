void auto_detect(int* pins) {
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (i == j) continue;
      for (int k = 0; k < 4; k++)
      {
        if (i == k || j == k) continue;
        for (int l = 0; l < 4; l++)
        {
          if (i == l || j == l || k == l) continue;

          CLOCK = pins[i];
          COMMAND = pins[j];
          ATTENTION = pins[k];
          DATA = pins[l];

          int error = ps2x.config_gamepad(CLOCK, COMMAND, ATTENTION, DATA, false, false);
          delay(10);
          //          if(error){
          Serial.print(i); Serial.print(j); Serial.print(k); Serial.print(l); Serial.print('\t'); Serial.println(error);
          //          return;
          //          }
        }
      }
    }
  }
}

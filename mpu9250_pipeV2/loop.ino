void loop()
{

dist=analogRead(A5);

debug_pot();
dist=((ldist+dist)/2)*(1)+(ldist)*0.0;
//mov_bot(640,740);
 mpu_data();

  // Serial.print("Yaw, Pitch, Roll: ");
  //  Serial.print(yaw,0);
  //  Serial.print("\t");
  //  Serial.print(pitch,0);
  //  Serial.print("\t");
  //  Serial.print(roll, 0);
  //  Serial.print("\t");
  //640 min    ront decress 
  //740 max     back increase
 // if ((abs(lmx - mx) > 300 || abs(lmy - my) > 300 || abs(lmz - mz) > 300)&&(magnitude(mx, my, mz)>17000))
  {

    Serial.print(mx, 0);
    Serial.print("\t");
    Serial.print(my, 0);
    Serial.print("\t ");
    Serial.print(mz, 0);
    Serial.print("\t ");
    Serial.print(magnitude(mx, my, mz), 0);
    Serial.print("\t ");   
    Serial.print(roll, 0);
    Serial.print("\t");
   // Serial.print(magnitude(vx, vy, vz) / deltat, 0);
  // Serial.print("\t");
    Serial.println((dist-459));
    brake();
  }
  count = millis();
  sumCount = 0;
  sum = 0;
  lmx = mx;
  lmy = my;
  lmz = mz;
  lspd = spd;
  lspd1 = spd1;
  ldist=dist;
}

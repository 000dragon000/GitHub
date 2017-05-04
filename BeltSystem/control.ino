void control()
{
  readButtons();
  if (cross)
  {
    spd1 = 1500;
    spd2 = 1500;
    s1.writeMicroseconds(spd1);
    s2.writeMicroseconds(spd2);
    flag1 = 0;
    flag2 = 0;
    f2 = 0;
    f1 = 0;
    fl1 = 0;
    fl2 = 0;Serial.print(" ");
    Serial.print("cross");
  }
  if (flag1 > 0 && l1 == 1)
  {
    incj();
    f1 = 1;
    s1.writeMicroseconds(spd1);
    Serial.print(spd1); Serial.print(" ");
    Serial.println("flag1 & l1");
  }
  if (flag2 > 0 && r1 == 1)
  {
    inci();
    f2 = 1;
    s2.writeMicroseconds(spd2);
    Serial.print(spd2); Serial.print(" ");
    Serial.println("flag2 & r1");
  }
  if (flag1 > 0 && l2 == 1)
  {
    decj();
    fl1 = 1;
    s1.writeMicroseconds(spd1);
    Serial.print(spd1); Serial.print(" ");
    Serial.println("flag1 & l2");
  }
  if (flag2 > 0 && r2 == 1)
  {
    deci();
    fl2 = 1;
    s2.writeMicroseconds(spd2);
    Serial.print(spd2); Serial.print(" ");
    Serial.println("flag2 & r2");
  }
  if (l1 && f1 == 0)                                        //Left BLDC
  {
    incL();
    s1.writeMicroseconds(spd1);
    Serial.print(spd1); Serial.print(" ");
    Serial.println("l1");
  }
  if (l2 && fl1 == 0)
  {
    decL();
    s1.writeMicroseconds(spd1);
    Serial.print(spd1); Serial.print(" ");
    Serial.println("l2");
  }
  if (sqr)
  {
    flag1++;
    spd1 = 1500;
    delay(20);
    s1.writeMicroseconds(spd1);
    delay(10);
    s1.writeMicroseconds(1340);
    delay(10);
    s1.writeMicroseconds(spd1);
    delay(10);
    s1.writeMicroseconds(1340);
    spd1 = 1340; Serial.print(" ");
    Serial.println("sqr");
  }
  if (r1 && f2 == 0)                                          //Right BLDC
  {
    incR();
    s2.writeMicroseconds(spd2);
    Serial.print(spd2); Serial.print(" ");
    Serial.println("r1");
  }
  if (r2 && fl2 == 0)
  {
    decR();
    s2.writeMicroseconds(spd2);
    Serial.print(spd2); Serial.print(" ");
    Serial.println("r2");
  }
  if (circle)
  {
    flag2++;
    spd2 = 1500;
    delay(20);
    s2.writeMicroseconds(spd2);
    delay(10);
    s2.writeMicroseconds(1340);
    delay(10);
    s2.writeMicroseconds(spd2);
    delay(10);
    s2.writeMicroseconds(1340);
    spd2 = 1340;
    Serial.print(flag2); Serial.print(" ");
    Serial.println("circle");
  }
}


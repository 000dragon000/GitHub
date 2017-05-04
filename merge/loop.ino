void loop()
{  unsigned long blinkCopy=0; 
   rev();
   while(Serial.available())
   {char m=Serial.read();
   if ('m'==m)
  { encL_pos=0;
   encR_pos=0;}
   }
   blinkLED();
   noInterrupts();
   blinkCopy = blinkCount;
   interrupts();
   Serial.print(blinkCopy); Serial.print(" ");Serial.print(encR_pos); Serial.print(" "); Serial.print(encL_pos); Serial.print(" ");  Serial.print(a); Serial.print(" "); Serial.print(b);Serial.print(" ");Serial.print(r);Serial.print(" ");Serial.println(g);//Serial.print(" ");// Serial.print(x); Serial.print(" "); Serial.print(y);Serial.print(" "); Serial.print(ax); Serial.print(" "); Serial.print(ay);Serial.print(" "); Serial.print(bx); Serial.print(" "); Serial.println(by);
 //Serial.print(blinkCopy);Serial.print(" ");  Serial.print(encR_pos); Serial.print(" "); Serial.println(encL_pos);//Serial.print(" ");  //Serial.print(pida); Serial.print(" "); Serial.println(pidb);
  }
  bblinkCopy=blinkCopy;
  lastR = encR_pos;
  lastL = encL_pos;
  la=a;
  lb=b;
 }

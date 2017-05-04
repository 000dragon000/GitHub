void debug_pot()
{
   if (Serial.available()){
   c = Serial.read();}
   
    if (c == '1') {
      spd++;
    }
    if (c == '2') {
      spd--;
    }
    if (c == '3') {
      spd1++;
    }
    if (c == '4') {
      spd1--;
    }
    spd = constrain(spd, 0, 255);
    spd1 = constrain(spd, 0, 255);
    spd = (1 - alpha) * spd + alpha * lspd;
    spd1 = (1 - alpha) * spd1 + alpha * lspd1;
unsigned long currentMillis = millis();
if(c=='w'){
    // save the last time you blinked the LED 
    front(spd,spd1);
    delay(10);
    brake();
    c='l';
}
if(c=='s'){
 
    // save the last time you blinked the LED 
    back(spd,spd1);
    delay(10);
    brake();
        c='l';
    }
if(c=="z")
{
  brake();
}
;
//if(analogRead(pot)>690&&analogRead(pot)<710)
//flag=1;
//if(analogRead(pot)<620&&analogRead(pot)>610)
//flag=0;
//Serial.print(analogRead(pot));Serial.print(" lag ");Serial.println(flag);
//if(c=='z'&&flag!=lflag&&c!='w'&&c!='s')
//{brake();Serial.print("brake    ");Serial.print(c);Serial.print("flag    ");Serial.println(flag);}
//lflag=flag;

}



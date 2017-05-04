 void sdcard(){
  File dataFile = SD.open("datalog.txt");
  // if the file is available, write to it:
  if (dataFile) {
    while (dataFile.available()) {
      int c=dataFile.read();
      
       if((c!='\n')&&(c!=','))
      {    
        s[count]+=(char)c;
       }
      else{Serial.print(s[count].toFloat());Serial.print(",");count++;if(count==3){Serial.println();count=0;}s[count]="";}
      }
    dataFile.close();
  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  } 
}

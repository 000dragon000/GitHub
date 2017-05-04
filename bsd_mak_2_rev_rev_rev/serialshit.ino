void ps2_transferData() {
 if(buff[1]!=buff[0]){
 Serial1.write(buff[1]);
 buff[0]=buff[1];
}
}


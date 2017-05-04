int motorA[]={48,A9,A15,41};
int motorB[]={A8,A14,40,47};
int pwm[]={44,11,46,45};
int pwmd[]={20,20,20,20};
int pp=20;
void setup() {
Serial.begin(9600);
for (int i=0;i<4;i++){
pinMode(motorA[i],OUTPUT);
pinMode(motorB[i],OUTPUT);
pinMode(pwm[i],OUTPUT);
}}
void stops()
{for (int i=0;i<4;i++)
{
  digitalWrite(motorA[i], LOW);
  digitalWrite(motorB[i], LOW);
  analogWrite(pwm[i],0);
}
}

void motorBK(int a ,int b)
{ digitalWrite(a, HIGH);
  digitalWrite(b, LOW);

}
void motorF(int a ,int b)
{ digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
}

void loop(){

while(Serial.available())
{
char h=Serial.read();
if (h=='q')
stops();
if (h=='a')
{pwmd[0]+=1;pwmd[3]+=1;}
if (h=='z')
{pwmd[0]-=1;pwmd[3]-=1;}

if (h=='d')
{pwmd[1]+=1;pwmd[2]+=1;
}
if (h=='c')
{pwmd[1]-=1;pwmd[2]-=1;}

for (int i=0;i<4;i++)
{
 if (pwmd[i]>10)
 pwmd[i]=255      ;
 if (pwmd[i]<0)
 pwmd[i]=0;
}
if (h=='w')
{for (int i=0;i<4;i++)
{
  motorF(motorA[i],motorB[i]);
  analogWrite(pwm[i], pwmd[i]);

}}
if (h=='s')
{for (int i=0;i<4;i++)
{
  motorBK(motorA[i],motorB[i]);
  analogWrite(pwm[i], pwmd[i]);
}
}
Serial.print(h);Serial.print(" ");Serial.print(pwmd[0]);Serial.print(" ");Serial.print(pwmd[1]);Serial.print(" ");Serial.print(pwmd[2]);Serial.print(" ");Serial.println(pwmd[3]);

}
}



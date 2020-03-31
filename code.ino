

#include<VarSpeedServo.h>
VarSpeedServo s1;
int light=3;
int relay=2;
int cm,cm1;
int trigpin=A3;
int echopin=A4;
int trigpin1=A1;
int echopin1=A2;
int duration,duration1;

void setup()
{
  Serial.begin(9600);
  pinMode(light,OUTPUT);
  
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
pinMode(relay,OUTPUT);
pinMode(trigpin1,OUTPUT);
  pinMode(echopin1,INPUT);
s1.attach(6);


}

void loop()
{
  
digitalWrite(trigpin1,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin1,LOW);
  delayMicroseconds(2);

  duration1=pulseIn(echopin1,HIGH);
  cm1=(duration1/29/2);
  delay(100);
  Serial.println(cm1);
 if(cm1<6)
 {
  sweep();
  delay(100);
  
  digitalWrite(light,HIGH);
  delay(20000);
  digitalWrite(light,LOW);
 }



  
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);

  duration=pulseIn(echopin,HIGH);
  cm=(duration/29/2);
  delay(100);
  Serial.println(cm);

  
 if(cm<10)
 {
  digitalWrite(relay,HIGH);
  delay(10000);
 }
 else if(cm>10) 
 {
  digitalWrite(relay,LOW);
 }
}

void sweep()
{

for(int angle = 90 ; angle<=180 ; angle++)
{
  s1.write(angle,180);
 delay(10); 
}
  for(int angle = 180 ; angle>=90 ; angle--)
{
  s1.write(angle,180);
  delay(10);
}

}

#include<Stepper.h>
int out1=8;
int out2=9;
int enA=11;
int enB=10;
int dirA=12;
int dirB=13;
const int spr=20;
Stepper myStepper(spr,dirA,dirB);
void setup()
{
  myStepper.setSpeed(60);
  pinMode (enA,OUTPUT);
  digitalWrite(enA,HIGH);
  pinMode (enB,OUTPUT);
  digitalWrite(enB,HIGH);
}
void loop()
{
  myStepper.step(spr*5);
delay(100000);
 myStepper.step(-spr*5);
delay(100000); 
}


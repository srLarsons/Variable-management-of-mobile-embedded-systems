#include <TimerOne.h>
unsigned int counter=0;
unsigned int counter1=0;
 
 volatile int b1a =3 ;  // L9110 B-1A 
volatile int b1b = 12;  // L9110 B-1B
volatile int b1c =11 ;  // L9110 B-1A 
volatile int b1d = 13;

 
/*void docount()  // counts from the speed sensor
{
  counter++;  // increase +1 the counter value
  Serial.print("count=");
    Serial.println(counter);
   int rotation = (counter / 120);
  Serial.println(rotation);
} */
 void docount1()  // counts from the speed sensor
{
  counter1++;  // increase +1 the counter value
  Serial.print("count=");
    Serial.println(counter1);
   int rotation1 = (counter1 / 120);
  Serial.println(rotation1);
} 
 
/*void timerIsr()
{
  Timer1.detachInterrupt();  //stop the timer
  Serial.print("Motor Speed: "); 
  int rotation = (counter / 20);  // divide by number of holes in Disc
  Serial.print(rotation,DEC);  
  Serial.println(" Rotation per seconds"); 
  counter=0;  //  reset counter to zero
  Timer1.attachInterrupt( timerIsr );  //enable the timer
}
 */
void setup() 
{
  Serial.begin(9600);
  
 pinMode(b1a, OUTPUT); 
 pinMode(b1b, OUTPUT); 
  
  Timer1.initialize(1000000); // set timer for 1sec
  //attachInterrupt(0, docount, RISING);
  attachInterrupt(digitalPinToInterrupt(10), docount1, CHANGE);
 
  // increase counter when speed sensor pin goes High
 // Timer1.attachInterrupt( timerIsr ); // enable the timer
} 
 
void loop()
{
  int potvalue = analogRead(5);  // Potentiometer connected to Pin A1
  int motorspeed = map(potvalue, 0, 680, 255, 0);
  analogWrite(b1a, motorspeed);  // set speed of motor (0-255)
  digitalWrite(b1b, 0);  // set rotation of motor to Clockwise
    int potvalue1 = analogRead(4);  // Potentiometer connected to Pin A1
  int motorspeed1 = map(potvalue1, 0, 680, 255, 0);
  analogWrite(b1c, motorspeed1);  // set speed of motor (0-255)
  digitalWrite(b1d, 0);  // set rotation of motor to Clockwise
}

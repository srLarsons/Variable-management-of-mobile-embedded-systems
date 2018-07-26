#include <TimerOne.h>
unsigned int counter=0;
 
int b1a = 3;  // L9110 B-1A 
int b1b = 12;  // L9110 B-1B
 
void docount()  // counts from the speed sensor
{
   Serial.begin(9600);
   
  counter++;  // increase +1 the counter value
  Serial.print("count=");
    Serial.println(counter);
   int rotation = (counter / 120);
  Serial.println("rotation");
  Serial.println(rotation);
  
   float distance = rotation*4.5*(22/7);
   Serial.println("distance");
  Serial.print(distance);
  Serial.println("");
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
 
  
 pinMode(b1a, OUTPUT); 
 pinMode(b1b, OUTPUT); 
  
  Timer1.initialize(1000000); // set timer for 1sec
  attachInterrupt(0, docount, RISING);
  

  // increase counter when speed sensor pin goes High
 // Timer1.attachInterrupt( timerIsr ); // enable the timer
} 
 
void loop()
{
  int potvalue = analogRead(5);  // Potentiometer connected to Pin A1
  int motorspeed = map(potvalue, 0, 680, 255, 0);
  analogWrite(b1a, motorspeed);  // set speed of motor (0-255)
  digitalWrite(b1b, 1);  // set rotation of motor to Clockwise
 
}

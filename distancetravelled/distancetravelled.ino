#include <TimerOne.h>
#include <SharpIR.h>
unsigned int counter=0;
 
int b1a = 11;  // L9110 B-1A
int b1b = 13;  // L9110 B-1B
 
/*void docount()  // counts from the speed sensor
{
  counter++;  // increase +1 the counter value
  Serial.print("count=");
    Serial.println(counter);
   double rotation = (counter / 120.0);
     Serial.println("rotation=");
  Serial.println(rotation);
  double dist_travel= rotation*4.5*22/7;
    Serial.println("distance traveled=");
    Serial.println(dist_travel);
    double rpm=rotation/60;
    Serial.println("rpm=");
    Serial.println(rpm);
    Serial.println("/n");
     
}*/
 
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
 pinMode(13, OUTPUT);
 pinMode(9, OUTPUT);
  pinMode(12, OUTPUT);
 pinMode(8, OUTPUT);
  
 
 // Timer1.initialize(1000000); // set timer for 1sec
//  attachInterrupt(0, docount, RISING);
  // increase counter when speed sensor pin goes High
 // Timer1.attachInterrupt( timerIsr ); // enable the timer
}
 
void loop()
{
    counter++;  // increase +1 the counter value
  Serial.print("count=");
    Serial.println(counter);
   double rotation = (counter / 120.0);
     Serial.println("rotation=");
  Serial.println(rotation);
  double dist_travel= rotation*4.5*22/7;
    Serial.println("distance traveled=");
    Serial.println(dist_travel);
    double rpm=rotation*60;
    Serial.println("rpm=");
    Serial.println(rpm);
    Serial.println("/n");
    int x= analogRead(A2);
    float vol1= x * (5.0/1023);
    int y= analogRead(A3);
    float vol2= y * (5.0/1023);
    Serial.println("vol1=");
    Serial.println(vol1);
    Serial.println("/n");
    Serial.println("vol2=");
    Serial.println(vol2);
    Serial.println("/n");
 if (vol1> 2)
 double rpm= 5;

}

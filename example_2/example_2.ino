#define trigPin 13

#define echoPin 12

#define led 11

#define led2 10

#include <Servo.h>

int pos = 0; // variable to store the servo position

int defPOS = 0;

Servo myservo;

void setup() {

Serial.begin (9600);

pinMode(trigPin, OUTPUT);

pinMode(echoPin, INPUT);

pinMode(led, OUTPUT);

pinMode(led2, OUTPUT);

myservo.attach(9);

myservo.write(0);

}

void loop() {

long duration, distance;

digitalWrite(trigPin, LOW); // Added this line

delayMicroseconds(2); // Added this line

digitalWrite(trigPin, HIGH);

// delayMicroseconds(1000); - Removed this line

delayMicroseconds(10); // Added this line

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = (duration/2) / 29.1;

//0 Left

//1 Center

//2 Right

int buttonState1 = digitalRead(led); //red

int buttonState2 = digitalRead(led2); //green

if( (buttonState1 == 0 && buttonState2 == 1) && (defPOS != 1))

{

delay(2000);

if(defPOS == 2)

{

for(pos = 0; pos <= 90; pos += 1) // goes from 0 degrees to 180 degrees

{ // in steps of 1 degree

myservo.write(pos); // tell servo to go to position in variable 'pos'

delay(2); // waits 15ms for the servo to reach the position

}

}

else if(defPOS == 0)

{

for(pos = 0; pos <= 90; pos += 1) // goes from 0 degrees to 180 degrees

{ // in steps of 1 degree

myservo.write(pos); // tell servo to go to position in variable 'pos'

delay(2); // waits 15ms for the servo to reach the position

}

}

defPOS = 1;

}

if (distance < 30) { // This is where the LED On/Off happens

digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off

digitalWrite(led2,LOW);

if(defPOS == 0)

{

for(pos = 90; pos>=0; pos-=1) // goes from 180 degrees to 0 degrees

{

myservo.write(pos); // tell servo to go to position in variable 'pos'

delay(2); // waits 15ms for the servo to reach the position

}

defPOS = 2;

}

else if(defPOS == 2)

{

for(pos = 0; pos <= 90; pos += 1) // goes from 0 degrees to 180 degrees

{ // in steps of 1 degree

myservo.write(pos); // tell servo to go to position in variable 'pos'

delay(2); // waits 15ms for the servo to reach the position

}

defPOS = 1;

}

else if(defPOS == 1)

{

for(pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees

{ // in steps of 1 degree

myservo.write(pos); // tell servo to go to position in variable 'pos'

delay(2); // waits 15ms for the servo to reach the position

}

defPOS = 0;

}

//myservo.write(180);

// delay(1000);

//myservo.write(0);

}

else {

digitalWrite(led,LOW);

digitalWrite(led2,HIGH);

}

if (distance >= 400 || distance <= 0){

Serial.println("Out of range");

}

else {

Serial.print(distance);

Serial.println(" cm");

}

delay(500);

}



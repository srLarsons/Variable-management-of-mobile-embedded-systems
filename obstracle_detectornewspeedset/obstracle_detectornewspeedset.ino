
/*************************************************************
Motor Shield 2-Channel DC Motor Demo
by Randy Sarafan

For more information see:
http://www.instructables.com/id/Arduino-Motor-Shield-Tutorial/

*************************************************************/

void setup() {
  
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel A pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel A pin
  
}

void loop(){
int sensValue1=analogRead(A2);
 int sensValue2=analogRead(A3);
 float voltage1 = sensValue1 * (5.0 / 1023.0);
 float voltage2 = sensValue2 * (5.0 / 1023.0);

 Serial.print(voltage1);
 Serial.print(voltage2);
   //display the results
  delay(10); //wait for the string to be sent
  if(voltage1<1 && voltage2<1) 
  {
  //Motor  forward @ full speed
  digitalWrite(12, LOW); //Establishes farward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 75);   //Spins the motor on Channel A at full speed

  //Motor B FARWARD @ half speed
  digitalWrite(13, LOW);  //Establishes farward direction of Channel B
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, 255);    //Spins the motor on Channel B at half speed
  }
  else if(voltage1>1 && voltage2>1)
  {
    // LEFT MOTOR MOVES BACK
   digitalWrite(12, HIGH); //Establishes backward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 75);   //Spins the motor on Channel A at full speed

  //Motor B backwarD
  digitalWrite(13, HIGH);  //Establishes backward direction of Channel B
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, 255);  
  }
  else if(voltage1<1 && voltage2>1) //left sensor got obstracle
  {
   
   digitalWrite(12, HIGH); //Establishes LEFT backward FULL SPEED
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 75);   //Spins the motor on Channel A at full speed 
  analogWrite(11,0);   //break for left wheel

 
  }
  else if(voltage1>1 && voltage2<1)  //right sensor got obstrcle
  {
     digitalWrite(13, HIGH);  //LEFT WHEEL MOVES BACKWARDS WITH FULL SPEED
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, 255); 
  analogWrite(3,0); // brake for right wheel

 
  }
  }

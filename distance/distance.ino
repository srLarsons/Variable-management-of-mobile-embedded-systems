void setup()
{
  Serial.begin(9600);
}
void loop()
{
 int x=analogRead(A3);
 int  y=analogRead(A2);
  int vol = x * (5.0 / 1023.0);
  int vol2 = y * (5.0 / 1023.0);
  
  Serial.print("vol");
  Serial.print(vol);

  Serial.print("\n"); 
  Serial.print("\n"); 
   Serial.print("vol2");
  Serial.print(vol2);

  Serial.print("\n"); 
  Serial.print("\n");
 digitalWrite(5,vol2);
  digitalWrite(6,vol);
  digitalWrite(7,LOW);
   /*if (vol<=1.5 && vol2<2.5 ) //not sensing both side then turn left
{

 digitalWrite(12, LOW);  //Establishes farward direction of Channel B
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(3, 150);
    
  //Motor B FARWARD @ half speed
  digitalWrite(13,HIGH);  //Establishes farward direction of Channel B
  digitalWrite(9, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, 255);
}
 else if ( 2<vol<=2.4 && vol2<2.5)// follow wall
{

 digitalWrite(12, LOW);  //Establishes farward direction of Channel B
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(3, 255);
    
  //Motor B FARWARD @ half speed
  digitalWrite(13, LOW);  //Establishes farward direction of Channel B
  digitalWrite(9, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, 255);
    
}
else if ( 1.5<vol<=2 && vol2<2.5)// set towards the path 
{

 digitalWrite(12, LOW);  //Establishes farward direction of Channel B
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(3, 255);
    
  //Motor B FARWARD @ half speed
  digitalWrite(13, LOW);  //Establishes farward direction of Channel B
  digitalWrite(9, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, 150);
}
else if (2.6>vol>2.4 && vol2<2.5)// set back to the path from close to wall
{

 digitalWrite(12, LOW);  //Establishes farward direction of Channel B
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(3, 150);
    
  //Motor B FARWARD @ half speed
  digitalWrite(13, LOW);  //Establishes farward direction of Channel B
  digitalWrite(9, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, 255);
}
else if (vol>=2.6 && vol2<2.5) //set back to the path  as above
{

 digitalWrite(12, LOW);  //Establishes farward direction of Channel B
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(3, 150);
    
  //Motor B FARWARD @ half speed
  digitalWrite(13, LOW);  //Establishes farward direction of Channel B
  digitalWrite(9, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, 255);
}
else if ( vol2>2.5 &&(2<vol<=2.4 or 1.5<vol<=2 or 2.6>vol>2.4 or vol>=2.6 ) ) //turn right
{

 digitalWrite(12, HIGH);  //Establishes farward direction of Channel B
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(3, 255);
    
  //Motor B FARWARD @ half speed
  digitalWrite(13, LOW);  //Establishes farward direction of Channel B
  digitalWrite(9, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, 255);
}
*/
}

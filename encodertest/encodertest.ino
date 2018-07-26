const int Encoder_Pin = 10; // output of encoder to interrupt #0, pin 2 of arduino

int Encoder_Count = 0;
long Time1 = 0;
long Time2 = 0;
long Time3 = 0;

void setup() 
{
  pinMode(12,OUTPUT);
  Serial.begin(9600);
  attachInterrupt(1, Count_Pulses, FALLING); //attach interrupt to encoder pin
}

void Count_Pulses() 

{
  //this is the function that runs every time pin 2 
  //switches from high to low
  Encoder_Count++;
}


void loop()

{
  Time1 = millis();
  Time3 = Time1 -= Time2;
  digitalWrite(12,HIGH);
  analogWrite(3,230);

  if (Time3 >= 500)
  {
   Time2 = millis ();
   int PulsSpeed = Encoder_Count;
   Encoder_Count = 0;
   Serial.println(PulsSpeed);
  }

}

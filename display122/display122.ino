int data = 6;
int clock = 5;
int enable = 7;
int led = 13;

void setup()
{
pinMode(data, OUTPUT);
pinMode(enable, OUTPUT);
pinMode(clock, OUTPUT);
pinMode(led, OUTPUT); 

writetoDisplay(B11100011,B11000011,B11111111);
}


void writetoDisplay(char digit1, char digit2, char digit3)
{

  char stream[36];
  stream[0]=1;
  for ( int i=1; i<36; i++ )
  {
    stream[i]=0;
  }
  for ( int i=0; i<8; i++ )
  {
    stream[i+1]=digit1 & (1<<(7-i));
  }
  for ( int i=0; i<8; i++ )
  {
    stream[i+10]=digit2 & (1<<(7-i));
  }
  for ( int i=0; i<8; i++ )
  {
    stream[i+17]=digit3 & (1<<(7-i));
  }
  
  for ( int i=0; i<36; i++ )
  {
    digitalWrite(enable, LOW);  
    digitalWrite(data, stream[i]);
    digitalWrite(clock, HIGH);
    digitalWrite(clock, LOW);
    digitalWrite(enable, HIGH);  
  }
}

void loop()
{
digitalWrite(led, HIGH);
delay(1000);
digitalWrite(led, LOW);
delay(1000);
}

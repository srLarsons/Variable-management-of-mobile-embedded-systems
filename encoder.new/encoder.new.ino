unsigned long count=0;
unsigned long timep, time, etime;
byte A,Ap;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
//count the channel a to pin 2
pinMode(2,INPUT);
//set the initial time
timep =micros();
//set the initial values of A
Ap= digitalRead(2);
}

void loop() {
  // put your main code here, to run repeatedly:
 // digitalWrite(12,LOW);
  //digitalWrite(3,100);
A=digitalRead(2);
if (A^Ap)//is there a difference?
{
  count++;//if so increment.
}
Ap=A;
time=micros();
etime=time-timep;
if(etime > 1000000)//every 1 sec
{
  Serial.print("count=");
  Serial.println(count);
   Serial.print("\n");
  timep =time;
}
}

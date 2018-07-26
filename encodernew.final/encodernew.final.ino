unsigned long count=0;
 double revolutions=0.0;
 double distancetravel=0.0;
unsigned long timep, time, etime;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
//count the channel a to pin 2
pinMode(2,INPUT);

attachInterrupt(0, transition, CHANGE);
//set the initial time
timep =micros();
//set the initial values of A
}
void transition()
{
  count++;
}

void loop() {
  // put your main code here, to run repeatedly:;
  //analogWrite(3,60);
time=micros();
etime=time-timep;
revolutions=(count/526.00);
//revolutions=(count/266.00);
distancetravel=(15.9*revolutions);
if(etime > 1000000)//every 1 sec
{
  Serial.print("count=");
  Serial.println(count);
  Serial.print("revolutions=");
  Serial.println(revolutions);
   Serial.print("distance travelled(in cm)=");
  Serial.println(distancetravel);
   Serial.print("\n");//
   //count=0;
  timep =time;
}
}

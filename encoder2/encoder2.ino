#define rmencpin    2                                           //  D3 is the pin for external interrupt 1      encod_R
#define rmdirpin      12                                           //  D8  right motor direction                   DIR_R
#define rmpwmpin  3    //10   //<< change             //  D10 right motor PWM                         PWM_R

volatile unsigned int rpulse=100000;                  // width of left and right encoder pulses in uS
unsigned long mtime;                                         // "no go" timer used to re-start motors when both motors stopped
volatile unsigned long rtime;                               // remembers time of right encoders last state change in uS

void setup()  {
  Serial.begin(9600);
  pinMode(rmdirpin,OUTPUT);
  digitalWrite(rmencpin,1);                                   // enable pullup resistor for right encoder sensor
  attachInterrupt(1,Rencoder,CHANGE);            // trigger right encoder ISR on state change
  digitalWrite(rmdirpin,true);                                // set direction of right motor
  analogWrite(rmpwmpin,250);  //<< change                    // speed for right motor}
}

void loop()  { 
  unsigned int temp;                                      // temporary variable for calculationa
  if(micros()-mtime>999)    {                          // Call motor control function every mS
    mtime=micros();                                       // reset motor timer
    Serial.println(rpulse);  //<< change
  }
}

void Rencoder()  {
  rpulse=micros()-rtime;                             // time between last state change and this state change
  rtime=micros();                                        // update ltime with time of most recent state change

}

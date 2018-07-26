#include <ArduinoRobot.h>

void setup(){
  Robot.begin();
}
void loop(){
  Robot.motorsWrite(255,255); //Make the robot go forward, full speed
  delay(1000);
  Robot.motorsWrite(0,0); //Make the robot stop
  delay(1000);
  Robot.motorsWrite(255,-255);//Make the robot rotate right, full speed
  delay(1000);
  Robot.motorsWrite(0,0); //Make the robot stop
  delay(1000);
}

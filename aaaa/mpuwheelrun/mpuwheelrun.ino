#include <Wire.h>
#include<I2Cdev.h>
#include<MPU6050.h>
 
MPU6050 mpu;
 
int16_t ax, ay, az;
int16_t gx, gy, gz;
 
#define pin1 3
#define pin2 11
 
void setup(){
 Serial.begin(115200);
 Serial.println("Initialize MPU");
 mpu.initialize();
 //Serial.println(mpu.testConnection() ? "Connected" : "Connection failed"); pinMode(pin1,OUTPUT);
 pinMode(pin1,OUTPUT);
 pinMode(pin2,OUTPUT);
 
}
 
void loop(){
 mpu.getMotion6(&ax, &az, &ay, &gx, &gz, &gy);
 //mpu.getRotation( &ax, &ay,  &az);
 ax = map(ax, -17000, 17000, -1500, 1500);
  ay = map(ay, -17000, 17000, -1500, 1500);
   az = map(az, -17000, 17000, -1500, 1500);
 Serial.print("ax=");
  
  Serial.print(ax);
  Serial.print("\n");
   Serial.print("ay=");
    Serial.print(ay);
    Serial.print("\n");
     Serial.print("az=");
      Serial.print(az);
      Serial.print("\n");
      delay(1000);
if (-2<ax<2)
{
  analogWrite(pin1,80);
  analogWrite(pin2,255);
}
else if (ax>2)
{
  analogWrite(pin1,100);
  analogWrite(pin2,255);
}
else if (ax<2)
{
  analogWrite(pin1,100);
  analogWrite(pin2,150);
}
}
 //Serial.println(ax);
/* if(ay > 0){
  if(ay<255){
  Serial.println(ay);
  analogWrite(pin1,ay);
   analogWrite(pin2,ay);
 }
 else{
  Serial.println("+255");
  analogWrite(pin1,255);
  analogWrite(pin2,255);
 }
 
 }
 if(ay<0){
  if(ay>-255){
  Serial.println(ay);
  analogWrite(pin1, ay-ay-ay);
  analogWrite(pin2, ay-ay-ay);
 }
 else{
  Serial.println("-255");
  analogWrite(pin1, 255);
  analogWrite(pin2, 255);
 }
 }
 delay(1000);
}*/

#include <NewPing.h>

#include <NewPing.h>

#define TRIGGER_PIN  14
#define ECHO_PIN     15
#define MAX_DISTANCE 20

NewPing DistanceSensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    unsigned int cm = DistanceSensor.ping_cm();
    Serial.print("Distance: ");
    Serial.print(cm);
    Serial.println("cm");
    delay(1000);
}

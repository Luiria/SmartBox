#include <Arduino.h>

#include "infra/UltraSonicSensor.h"
#include "app/DistanceMonitoringService.h"

#define echoPin 26
#define trigPin 27

UltraSonicSensor ultraSonicSensor(echoPin, trigPin);
IDistanceSensor &distanceSensor = ultraSonicSensor;

DistanceMonitoringService service(distanceSensor);

void setup()
{
  Serial.begin(115200);
  distanceSensor.begin();

  delay(2000);
  Serial.println("SETUP OK");
}

void loop()
{

  if (service.isDoorOpen())
  {
    Serial.println("Door Open");
  }

  if (service.isMailInserted())
  {
    Serial.println("Letter");
  }
  delay(1000);
}

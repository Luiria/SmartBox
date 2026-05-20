#include <Arduino.h>

#include "hal/IDistanceSensor.h"
#include "infra/UltraSonicSensor.h"

#define echoPin 26
#define trigPin 27

UltraSonicSensor ultraSonicSensor(echoPin, trigPin);
IDistanceSensor& sensor = ultraSonicSensor;

void setup()
{
  Serial.begin(115200);
  sensor.begin();

  delay(2000);
  Serial.println("SETUP OK");
}

void loop()
{
  sensor.read();
  Serial.println(sensor.getDistance());
  delay(1000);
}


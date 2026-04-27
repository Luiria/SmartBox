#include <Arduino.h>

#include "infra/UltraSonicSensor.h"

UltraSonicSensor sensor(26, 27);

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


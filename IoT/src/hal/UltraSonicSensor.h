#ifndef ULTRA_SONIC_SENSOR_H
#define ULTRA_SONIC_SENSOR_H

#include <Arduino.h>
#include "interfaces/IDistanceSensor.h"

class UltraSonicSensor : public IDistanceSensor
{
private:
    uint8_t echoPin;
    uint8_t trigPin;
    long distance;

public:
    UltraSonicSensor(uint8_t echoPin, uint8_t trigPin);

    void begin() override;
    void read() override;

    // GETTERS
    long getDistance() { return this->distance; };

    // SETTERS
    void setDistance(long newDistance) { this->distance = newDistance; };
};

#endif
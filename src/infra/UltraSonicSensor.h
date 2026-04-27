#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include <Arduino.h>

class UltraSonicSensor
{
private:
    uint8_t echoPin;
    uint8_t trigPin;
    long distance;

public:
    UltraSonicSensor(uint8_t echoPin, uint8_t trigPin);
    void begin();
    void read();

    // GETTERS
    long getDistance() { return this->distance; };
};

#endif
#include "UltraSonicSensor.h"

UltraSonicSensor::UltraSonicSensor(uint8_t echoPin, uint8_t trigPin)
    : trigPin(trigPin), echoPin(echoPin) {}

void UltraSonicSensor::begin()
{
    pinMode(this->trigPin, OUTPUT);
    pinMode(this->echoPin, INPUT);
}

void UltraSonicSensor::read()
{
    // Clears the trigPin
    digitalWrite(this->trigPin, LOW);
    delayMicroseconds(2);

    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(this->trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->trigPin, LOW);

    // Reads the echoPin, returns the sound wave travel time in microseconds
    long duration = pulseIn(this->echoPin, HIGH);

    // Calculating the distance
    this->distance = duration * 0.034 / 2;
}
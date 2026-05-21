#ifndef I_DISTANCE_SENSOR_H
#define I_DISTANCE_SENSOR_H

class IDistanceSensor
{

public:
    virtual void begin() = 0;
    virtual void read() = 0;
    virtual long getDistance() = 0;

    virtual ~IDistanceSensor() = default;
};

#endif
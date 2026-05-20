#include "hal/IDistanceSensor.h"
#include "DistanceMonitoringService.h"

#include <Arduino.h>

DistanceMonitoringService::DistanceMonitoringService(IDistanceSensor &sensor)
    : sensor(sensor)
{
    this->doorOpenThreshold  = 30;
    this->mailDetectedThreshold  = doorOpenThreshold  - 2;
}

bool DistanceMonitoringService::isDoorOpen()
{
    sensor.read();
    return sensor.getDistance() > getDoorOpenThreshold() ;
};

bool DistanceMonitoringService::isMailInserted()
{
    sensor.read();
    return sensor.getDistance() < getMailDetectedThreshold();
}
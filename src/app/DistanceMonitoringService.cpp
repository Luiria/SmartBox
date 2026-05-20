#include <Arduino.h>

#include "hal/IDistanceSensor.h"
#include "DistanceMonitoringService.h"

#include "MailBoxState.h"

DistanceMonitoringService::DistanceMonitoringService(IDistanceSensor &sensor)
    : sensor(sensor)
{
    this->doorOpenThreshold = 30;
    this->mailDetectedThreshold = doorOpenThreshold - 2;
    this->lastState = MailBoxState::NONE;
}

bool DistanceMonitoringService::isDoorOpen()
{
    return sensor.getDistance() > getDoorOpenThreshold();
};

bool DistanceMonitoringService::isMailInserted()
{

    return sensor.getDistance() < getMailDetectedThreshold();
};

MailBoxState DistanceMonitoringService::detectEvent()
{

    sensor.read();
    MailBoxState currentState = MailBoxState::NONE;

    if (isDoorOpen())
        currentState = MailBoxState::OPEN;

    else if (isMailInserted())
        currentState = MailBoxState::MAIL_INSERTED;

    else
        currentState = MailBoxState::CLOSED;

    // anti spam
    if (currentState == lastState)
    {
        return MailBoxState::NONE;
    }

    lastState = currentState;
    return currentState;
}

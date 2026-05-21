#ifndef DISTANCE_MONITORING_SERVICE_H
#define DISTANCE_MONITORING_SERVICE_H

#include "hal/IDistanceSensor.h"

#include "MailBoxState.h"

class DistanceMonitoringService
{

private:
    IDistanceSensor &sensor;
    int doorOpenThreshold;     // in cm
    int mailDetectedThreshold; // in cm
    
    MailBoxState lastState;

    bool isDoorOpen();
    bool isMailInserted();

public:
    DistanceMonitoringService(IDistanceSensor &sensor);

    MailBoxState detectEvent();

    // GETTERS
    int getDoorOpenThreshold() { return this->doorOpenThreshold; };
    int getMailDetectedThreshold() { return this->mailDetectedThreshold; };
};

#endif
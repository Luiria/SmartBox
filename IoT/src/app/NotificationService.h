#ifndef EMAIL_SERVICE_H
#define EMAIL_SERVICE_H

#include <Arduino.h>
#include "interfaces/INotificationSender.h"
#include "DistanceMonitoringService.h"

class NotificationService
{

private:
    INotificationSender &notificationSender;

public:
    NotificationService(INotificationSender &notificationSender);
    void send(const char *message, const char *email);
};

#endif
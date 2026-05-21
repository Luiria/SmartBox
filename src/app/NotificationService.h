#ifndef EMAIL_SERVICE_H
#define EMAIL_SERVICE_H

#include <Arduino.h>
#include "hal/INotificationSender.h"
#include "DistanceMonitoringService.h"

class NotificationService
{

private:
    INotificationSender &notificationSender;

public:
    NotificationService(INotificationSender &notificationSender);
    void sendNotif(MailBoxState event);
};

#endif
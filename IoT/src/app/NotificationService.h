#ifndef EMAIL_SERVICE_H
#define EMAIL_SERVICE_H

#include <Arduino.h>

#include "interfaces/INotificationSender.h"
#include "DistanceMonitoringService.h"

#include "domain/MailBoxState.h"
#include "domain/MailBoxMessage.h"

#include "secret.h"

class NotificationService
{

private:
    INotificationSender &notificationSender;

public:
    NotificationService(INotificationSender &notificationSender);
    void send(const char *message, const char *email);
};

#endif
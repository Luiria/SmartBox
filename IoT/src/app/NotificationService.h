#ifndef EMAIL_SERVICE_H
#define EMAIL_SERVICE_H

#include <Arduino.h>

#include "interfaces/IMessagePublisher.h"
#include "infra/MqttService.h"
#include "DistanceMonitoringService.h"

#include "domain/MailBoxState.h"
#include "domain/MailBoxMessage.h"

#include "secret.h"

class NotificationService
{

private:
    IMessagePublisher &publisher;

public:
    NotificationService(IMessagePublisher &publisher);
    void send(MailBoxState event);
};

#endif
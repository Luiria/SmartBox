#ifndef I_NOTIFICATION_SENDER_H
#define I_NOTIFICATION_SENDER_H

#include <Arduino.h>

class INotificationSender
{

public:
    virtual void send(const char *subject) = 0;
    virtual ~INotificationSender() = default;
};

#endif
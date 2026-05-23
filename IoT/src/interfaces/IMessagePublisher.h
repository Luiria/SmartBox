#ifndef I_NOTIFICATION_SENDER_H
#define I_NOTIFICATION_SENDER_H

#include <Arduino.h>

class IMessagePublisher
{

public:
    virtual void publish(const char *payload) = 0;
    virtual ~IMessagePublisher() = default;
};

#endif
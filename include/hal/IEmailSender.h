#ifndef I_EMAIL_SENDER_H
#define I_EMAIL_SENDER_H

#include <Arduino.h>

class IEmailSender
{

public:
    virtual void send(const char *subject) = 0;
    virtual ~IEmailSender() = default;
};

#endif
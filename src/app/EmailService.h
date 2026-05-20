#ifndef EMAIL_SERVICE_H
#define EMAIL_SERVICE_H

#include <Arduino.h>
#include "hal/IEmailSender.h"

class EmailService
{

private:
    IEmailSender &emailSender;

public:
    EmailService(IEmailSender &emailSender);
    void sendEmail(const char *subject);
};

#endif
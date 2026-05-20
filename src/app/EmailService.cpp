#include <Arduino.h>

#include "EmailService.h"
#include "hal/IEmailSender.h"

EmailService::EmailService(IEmailSender &emailSender)
    : emailSender(emailSender) {};

void EmailService::sendEmail(const char *subject)
{
    emailSender.send(subject);
}
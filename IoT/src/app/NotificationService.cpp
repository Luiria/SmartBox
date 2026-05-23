#include <Arduino.h>

#include "NotificationService.h"
#include "interfaces/INotificationSender.h"

#include "MailBoxState.h"
#include "MailBoxMessage.h"

#include "secret.h"

NotificationService::NotificationService(INotificationSender &notificationSender)
    : notificationSender(notificationSender) {};

void NotificationService::send(const char *message, const char *email)
{
    notificationSender.send(email, message);
};
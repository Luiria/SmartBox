#include <Arduino.h>

#include "NotificationService.h"
#include "hal/INotificationSender.h"

#include "MailBoxState.h"
#include "MailBoxMessages.h"

#include "secret.h"


NotificationService::NotificationService(INotificationSender &notificationSender)
    : notificationSender(notificationSender) {};

void NotificationService::sendNotif(MailBoxState event)
{
    const char *message = MailBoxMessages::getMessage(event);

    if (message != nullptr)
        notificationSender.send(USER_EMAIL, message);
};
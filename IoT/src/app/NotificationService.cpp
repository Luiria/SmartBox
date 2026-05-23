#include "NotificationService.h"

NotificationService::NotificationService(INotificationSender &notificationSender)
    : notificationSender(notificationSender) {};

void NotificationService::send(const char *message, const char *email)
{
    notificationSender.send(email, message);
};
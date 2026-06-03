#include "NotificationService.h"

NotificationService::NotificationService(IMessagePublisher &publisher)
    : publisher(publisher) {};

void NotificationService::send(MailBoxState event)
{

    if (event != MailBoxState::NONE)
    {

        const char *message = MailBoxMessages::getMessage(event);

        String payload = MailBoxMessages::buildEvent(
            USER_EMAIL,
            EMAIL_SUBJECT,
            message);

        this->publisher.publish(payload.c_str());
    }
};
#ifndef I_NOTIFICATION_SENDER_H
#define I_NOTIFICATION_SENDER_H

class INotificationSender
{

public:
    virtual void send(const char *userEmail, const char *message) = 0;
    virtual ~INotificationSender() = default;
};

#endif
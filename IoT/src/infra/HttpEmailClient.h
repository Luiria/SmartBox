#ifndef HTTP_EMAIL_CLIENT_H
#define HTTP_EMAIL_CLIENT_H

#include "interfaces/INotificationSender.h"
#include "Wifi.h"

class HttpEmailClient : public INotificationSender
{

private:
    Wifi &wifi;

    bool checkWifi();
    bool handleError(int httpResponseCode);

public:
    HttpEmailClient(Wifi &wifi);
    void send(const char *userEmail, const char *message) override;
};

#endif
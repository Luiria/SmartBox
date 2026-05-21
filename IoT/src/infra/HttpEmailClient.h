#ifndef HTTP_EMAIL_CLIENT_H
#define HTTP_EMAIL_CLIENT_H

#include "hal/INotificationSender.h"
#include "hal/IWifi.h"

class HttpEmailClient : public INotificationSender
{

private:
    IWifi &wifi;

    bool checkWifi();
    bool handleError(int httpResponseCode);

public:
    HttpEmailClient(IWifi &wifi);
    void send(const char *userEmail, const char *message) override;
};

#endif
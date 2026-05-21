#ifndef HTTP_EMAIL_CLIENT_H
#define HTTP_EMAIL_CLIENT_H

#include "hal/INotificationSender.h"
#include "hal/IWifi.h"

class HttpEmailClient : public INotificationSender
{

private:
    IWifi &wifi;

    bool checkWifi();
    void handleError(int httpResponseCode);

public:
    HttpEmailClient(IWifi &wifi);
    void send(const char *subject) override;
};

#endif
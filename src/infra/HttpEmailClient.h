#ifndef HTTP_EMAIL_CLIENT_H
#define HTTP_EMAIL_CLIENT_H

#include "hal/IEmailSender.h"
#include "hal/IWifi.h"

class HttpEmailClient : public IEmailSender
{

private:
    IWifi &wifi;

public:
    HttpEmailClient(IWifi &wifi);
    void send(const char *subject) override;
    bool checkWifi();
    void handleError(int httpResponseCode);
};

#endif
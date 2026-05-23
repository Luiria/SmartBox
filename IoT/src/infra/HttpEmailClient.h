#ifndef HTTP_EMAIL_CLIENT_H
#define HTTP_EMAIL_CLIENT_H

#include "interfaces/IMessagePublisher.h"
#include "Wifi.h"

class HttpEmailClient : public IMessagePublisher
{

private:
    Wifi &wifi;

    bool checkWifi();
    bool handleError(int httpResponseCode);

public:
    HttpEmailClient(Wifi &wifi);
    void publish(const char *payload) override;
};

#endif
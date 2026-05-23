#pragma once

#include <WiFi.h>
#include <PubSubClient.h>

#include "interfaces/IMessagePublisher.h"
#include "secret.h"

class MqttService : public IMessagePublisher
{

private:
    WiFiClient espClient;
    PubSubClient client;

    const char *server;
    int port;
    const char *user;
    const char *pass;

    void reconnect();

public:
    MqttService();
    void begin(const char *server, int port, const char *user, const char *pass);
    void loop();
    void publish(const char *payload) override;
};
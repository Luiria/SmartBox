#pragma once

#include <WiFi.h>
#include <PubSubClient.h>

#include "secret.h"

class MqttService
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
    void publish(String payload);
};
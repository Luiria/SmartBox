#pragma once

#include <WiFi.h>
#include <PubSubClient.h>

class MqttService
{

private:
    WiFiClient espClient;
    PubSubClient client;

public:
    MqttService();
    void begin(const char *server,  int port, const char *user, const char *pass);
    void publish(const char *topic, const char *message);
    void loop();
};
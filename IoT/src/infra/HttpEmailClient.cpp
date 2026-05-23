// #include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>

#include "HttpEmailClient.h"
#include "./secret.h"

HttpEmailClient::HttpEmailClient(Wifi &wifi)
    : wifi(wifi) {};

bool HttpEmailClient::checkWifi()
{

    if (!this->wifi.isConnected())
    {
        Serial.println("WiFi disconnected");
        return false;
    }

    return true;
};

bool HttpEmailClient::handleError(int httpResponseCode)
{

    if (httpResponseCode < 200 || httpResponseCode >= 300)
    {
        Serial.print("HTTP FAILED: ");
        Serial.println(httpResponseCode);
        return false;
    }

    return true;
}

void HttpEmailClient::publish(const char *payload)
{
    if (!checkWifi())
        return;

    WiFiClientSecure client;
    client.setInsecure();

    HTTPClient http;
    http.begin(client, WEBHOOK_URL);
    http.addHeader("Content-Type", "application/json");

    int httpResponseCode = http.POST(payload);

    if (!handleError(httpResponseCode))
        return;

    Serial.print("HTTP SEND :");
    Serial.println(httpResponseCode);

    http.end();
};

// #include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>

#include "HttpEmailClient.h"
#include "./secret.h"

WiFiClientSecure client;

HttpEmailClient::HttpEmailClient(IWifi &wifi)
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

void HttpEmailClient::handleError(int httpResponseCode)
{

    if (httpResponseCode < 0)
    {
        Serial.print("HTTP error: ");
        Serial.println(httpResponseCode);
    }
}

void HttpEmailClient::send(const char *subject)
{

    if (!checkWifi())
        return;

    client.setInsecure();
    HTTPClient http;
    http.begin(WEBHOOK_URL);

    http.addHeader("Content-Type", "application/json");

    char payload[100];
    sprintf(payload, "{\"subject\":\"%s\"}", subject);

    int httpResponseCode = http.POST(payload);
    handleError(httpResponseCode);
    http.end();
};

// #include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>

#include "HttpEmailClient.h"
#include "./secret.h"

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

    if (httpResponseCode <= 0)
    {
        Serial.print("HTTP FAILED: ");
        Serial.println(httpResponseCode);
    }
}

void HttpEmailClient::send(const char *subject)
{
    if (!checkWifi())
        return;

    WiFiClientSecure client;
    client.setInsecure();

    HTTPClient http;
    http.begin(client, WEBHOOK_URL);
    http.addHeader("Content-Type", "application/json");

    String payload = String("{\"subject\":\"") + subject + "\"}";

    int httpResponseCode = http.POST(payload);
    handleError(httpResponseCode);

    Serial.println("HTTP SEND: ");
    http.end();
};

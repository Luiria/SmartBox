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

bool HttpEmailClient::handleError(int httpResponseCode)
{

    if (httpResponseCode <= 0)
    {
        Serial.print("HTTP FAILED: ");
        Serial.println(httpResponseCode);
        return false;
    }

    return true;
}

void HttpEmailClient::send(const char *userEmail, const char *message)
{
    if (!checkWifi())
        return;

    WiFiClientSecure client;
    client.setInsecure();

    HTTPClient http;
    http.begin(client, WEBHOOK_URL);
    http.addHeader("Content-Type", "application/json");

    String payload = String("{") +
                     "\"email\":\"" + userEmail +
                     "\"," + "\"subject\":\"SmartBox - Nouvelle activité détectée\"," +
                     "\"message\":\"" + message + "\"" +
                     "}";

    int httpResponseCode = http.POST(payload);

    if (handleError(httpResponseCode))
        Serial.println("HTTP SEND");

    http.end();
};

#include <WiFiClientSecure.h>

#include "Wifi.h"
#include "./secret.h"

void Wifi::connect()
{
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("WiFi connected");
}

bool Wifi::isConnected()
{
    return WiFi.status() == WL_CONNECTED;
}
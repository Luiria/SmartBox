#include <Arduino.h>

#include "secret.h"
#include "infra/MqttService.h"

#include "infra/UltraSonicSensor.h"
#include "app/DistanceMonitoringService.h"

#include "infra/HttpEmailClient.h"
#include "app/NotificationService.h"

#include "infra/Wifi.h"

#include "MailBoxState.h"
#include "MailBoxMessages.h"

#define echoPin 26
#define trigPin 27

// SENSOR
UltraSonicSensor ultraSonicSensor(echoPin, trigPin);
IDistanceSensor &distanceSensor = ultraSonicSensor;

// WIFI
Wifi wifi;
IWifi &wifiManager = wifi;

// EMAIL
HttpEmailClient httpEmail(wifiManager);
INotificationSender &notificationSender = httpEmail;

// SERVICES
DistanceMonitoringService monitoringService(distanceSensor);
NotificationService notifierService(notificationSender);

MqttService mqtt;

void setup()
{
  Serial.begin(115200);

  wifi.connect();
  mqtt.begin(MQTT_SERVER, MQTT_PORT, MQTT_USER, MQTT_KEY);

  distanceSensor.begin();

  delay(2000);

  Serial.println("SETUP OK");
}

void loop()
{

  mqtt.loop();

  Serial.println("start");
  MailBoxState event = monitoringService.detectEvent();

  // notifierService.sendNotif(event);

  const char *message = MailBoxMessages::getMessage(event);

  if (message != nullptr)
  {

    static unsigned long lastSend = 0;

    if (millis() - lastSend > 5000)
    {
      lastSend = millis();

      String payload = String("{") +
                       "\"email\":\"" + USER_EMAIL +
                       "\"," + "\"subject\":\"SmartBox - Nouvelle activité détectée\"," +
                       "\"message\":\"" + message + "\"" +
                       "}";

      String feed = String(MQTT_USER) + "/feeds/" + MQTT_FEED_NAME;
      mqtt.publish(feed.c_str(), payload.c_str());
      Serial.println("MQTT SEND");
    }
  }

  delay(1000);
}

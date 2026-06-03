#include <Arduino.h>

#include "secret.h"
#include "infra/MqttService.h"

#include "interfaces/IDistanceSensor.h"
#include "app/DistanceMonitoringService.h"

#include "infra/HttpEmailClient.h"
#include "app/NotificationService.h"

#include "infra/Wifi.h"

#include "hal/UltraSonicSensor.h"

#include "domain/MailBoxState.h"
#include "domain/MailBoxMessage.h"

#define echoPin 26
#define trigPin 27

// SENSOR
UltraSonicSensor ultraSonicSensor(echoPin, trigPin);
IDistanceSensor &distanceSensor = ultraSonicSensor;
DistanceMonitoringService monitoringService(distanceSensor);

// WIFI
Wifi wifi;

// NOTIFICATION
HttpEmailClient httpEmail(wifi);
MqttService mqtt;

IMessagePublisher *publisher = nullptr;
NotificationService *notifierService = nullptr;

void setup()
{
  Serial.begin(115200);

  wifi.connect();

  if (PUBLISH_MODE == MQTT_MODE)
  {
    publisher = &mqtt;
    mqtt.begin(MQTT_SERVER, MQTT_PORT, MQTT_USER, MQTT_KEY);

    Serial.println("MODE MQTT");
  }
  else
  {
    publisher = &httpEmail;
    Serial.println("MODE HTTP");
  }

  static NotificationService service(*publisher);
  notifierService = &service;

  distanceSensor.begin();

  delay(2000);
  Serial.println("SETUP OK");
}

void loop()
{
  if (PUBLISH_MODE == MQTT_MODE)
    mqtt.loop();

  MailBoxState event = monitoringService.detectEvent();
  notifierService->send(event);

  delay(1000);
}

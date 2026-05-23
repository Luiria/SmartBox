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

// EMAIL
HttpEmailClient httpEmail(wifi);
INotificationSender &notificationSender = httpEmail;

// NOTIFICATION
NotificationService notifierService(notificationSender);

// MQTT
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

  if (event != MailBoxState::NONE)
  {

    const char *message = MailBoxMessages::getMessage(event);

    String payload = MailBoxMessages::buildEvent(
        USER_EMAIL,
        EMAIL_SUBJECT,
        message);

    // notifierService.send(message, USER_EMAIL);
    mqtt.publish(payload);
  }

  delay(1000);
}

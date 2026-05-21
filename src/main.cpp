#include <Arduino.h>

#include "infra/UltraSonicSensor.h"
#include "app/DistanceMonitoringService.h"

#include "infra/HttpEmailClient.h"
#include "app/NotificationService.h"

#include "infra/Wifi.h"

#include "MailBoxState.h"

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

void setup()
{
  Serial.begin(115200);

  wifi.connect();
  distanceSensor.begin();

  delay(2000);

  Serial.println("SETUP OK");
}

void loop()
{
  MailBoxState event = monitoringService.detectEvent();
  notifierService.sendNotif(event);

  delay(1000);
}

#include <Arduino.h>

#include "infra/UltraSonicSensor.h"
#include "app/DistanceMonitoringService.h"

#include "infra/HttpEmailClient.h"
#include "app/EmailService.h"

#include "infra/Wifi.h"

#define echoPin 26
#define trigPin 27

UltraSonicSensor ultraSonicSensor(echoPin, trigPin);
IDistanceSensor &distanceSensor = ultraSonicSensor;
DistanceMonitoringService service(distanceSensor);

Wifi wifi;
IWifi &wifiManager = wifi;

HttpEmailClient httpEmail(wifiManager);
IEmailSender &emailSender = httpEmail;
EmailService emailService(emailSender);

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

  if (service.isDoorOpen())
  {
    Serial.println("Door Open");
    emailService.sendEmail("door Open");
  }

  if (service.isMailInserted())
  {
    Serial.println("Letter");
    emailService.sendEmail("letter");
  }

  delay(1000);
}

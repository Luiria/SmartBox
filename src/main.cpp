#include <Arduino.h>

#include "infra/UltraSonicSensor.h"
#include "app/DistanceMonitoringService.h"

#include "infra/HttpEmailClient.h"
#include "app/EmailService.h"

#include "infra/Wifi.h"

#include "MailBoxState.h"

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

  MailBoxState eventBox = service.detectEvent();

  switch (eventBox)
  {
  case MailBoxState::OPEN:
    emailService.sendEmail("Door opened");
    break;

  case MailBoxState::MAIL_INSERTED:
    emailService.sendEmail("Letter");
    break;

  default:
    break;
  }

  delay(1000);
}

#include "MqttService.h"


MqttService::MqttService() : client(espClient) {}

void MqttService::begin(const char *server, int port, const char *user, const char *pass)
{

  this->server = server;
  this->port = port;
  this->user = user;
  this->pass = pass;

  client.setServer(server, port);
  client.connect("ESP32Client", user, pass);
}

void MqttService::loop()
{

  if (!client.connected())
  {
    reconnect();
  }

  client.loop();
}

void MqttService::reconnect()

{
  while (!client.connected())
  {
    Serial.print("Connecting MQTT...");

    if (client.connect("ESP32Client", this->user, this->pass))
    {
      Serial.println("CONNECTED");
    }
    else
    {
      Serial.print("FAILED : ");
      Serial.println(client.state());

      delay(5000);
    }
  }
}

void MqttService::publish(String payload)
{
  if (!client.connected())
    reconnect();

  String feed = String(MQTT_USER) + "/feeds/" + MQTT_FEED_NAME;

  client.publish(feed.c_str(), payload.c_str());
  Serial.println("MQTT SEND");
}
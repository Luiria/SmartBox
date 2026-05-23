#include "MqttService.h"

MqttService::MqttService() : client(espClient) {}

void MqttService::begin(const char* server,  int port, const char* user, const char* pass) {
  client.setServer(server, port);
  client.connect("ESP32Client", user, pass);
}

void MqttService::publish(const char* topic, const char* message) {
  client.publish(topic, message);
}

void MqttService::loop() {
  client.loop();
}
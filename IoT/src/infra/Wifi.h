#ifndef WIFI_H
#define WIFI_H

#include <WiFiClientSecure.h>

#include "./secret.h"

class Wifi 
{

public:
    void connect() ;
    bool isConnected() ;
};

#endif
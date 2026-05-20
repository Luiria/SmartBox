#ifndef WIFI_H
#define WIFI_H

#include "hal/IWifi.h"

class Wifi : public IWifi
{

public:
    void connect() override;
    bool isConnected() override;
};

#endif
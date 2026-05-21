#ifndef I_WIFI_H
#define I_WIFI_H

class IWifi
{
public:
     virtual void connect() = 0;
    virtual bool isConnected() = 0;
    
    virtual ~IWifi() = default;
};

#endif
#ifndef DomoticzGateway_h
#define DomoticzGateway_h

#include "Arduino.h"
#include <UIPEthernet.h>
#include "Sensor.h"

class DomoticzGateway {

public:
	DomoticzGateway(){}
	DomoticzGateway(IPAddress address, unsigned int domoticzPort);
	void notifyDomoticz(int idx, int value);
	void notifyDomoticz(const Sensor * s);

	const IPAddress& getDzServerHost() const {
		return _dzServerHost;
	}

	void setDzServerHost(const IPAddress  dzServerHost) {
		_dzServerHost = dzServerHost;
	}

	unsigned int getDzServerPort() const {
		return _dzServerPort;
	}

	void setDzServerPort(unsigned int dzServerPort) {
		_dzServerPort = dzServerPort;
	}

class DomoticzGateway
{
  public:
    DomoticzGateway(IPAddress address, unsigned int domoticzPort);
    void notifyDomoticz(int idx, double value);
    
    
  private:
    IPAddress _dzSevrerHost;
    unsigned int _dzSevrerPort;
};

#endif

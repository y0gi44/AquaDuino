#ifndef DomoticzGateway_h
#define DomoticzGateway_h

#include "Arduino.h"
#include <UIPEthernet.h>
#include "Sensors/Sensor.h"

class DomoticzGateway {

private:
    IPAddress _dzServerHost;
    unsigned int _dzServerPort;

public:
	DomoticzGateway(){}
	DomoticzGateway(IPAddress address, unsigned int domoticzPort);
	void notifyDomoticz(int idx, int value);
    void notifyDomoticz(int idx, double value);
    void notifyDomoticz(const Sensor * s);

	IPAddress getDzServerHost() const {
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

};
#endif

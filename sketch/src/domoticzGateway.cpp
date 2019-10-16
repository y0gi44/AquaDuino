#include "domoticzGateway.h"

DomoticzGateway::DomoticzGateway(IPAddress address, unsigned int domoticzPort) {
	_dzServerHost = address;
	_dzServerPort = domoticzPort;
}

void DomoticzGateway::notifyDomoticz(int idx, double value) {
	EthernetClient client;
	if (client.connect(this->_dzServerHost, this->_dzServerPort)) {
		client.print(F("GET /json.htm?type=command&param=udevice&idx="));
		client.print(idx);
		client.print(F("&nvalue="));
		client.print(value);
		client.print(F("&svalue="));
		client.print(value);
		client.print(F(" HTTP/1.1\r\nHost: "));

		client.print((int) this->_dzServerHost[0]);
		client.print(F("."));
		client.print((int) this->_dzServerHost[1]);
		client.print(F("."));
		client.print((int) this->_dzServerHost[2]);
		client.print(F("."));
		client.print((int) this->_dzServerHost[3]);

		signed long next = millis() + 100;
		while (client.available() == 0) {
			if (next - millis() < 0)
				goto close;
		}
		int size;
		while ((size = client.available()) > 0) {
			char c = client.read();
#if defined(DEV_MODE)
			Serial.write(c);
#endif
		}
		close: client.stop();
	}
#if defined(DEV_MODE)
	else
	Serial.println(F("Client connect failed"));
#endif
}


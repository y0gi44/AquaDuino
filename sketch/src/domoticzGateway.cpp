#include "domoticzGateway.h"

DomoticzGateway::DomoticzGateway(IPAddress address, unsigned int domoticzPort){
  _dzSevrerHost = address;
  _dzSevrerPort = domoticzPort;
}


void DomoticzGateway::notifyDomoticz(int idx, double value){
  EthernetClient client;
  if (client.connect(_dzSevrerHost,_dzSevrerPort))
  {
    client.print(F("GET /json.htm?type=command&param=udevice&idx="));
    client.print(idx);
    client.print(F("&nvalue="));
    client.print(value);
    client.print(F("&svalue="));
    client.print(value);
    client.print(F(" HTTP/1.1\r\nHost: "));
    
    client.print((int)_dzSevrerHost[0]);
    client.print(F("."));
    client.print((int)_dzSevrerHost[1]);
    client.print(F("."));
    client.print((int)_dzSevrerHost[2]);
    client.print(F("."));
    client.print((int)_dzSevrerHost[3]);

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
	} else {
#if defined(DEV_MODE)
		Serial.print(F("noDzServer Initialised");
#endif

    signed long next = millis() + 100;
    while(client.available()==0)
    {
      if (next - millis() < 0)
        goto close;
    }
    int size;
    while((size = client.available()) > 0)
    {
       char c = client.read();
      #if defined(DEV_MODE) 
        Serial.write(c);
      #endif
    }
 close:
     client.stop();
   }
   #if defined(DEV_MODE) 
    else
      Serial.println(F("Client connect failed"));
   #endif
}

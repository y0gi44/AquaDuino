#include <Arduino.h>

#ifndef CO2DOSING_PUMP_H
#define CO2DOSING_PUMP_H

#include "Actuator.h"

class Co2DosingPump: public Actuator {

private :
	byte _pin;
	uint8_t _mlPerMinute;

public :
	Co2DosingPump(byte pin);

	void calibrateDosingPump(uint8_t mlPerMinute){
		_mlPerMinute = mlPerMinute;
	}

	void justDoIt(double unit = 0);


};

#endif

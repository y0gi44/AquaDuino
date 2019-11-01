#ifndef CO2DOSING_PUMP_H
#define CO2DOSING_PUMP_H

#include <Arduino.h>
#include "Actuator.h"

class Co2DosingPump : public Actuator {

private:
	byte _pin;
	uint8_t _mlPerMinute;

protected:
	// ne fait rien, c'est une pompe
	void setOn() {}
	// ne fait rien, c'est une pompe elle ne fait que doser :)
	void setOff() {}

public:
	Co2DosingPump(byte pin);

	void calibrateDosingPump(uint8_t mlPerMinute) {
		_mlPerMinute = mlPerMinute;
	}

	void justDoIt(double unit = 0);

};

#endif

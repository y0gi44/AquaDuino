#ifndef TURBIDITYSENSOR_H
#define TURBIDITYSENSOR_H

#include "Sensor.h"

class TurbiditySensor : public Sensor {

private:
	byte _pin;
	double _currentValue;

public:
	TurbiditySensor( byte userPin ) ;
	~TurbiditySensor(){};

	//read function must be implemented
	void refreshSensor();
};


#endif

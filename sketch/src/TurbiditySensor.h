#ifndef TURBIDITYSENSOR_H
#define TURBIDITYSENSOR_H

#include "Sensor.h"

class TurbiditySensor : public Sensor {

private:
	byte _pin;
	double _currentValue;

public:
	TurbiditySensor( byte userPin ) ;
	TurbiditySensor( byte userPin, uint8_t idDz, String desc ) ;
	~TurbiditySensor(){};

	//read function must be implemented
	double read();
	void refreshSensor();

	void setPower(bool b){};
};


#endif

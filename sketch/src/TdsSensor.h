#ifndef TDSSENSOR_H
#define TDSSENSOR_H

#include "Sensor.h"
#include "GravityTDS.h"

class TdsSensor : public Sensor {

private:
	byte _pin;
	GravityTDS _gravityTds;
	double _currentValue;

public:
	TdsSensor( byte userPin ) ;
	TdsSensor( byte userPin, uint8_t idDz, String desc ) ;
	~TdsSensor(){};

    double read();
    void refreshSensor();
	void setPower(bool b){};


};


#endif

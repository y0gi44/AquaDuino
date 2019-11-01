#ifndef TDSSENSOR_H
#define TDSSENSOR_H

#include "Sensor.h"
#include "GravityTDS.h"

class TdsSensor : public Sensor {

private:
	byte _pin;
	GravityTDS _gravityTds;

public:
	TdsSensor( byte userPin ) ;
	TdsSensor( byte userPin, uint8_t idDz, String desc ) ;
	~TdsSensor(){};

    void refreshSensor();


};


#endif

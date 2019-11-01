#ifndef PHSENSOR_H
#define PHSENSOR_H

#include "Sensor.h"
// détermine le nombre d'échantillons de mesure (on extrait la moyenne en excluant les 2 + haute et 2 + basse)
#define NB_SAMPLES 20 

class PhSensor : public Sensor {
private:
	byte _pin;
	int _buf[NB_SAMPLES];
	double _currentValue;

public:
    PhSensor( byte userPin ) ;
    PhSensor( byte userPin, uint8_t idDz, String desc ) ;
    ~PhSensor(){};

	//read function must be implemented
	void refreshSensor();

};


#endif

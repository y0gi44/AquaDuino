#include <Arduino.h>

#ifndef FOOD_DISTRIBUTOR_H
#define FOOD_DISTRIBUTOR_H

#include "Actuator.h"

class FoodDistributor: public Actuator {

private :
	byte _pinPwr;
	byte _pinDistribute;

public :
	FoodDistributor(byte pinpower, byte pinDistribute);

	void justDoIt(double unit = 0);

};

#endif

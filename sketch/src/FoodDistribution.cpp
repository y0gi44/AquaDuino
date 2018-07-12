#include "FoodDistribution.h"

void pressbutton(byte pin);

FoodDistributor::FoodDistributor(byte pinPower, byte pinDistribute) :
		_pinPwr(pinPower), _pinDistribute(pinDistribute), _unit("time") {
	pinMode(_pinPwr, OUTPUT);
	pinMode(_pinDistribute, OUTPUT);
	digitalWrite(pinPower, LOW);
	digitalWrite(_pinDistribute, LOW);
}

void FoodDistributor::justDoIt(double unit) {

	// allumage du distributeur
	pressbutton(_pinPwr);
	delay(300);

	pressbutton(_pinDistribute);
	delay(5000);

	// extinction
	pressbutton(_pinPwr);
}

void pressbutton(byte pin) {
	digitalWrite(pin, LOW);
	delay(100);
	digitalWrite(pin, HIGH);
}

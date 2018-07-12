#include "Co2DosingPump.h"

Co2DosingPump::Co2DosingPump(byte pin) :
		_pin(pin), _unit("ml") {
	_mlPerMinute = 60;
	pinMode(_pin, OUTPUT);
	digitalWrite(_pin, LOW);
}

//
void Co2DosingPump::justDoIt(double unit) {
	// calcul du temps d'activation de la pompe de dosage.
	double durationMs = unit * 1.0 / (_mlPerMinute / 60) * 1000;

	// allumage de la pompe
	digitalWrite(_pin, HIGH);

	// attente
	delay(durationMs);

	// extinction de la pompe
	digitalWrite(_pin, LOW);
}

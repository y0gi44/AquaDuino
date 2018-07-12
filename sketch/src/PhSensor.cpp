#include "PhSensor.h"

PhSensor::PhSensor(byte userPin) {
	_pin = userPin;
}

PhSensor::PhSensor(byte userPin, uint8_t idDz, String desc) {
	this(userPin);
	_desc = desc;
	_dzIdx = idDz;
}

double PhSensor::read() {
	int temp;

	// récupération d'un échnatillon de n mesures
	for (int i = 0; i < NB_SAMPLES; i++) {
		_buf[i] = analogRead(_pin);
		delay(10);
	}

	// tri des valeurs
	for (int i = 0; i < NB_SAMPLES - 1; i++) {
		for (int j = i + 1; j < NB_SAMPLES; j++) {
			if (_buf[i] > _buf[j]) {
				temp = _buf[i];
				_buf[i] = _buf[j];
				_buf[j] = temp;
			}
		}
	}

	double avgValue = 0;
	for (int i = 2; i < NB_SAMPLES - 2; i++) { // suppression des 2 valeurs de chaque coté des extremes
		avgValue += _buf[i];
	}
	double phValue = (double) avgValue * 5.0 / 1024 / (NB_SAMPLES - 4); //convert the analog into millivolt
	phValue = 3.5 * phValue;               //convert the millivolt into pH value

	return phValue;
}


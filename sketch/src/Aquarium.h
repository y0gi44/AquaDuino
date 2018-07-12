/*
 * Aquarium.h
 *
 *  Created on: 4 juil. 2018
 *      Author: yogi
 */

#ifndef SRC_AQUARIUM_H_
#define SRC_AQUARIUM_H_

#include "Sensor.h"
#include "Actuator.h"

#define MAX_SENSORS 10
#define MAX_ACTUATOR 10


class Aquarium {

private :
	Sensor * _tabSensors[MAX_SENSORS];
	uint8_t _nbSensors;

	Actuator * _tabActuator[MAX_ACTUATOR];
	uint8_t _nbActuators;

public:
	Aquarium();
	virtual ~Aquarium();

	void beginAll();
	void refreshSensors();
	void registerNewSensor(Sensor * s);
	void registerNewActuator(Actuator * s);

	uint8_t getNbSensors() const {
		return _nbSensors;
	}

	const Sensor* getSensors(uint8_t id) const {
		return _tabSensors[id];
	}
};

#endif /* SRC_AQUARIUM_H_ */

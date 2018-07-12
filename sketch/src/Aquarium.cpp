/*
 * Aquarium.cpp
 *
 *  Created on: 4 juil. 2018
 *      Author: yogi
 */

#include "Aquarium.h"

#include <Arduino.h>

Aquarium::Aquarium() : _nbActuators (0), _nbSensors (0){
}

Aquarium::~Aquarium() {
	// TODO Auto-generated destructor stub
}

void Aquarium::registerNewSensor(Sensor* s) {
	this->_tabSensors[this->_nbSensors++] = s;
}

void Aquarium::registerNewActuator(Actuator * s) {
	this->_tabActuator[this->_nbActuators++] = s;
}


void Aquarium::refreshSensors() {
	// Allumage des capteurs
	for (uint8_t i = 0; i < this->_nbSensors; i++) {
		this->_tabSensors[i]->setPower(POWER_ON);
	}

	// allumage des capteurs et attente de 100 ms
	delay(300);

	// prise des mesures
	for (uint8_t i = 0; i < this->_nbSensors; i++) {
		this->_tabSensors[i]->refreshSensor();
	}

	//Extinction des capteurs
	for (uint8_t i = 0; i < this->_nbSensors; i++) {
		this->_tabSensors[i]->setPower(POWER_ON);
	}
}

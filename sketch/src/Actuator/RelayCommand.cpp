/*
 * RelayCommand.cpp
 *
 *  Created on: 31 oct. 2019
 *      Author: yogi
 */

#include "RelayCommand.h"

RelayCommand::RelayCommand(byte pin) {
	this->_pin = pin;
	pinMode(this->_pin, OUTPUT);
}

RelayCommand::~RelayCommand() {
}


void RelayCommand::setOn(){
	digitalWrite(this->_pin, HIGH);
}

void RelayCommand::setOff(){
	digitalWrite(this->_pin, LOW);
}

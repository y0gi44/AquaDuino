/*
 * RelayCommand.h
 *
 *  Created on: 31 oct. 2019
 *      Author: yogi
 */

#ifndef SRC_RELAYCOMMAND_H_
#define SRC_RELAYCOMMAND_H_

#include <Arduino.h>
#include "Actuator.h"

class RelayCommand: public  Actuator {
private :
	byte _pin;

	void setOn();
	void setOff();

public:
	RelayCommand(byte pin);
	virtual ~RelayCommand();

	void justDoIt(double unit = 0) {};
};

#endif /* SRC_RELAYCOMMAND_H_ */

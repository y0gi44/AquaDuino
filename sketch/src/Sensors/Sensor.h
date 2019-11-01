#ifndef SENSOR_H
#define SENSOR_H

#include "Arduino.h"

#define POWER_OFF false
#define POWER_ON true

//abstract class Sensor
class Sensor {

protected:
	uint8_t _dzIdx = 0;
	String _desc;
	String _shortDesc;
	String _unitReadValue;
	double _currentValue;

public:

	virtual ~Sensor() {}

	//initialize the sensor
	inline virtual void init() { /* ne fait rien par défaut */ }	;

	//Fonction virtuelle de rafraichissement de la valeur du capteur, mise à jour de la variable _currentValue
	virtual void refreshSensor() = 0;

	//accesseur à la valeur courante
	double read() { return this->_currentValue;}

	inline virtual void setPower(bool b) {};

	/* partie getter et setter de paramètre domoticz */
	uint8_t getDzIdx() const {
		return _dzIdx;
	}
	void setDzIdx(uint8_t dzIdx) {
		_dzIdx = dzIdx;
	}

	/* partie getter et setter de paramètre générique description, short desc,  unité de mesure */
	const String& getDesc() const {
		return _desc;
	}

	void setDesc(const String& desc) {
		_desc = desc;
	}

	const String& getShortDesc() const {
		return _shortDesc;
	}

	void setShortDesc(const String& shortDesc) {
		_shortDesc = shortDesc;
	}

	const String& getUnitReadValue() const {
		return _unitReadValue;
	}

	void setUnitReadValue(const String& unitReadValue) {
		_unitReadValue = unitReadValue;
	}

	int getType() {
		return 0;
	}

};
#endif


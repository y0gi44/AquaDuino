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

public:

	virtual ~Sensor() = 0;

	//initialize the sensor
	inline virtual void begin() { /*nothing*/
	}
	;

	//read function must be implemented
	virtual void refreshSensor() = 0;

	//this is called a pure virtual function
	virtual double read() = 0;

	inline virtual void setPower(bool b) = 0;

	uint8_t getDzIdx() const {
		return _dzIdx;
	}
	void setDzIdx(uint8_t dzIdx) {
		_dzIdx = dzIdx;
	}

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


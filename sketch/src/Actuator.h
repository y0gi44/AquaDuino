#ifndef ACTUATOR_H
#define ACTUATOR_H
//abstract class Sensor
class Actuator {

protected:
	String _desc;
	String _unit;
	double lastCommand;
	Date

public:
	//initialize the actuator
	inline virtual void begin() { /*nothing*/
	}
	;

	/*
	 * Fonction générique d'action
	 */
	inline virtual void justDoIt(double unit = 0);

	const String& getDesc() const {
		return _desc;
	}

	void setDesc(const String& desc) {
		_desc = desc;
	}

};
#endif


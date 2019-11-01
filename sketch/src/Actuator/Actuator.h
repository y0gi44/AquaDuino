#ifndef ACTUATOR_H
#define ACTUATOR_H
//abstract class Sensor
class Actuator {

protected:
	String _desc;
	String _unit;
	bool state = false;

	virtual void setOn() = 0 ;
	virtual void setOff() = 0 ;


public:
	//initialize the actuator
	inline virtual void begin() { /*nothing*/
	}
	;

	/*
	 * Fonction générique type
	 */
	virtual void justDoIt(double unit = 0);


	inline void on() {
		this->setOn();
		state = true;
	}

	inline void off(){
		this->setOff();
		state = false;
	}

	inline void toggle() {
		if (this->isOn()) {
			off();
		}
		else {
			on();
		}
	}

	inline bool isOn(){ return state; }

	inline const String& getDesc() const {
		return _desc;
	}

	inline void setDesc(const String& desc) {
		_desc = desc;
	}

};
#endif


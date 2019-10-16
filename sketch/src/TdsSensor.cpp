#include "TdsSensor.h"

// https://www.dfrobot.com/wiki/index.php/Gravity:_Analog_TDS_Sensor_/_Meter_For_Arduino_SKU:_SEN0244
// Documentation de la sonde TDS DF-Robot

TdsSensor::TdsSensor(byte userPin) {
	this->_pin = userPin;
	this->_gravityTds.setPin(this->_pin);
	this->_gravityTds.setAref(5.0); //reference voltage on ADC, default 5.0V on Arduino UNO
	this->_gravityTds.setAdcRange(1024);  //1024 for 10bit ADC;4096 for 12bit ADC
	this->_gravityTds.begin();  //initialization
	setUnitReadValue("ppm");
}

TdsSensor::TdsSensor(byte userPin, uint8_t idDz, String desc) {
	this->_pin = userPin;
	this->_gravityTds.setPin(this->_pin);
	this->_gravityTds.setAref(5.0); //reference voltage on ADC, default 5.0V on Arduino UNO
	this->_gravityTds.setAdcRange(1024);  //1024 for 10bit ADC;4096 for 12bit ADC
	this->_gravityTds.begin();  //initialization
	setUnitReadValue("ppm");

	this->_desc = desc;
	this->_dzIdx = idDz;
}

void TdsSensor::refreshSensor(){
	float temperature = 25.0;
	this->_gravityTds.setTemperature(temperature); // set the temperature and execute temperature compensation
	this->_gravityTds.update();  //sample and calculate
	this->_currentValue = _gravityTds.getTdsValue(); ;
}

double TdsSensor::read() {
	return this->_currentValue;
}


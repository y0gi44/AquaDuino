#include "TdsSensor.h"

// https://www.dfrobot.com/wiki/index.php/Gravity:_Analog_TDS_Sensor_/_Meter_For_Arduino_SKU:_SEN0244
// Documentation de la sonde TDS DF-Robot

TdsSensor::TdsSensor(byte userPin) {
	_pin = userPin;
	_gravityTds.setPin(_pin);
	_gravityTds.setAref(5.0); //reference voltage on ADC, default 5.0V on Arduino UNO
	_gravityTds.setAdcRange(1024);  //1024 for 10bit ADC;4096 for 12bit ADC
	_gravityTds.begin();  //initialization
	setUnitReadValue("ppm");
}

TdsSensor::TdsSensor(byte userPin, uint8_t idDz, String desc) {
	this(userPin);
	_desc = desc;
	_dzIdx = idDz;
}


double TdsSensor::read() {
	float temperature = 25.0;
	_gravityTds.setTemperature(temperature); // set the temperature and execute temperature compensation
	_gravityTds.update();  //sample and calculate
	return _gravityTds.getTdsValue(); ;
}


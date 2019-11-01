#include "TempSensor.h"
  

TempSensor::TempSensor(DallasTemperature * dallas, DeviceAddress * address){
    _dallas = dallas;
    _sensorAddress = address;
    _unitReadValue = "°C";
}

TempSensor::TempSensor(DallasTemperature * dallas, DeviceAddress * address, uint8_t idDz, String desc){
    this->_dallas = dallas;
    this->_sensorAddress = address;
    this->_unitReadValue = "°C";
    this->_desc = desc;
    this->_dzIdx = idDz;
}

void TempSensor::refreshSensor(){
	this->_currentValue = _dallas->getTempC(*_sensorAddress);
}

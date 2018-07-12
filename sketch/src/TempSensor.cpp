#include "TempSensor.h"
  

TempSensor::TempSensor(DallasTemperature * dallas, DeviceAddress * address){
    _dallas = dallas;
    _sensorAddress = address;
    _unitReadValue = "°C";
}

TempSensor::TempSensor(DallasTemperature * dallas, DeviceAddress * address, uint8_t idDz, String desc){
    this(dallas, address);
    _desc = desc;
    _dzIdx = idDz;
}
  
double TempSensor::read(){
  double tempC = _dallas->getTempC(*_sensorAddress);
  if (tempC == -127.00) 
  {
    Serial.println("Error getting temperature  ");
  } 
  else
  {
    Serial.print("Temp C: ");
    Serial.println(tempC);
  }
   return tempC;
}


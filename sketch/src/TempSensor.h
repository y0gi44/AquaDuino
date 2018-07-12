#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include "Sensor.h"
#include <OneWire.h>
#include <DallasTemperature.h>


class TempSensor : public Sensor
{
  public:
  TempSensor(DallasTemperature * dallas, DeviceAddress * address);
  TempSensor(DallasTemperature * dallas, DeviceAddress * address, uint8_t dzId, String desc);

    
  double read();
    
  private:
    DallasTemperature * _dallas;   
    DeviceAddress * _sensorAddress;
};

#endif




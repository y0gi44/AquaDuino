#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include "Sensor.h"
#include <OneWire.h>
#include <DallasTemperature.h>


class TempSensor : public Sensor {
private:
    DallasTemperature * _dallas;
    DeviceAddress * _sensorAddress;
    double _currentValue;

public:
  TempSensor(DallasTemperature * dallas, DeviceAddress * address);
  TempSensor(DallasTemperature * dallas, DeviceAddress * address, uint8_t dzId, String desc);
  ~TempSensor() {};

  void refreshSensor();

  double read();

  void setPower(bool b){};

};

#endif




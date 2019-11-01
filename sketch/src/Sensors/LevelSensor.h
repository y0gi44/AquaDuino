#ifndef LevelSensor_h
#define LevelSensor_h

#include "Arduino.h"
#include "Sensor.h"
#define MAX_PIN 15

class LevelSensor : public Sensor {

  public:
    LevelSensor(int pinEcho, int pinTrigger);
    void init();

	void refreshSensor();
    
  private:
    int _pinEcho;   // pushbutton connected to digital pin 7
    int _pinTrigger;
    int _nbMillimeterMax;
};

#endif

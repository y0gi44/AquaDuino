#ifndef LevelSensor_h
#define LevelSensor_h

#include "Arduino.h"
#define MAX_PIN 15

class LevelSensor
{
  public:
    LevelSensor(int pinEcho, int pinTrigger, int nbMillimeterMax);
    void powerOff();
    void powerUp();
    void init();
    int getRawValue();
    double getPctValue();
    
  private:
    int _pinEcho;   // pushbutton connected to digital pin 7
    int _pinTrigger;
    int _nbMillimeterMax;
};

#endif

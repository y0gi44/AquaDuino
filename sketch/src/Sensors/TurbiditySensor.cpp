#include "TurbiditySensor.h"

// https://www.dfrobot.com/wiki/index.php/Turbidity_sensor_SKU:_SEN0189
// Documentation de la sonde de turbidité DF-Robot

TurbiditySensor::TurbiditySensor(byte userPin){
  this->_pin = userPin;
  this->_unitReadValue = "NTU";
}

void TurbiditySensor::refreshSensor(){
  // récupération du Voltage
  double Turbidityval=analogRead(_pin)/1024.0*5.0;
  // calcul de la turbité
  this->_currentValue = -1120.4*(Turbidityval*Turbidityval) +5742.3*Turbidityval -4352.9;
}

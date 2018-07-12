#include "TurbiditySensor.h"

// https://www.dfrobot.com/wiki/index.php/Turbidity_sensor_SKU:_SEN0189
// Documentation de la sonde de turbidité DF-Robot

TurbiditySensor::TurbiditySensor(byte userPin){
  _pin = userPin;
  _unitReadValue = "NTU";
}

TurbiditySensor::TurbiditySensor(byte userPin, uint8_t idDz, String desc){
  this(userPin);
  _desc = desc;
  _dzIdx = idDz;
}

double TurbiditySensor::read(){
  // récupération du Voltage
  double Turbidityval=analogRead(_pin)/1024.0*5.0;
  // calcul de la turbité
  Turbidityval = -1120.4*(Turbidityval*Turbidityval) +5742.3*Turbidityval -4352.9;
  return Turbidityval;
}


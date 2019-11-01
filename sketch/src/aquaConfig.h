#ifndef AquaConfig_h
#define AquaConfig_h

#include "Sensors/PhSensor.h"
#include "Sensors/TempSensor.h"
#include "Sensors/TurbiditySensor.h"
#include "Sensors/TdsSensor.h"
#include "Sensors/LevelSensor.h"

#include "Actuator/Co2DosingPump.h"


#include <OneWire.h>
#include <DallasTemperature.h>
#include "Actuator/FoodDistributor.h"


/** address Mac de l'interface reseau**/
static byte mymac[] = { 0x80,0x6A,0x69,0x2C,0x30,0x96 };

/** Config domoticz   **/
IPAddress domoticzHost(192,168,1,120);
const int domoticzPort = 8080;

/** Config des Sondes de température et du bus One-Wire   **/
#define ONE_WIRE_BUS 30
#define TEMPERATURE_PRECISION 12
OneWire ds(ONE_WIRE_BUS);  // on pin 30 (a 4.7K resistor is necessary)
DallasTemperature sensors(&ds);

// Définition des adresses des sondes One Wire
DeviceAddress ProbeT1 = { 0x28, 0xFF, 0x9C, 0xD6, 0x92, 0x16, 0x04, 0x96 }; 
DeviceAddress ProbeT2 = { 0x28, 0xFF, 0x69, 0x9D, 0x93, 0x16, 0x05, 0x63 };

TempSensor Temp1(&sensors, &ProbeT1);
TempSensor Temp2(&sensors, &ProbeT2);


/** Sonde de turbidité **/
#define TURBIDITY_PIN A15
TurbiditySensor Turbidity1(TURBIDITY_PIN);

/** Sonde de PH **/
#define PH_PIN A14
PhSensor Ph1(PH_PIN);

/** Sonde TDS **/
#define TDS_PIN A9
TdsSensor tds(TDS_PIN);

/** Sonde de niveau Ultrason **/
#define US_TRIGGER_PIN 31
#define US_ECHO_PIN  32

LevelSensor level(US_ECHO_PIN, US_TRIGGER_PIN);


#endif

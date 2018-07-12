#ifndef TURBIDITYSENSOR_H
#define TURBIDITYSENSOR_H

#include "Sensor.h"
#include <EEPROM.h>
#include "GravityTDS.h"

class TdsSensor : public Sensor {
    public:
	TdsSensor( byte userPin ) ;
	TdsSensor( byte userPin, uint8_t idDz, String desc ) ;

        //read function must be implemented
        virtual double read(); 
        
    private:
        byte _pin;
        GravityTDS _gravityTds;

};


#endif

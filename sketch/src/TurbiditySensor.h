#ifndef TURBIDITYSENSOR_H
#define TURBIDITYSENSOR_H

#include "Sensor.h"

class TurbiditySensor : public Sensor {
    public:
        TurbiditySensor( byte userPin ) ;
        TurbiditySensor( byte userPin, uint8_t idDz, String desc ) ;
        //read function must be implemented
        virtual double read(); 
        
    private:
        byte _pin;
       
};


#endif

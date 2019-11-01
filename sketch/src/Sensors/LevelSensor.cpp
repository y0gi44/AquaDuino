#include "LevelSensor.h"

/* Constantes pour les broches */
//const byte TRIGGER_PIN = 3; // Broche TRIGGER
//const byte ECHO_PIN = 2;    // Broche ECHO
 
/* Constantes pour le timeout */
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s

/* Vitesse du son dans l'air en mm/us */
const float SOUND_SPEED = 340.0 / 1000;



LevelSensor::LevelSensor(int pinEcho, int pinTrigger){
  _pinEcho = pinEcho,
  _pinTrigger = pinTrigger;
  this->_unitReadValue = "mm";
}

void LevelSensor::init(){
    /* Initialise les broches */
  pinMode(this->_pinTrigger, OUTPUT);
  digitalWrite(this->_pinTrigger, LOW); // La broche TRIGGER doit être à LOW au repos
  pinMode(this->_pinEcho, INPUT);
}


void LevelSensor::refreshSensor(){
  int lvl = 0;

/* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs sur la broche TRIGGER */
  digitalWrite(this->_pinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(this->_pinTrigger, LOW);
  
  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) */
  long measure = pulseIn(this->_pinEcho, HIGH, MEASURE_TIMEOUT);
   
  /* 3. Calcul la distance à partir du temps mesuré */
  this->_currentValue = measure / 2.0 * SOUND_SPEED;
  
}


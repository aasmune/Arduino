#ifndef SonicSensor_H
#define SonicSensor_H

#include "Arduino.h"



class SonicSensor
{
private:
  int triggerPin, echoPin;
  const int lowWait = 3;
  const int highWait = 12;

  const unsigned long lowerTreshhold = 0;
  const unsigned long upperTreshhold = 400;


public:

  SonicSensor(int triggerPin, int echoPin);
  bool measure(unsigned long &distance);
  void changeTriggerPin(int pin);
  void changeEchoPin(int pin);
  void changePins(int triggerPin, int echoPin);


};

#endif

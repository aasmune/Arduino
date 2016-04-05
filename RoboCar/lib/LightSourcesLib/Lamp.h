#ifndef Lamp_h
#define Lamp_h

#include "Arduino.h"

class Lamp
{
public:
Lamp(int pin);
Lamp();
void changePin(int pin);
void blink(int duration, int count);
void burst(int numberOfBursts, int numberOfBlinks, int blinkDuration);

private:
  int pin;
};

#endif

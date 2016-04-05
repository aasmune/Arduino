#ifndef Car_H
#define Car_H

/*
Car.h - Libary class for a vehicle with 4 instances of Motor
Created by Lars van der Lee, 17.03.16
Released into the public domain
*/

#include "Arduino.h"
#include "Motor.h"

enum carState {forwards, backwards, stop, left, right};

class Car
{
private:
  Motor frontL;
  Motor frontR;
  Motor backL;
  Motor backR;
  carState currentState;
public:
  Car(Motor frontLeft, Motor frontRight, Motor backLeft, Motor backRight);
  void setDirection(carState state);
};
#endif

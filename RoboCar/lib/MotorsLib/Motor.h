#ifndef Motor_H
#define Motor_H

/*
Motor.cpp - Libary for controlling a DC motor using an arduino.
Created by Lars van der Lee, 14.03.16
Released into the public domain
*/

#include "Arduino.h"
enum motorState { FORWARDS, BACKWARDS, STOP };

class Motor
{
public:
	Motor(){};
	Motor(int positiveMotorPin, int negativeMotorPin);
	void setMotorState(motorState state);
private:
	int positiveMotorPin;
	int negativeMotorPin;
};

#endif

#include "Motor.h"

/*
	Motor.cpp - Libary for controlling a DC motor using an arduino.
	Created by Lars van der Lee, 14.03.16
	Released into the public domain
*/

//Declare the ports that the positive and negative poles of the motor are connected too
Motor::Motor(int positiveMotorPin, int negativeMotorPin)
{
	this->positiveMotorPin = positiveMotorPin;
	this->negativeMotorPin = negativeMotorPin;
	pinMode(this->positiveMotorPin, OUTPUT);
	pinMode(this->negativeMotorPin, OUTPUT);
}

//Set the direction for the motor
void Motor::setMotorState(motorState state)
{
	switch (state)
	{
	case motorState::FORWARDS:
		digitalWrite(positiveMotorPin, HIGH);
		digitalWrite(negativeMotorPin, LOW);
		break;

	case motorState::BACKWARDS:
		digitalWrite(positiveMotorPin, LOW);
		digitalWrite(negativeMotorPin, HIGH);
		break;

	case motorState::STOP:
		digitalWrite(positiveMotorPin, LOW);
		digitalWrite(negativeMotorPin, LOW);
		break;
	}
}

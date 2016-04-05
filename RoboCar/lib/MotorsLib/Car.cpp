#include "Arduino.h"
#include "Motor.h"
#include "Car.h"

/*
Car.cpp - Libary class for a vehicle with 4 instances of Motor
Created by Lars van der Lee, 17.03.16
Released into the public domain
*/

Car::Car(Motor frontLeft, Motor frontRight, Motor backLeft, Motor backRight)
{
  frontL = frontLeft;
  frontR = frontRight;
  backL = backLeft;
  backR = backRight;
}

void Car::setDirection(carState state)
{
  this->currentState = state;

  switch(state)
  {
    case carState::forwards:
    {
      frontL.setMotorState(motorState::FORWARDS);
      frontR.setMotorState(motorState::FORWARDS);
      backL.setMotorState(motorState::FORWARDS);
      backR.setMotorState(motorState::FORWARDS);
      break;
    }
    case carState::backwards:
    {
      frontL.setMotorState(motorState::BACKWARDS);
      frontR.setMotorState(motorState::BACKWARDS);
      backL.setMotorState(motorState::BACKWARDS);
      backR.setMotorState(motorState::BACKWARDS);
      break;
    }
    case carState::left:
    {
      frontL.setMotorState(motorState::STOP);
      frontR.setMotorState(motorState::FORWARDS);
      backL.setMotorState(motorState::STOP);
      backR.setMotorState(motorState::FORWARDS);
      break;
    }
    case carState::right:
    {
      frontL.setMotorState(motorState::FORWARDS);
      frontR.setMotorState(motorState::STOP);
      backL.setMotorState(motorState::FORWARDS);
      backR.setMotorState(motorState::STOP);
      break;
    }
    case carState::stop:
    {
      frontL.setMotorState(motorState::STOP);
      frontR.setMotorState(motorState::STOP);
      backL.setMotorState(motorState::STOP);
      backR.setMotorState(motorState::STOP);
      break;
    }
  }
}

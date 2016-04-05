#include "SonicSensor.h"


unsigned long microsecondsToCentimeters(unsigned long microseconds)
{
  return microseconds / (29 * 2);
}


SonicSensor::SonicSensor(int triggerPin, int echoPin) : triggerPin(triggerPin), echoPin(echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);

  pinMode(echoPin, INPUT);

}

void SonicSensor::changeEchoPin(int pin)
{
  this->echoPin = pin;

  pinMode(this->echoPin, INPUT);
}

void SonicSensor::changeTriggerPin(int pin)
{
  this->triggerPin = pin;
  pinMode(this->triggerPin, OUTPUT);
}

void SonicSensor::changePins(int triggerPin, int echoPin)
{
  changeEchoPin(echoPin);
  changeTriggerPin(triggerPin);
}

//The method can bloch the thread for a long time while waiting for a response
bool SonicSensor::measure(unsigned long &distance)
{

  //code for activating the sensor:
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(3);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(12);
  digitalWrite(triggerPin, LOW);

//code for getting response:
  unsigned long duration = pulseIn(echoPin, HIGH);
  distance = microsecondsToCentimeters(duration);


  bool successful = false;
 
  if(distance > lowerTreshhold && distance < upperTreshhold)
  {
    successful = true;
  }

  return successful;

}

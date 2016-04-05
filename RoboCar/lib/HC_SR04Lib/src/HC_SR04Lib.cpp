#include "HC_SR04Lib.h"

HC_SR04::HC_SR04(uint8_t trigger_pin, uint8_t echo_pin, unsigned int max_cm_distance): NewPing(trigger_pin, echo_pin, max_cm_distance), echoPin(echo_pin), triggerPin(trigger_pin)
      {
        //EMPTY
      }

unsigned long HC_SR04::measure()
{

  unsigned int uS = this->ping();
  pinMode(this->echoPin, OUTPUT);
  digitalWrite(echoPin, LOW);
  pinMode(echoPin, INPUT);

  unsigned long newDistanceMeasured = convert_cm(uS);

  if (newDistanceMeasured > 0 && newDistanceMeasured < 400)
  {
    this->lastDistanceMeasured = newDistanceMeasured;
  }
  return lastDistanceMeasured;
}

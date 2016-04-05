#include "Arduino.h"
#include "NewPing.h"

class HC_SR04 : NewPing
{
public:
  HC_SR04(uint8_t trigger_pin, uint8_t echo_pin, unsigned int max_cm_distance = MAX_SENSOR_DISTANCE);

  unsigned long measure();

private:
  uint8_t echoPin;
  uint8_t triggerPin;
  unsigned long lastDistanceMeasured;
};

#include "Arduino.h"
#include <HC_SR04Lib.h>

HC_SR04 test(12,11);

void setup()
{
  Serial.begin(115200);

}

void loop()
{

  Serial.println(test.measure());
}

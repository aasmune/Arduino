#include "Lamp.h"

/*
    Lamp.h - Klasse for en lampe koblet til en Arduino
*/

Lamp::Lamp()
{

}

//Sett pin til den utgangen på arduinoen som lampen blir styrt fra
Lamp::Lamp(int pin):pin(pin)
{
  pinMode(pin, OUTPUT);
}

//Bytt utgangen på arduinoen som lampen blir styrt fra
void Lamp::changePin(int pin)
{
  digitalWrite(this->pin, LOW);
  this->pin = pin;
  pinMode(pin, OUTPUT);
}

//Blinker lampen count ganger, der hvert blink varer duration millisekunder
void Lamp::blink(int duration, int count)
{
  for(int i = 0; i < count; i++)
  {
    digitalWrite(pin, HIGH);
    delay(duration);
    digitalWrite(pin, LOW);
    delay(duration);
  }
}

//Har numberOfBursts bursts med numberOfBlinks blinker som varer blinkDuration millisekunder
void Lamp::burst(int numberOfBursts, int numberOfBlinks, int blinkDuration)
{

    for(int i = 0; i < numberOfBursts; i++)
    {
      blink(blinkDuration,numberOfBlinks);
      delay(numberOfBlinks*blinkDuration*2);
    }

}

//Har bare kommentert ut innholdet her for å teste den nye SuperSonic klassen - Åsmund
//Er bare å fjerne kommenteringen

//#include "Arduino.h"

// // Includsene med <> melder feil, men de fungerer. Restart platformIO så funker
// // de
// #include <Motor.h>
// #include <Car.h>
//
// Motor motor1(9, 10);
// Motor motor2(11, 12);
// Motor motor3(13, 14);
// Motor motor4(15, 16);
//
// Car bil(motor1, motor2, motor3, motor4);
//
// void setup()
// {
//   bil.setDirection(carState::stop);
// }
//
// void loop()
// {
//   bil.setDirection(carState::left);
//   delay(10000);
//   bil.setDirection(carState::right);
//   delay(10000);
// }
//
// #include <SonicSensor.h>
//
// SonicSensor sensor(12, 11);
//
// void setup()
// {
//   Serial.begin(115200);
// }
//
// void loop()
// {
//   unsigned long distance;
//
//   sensor.measure(distance);
//   Serial.print("Ping: ");
//   Serial.println(distance);
// }

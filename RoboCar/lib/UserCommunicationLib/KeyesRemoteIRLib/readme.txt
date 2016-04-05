VIKTIG INFORMASJON ANGAAENDE BIBLIOTEKET

Dette er et bibliotek for Keyes-fjernkontrollen til Arduino for brukerkommunikasjon over IR.
Biblioteket benytter seg av libraryet IRremote, https://github.com/z3t0/Arduino-IRremote.

Naar man skal bruke KeyesRemoteIRLib vil ikke programmet kompillere, og gir feilmeldingen:
.../IRremoteTools.cpp:5: error: 'TKD2' was not declared in this scope.
Dette er paa grunn av en feil i biblioteket RobotIRremote som fulgte med Arduino 1.5.8. 
For aa loese problemet
maa man slette mappen RobotIRremote fra C:\Program Files (x86)\Arduino\libraries

Man maa saa laste ned biblioteket IRremote fra
https://github.com/z3t0/Arduino-IRremote, og foelge instruksjonene som staar paa siden
https://github.com/z3t0/Arduino-IRremote/blob/master/README.md.

Dersom man bruker PlatformIO som IDE maa man i tillegg slette RobotIRremote fra
C:\Users\USERNAME\.platformio\packages\framework-arduinoavr\libraries
og legge til IRremote som forklart ovenfor paa denne filbanen i tillegg.



//KeyesRemoteIRLib.h

#ifndef _KEYESREMOTEIRLIB_h
#define _KEYESREMOTEIRLIB_h



#include <IRremote.h>
#include <UserCommunicationLib.h>

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class KeyesRemoteIR : UserCommunication
{
public:
	KeyesRemoteIR(unsigned int echoPin);


	//UserInput getLastInputFromUser();

	//Recives and return a new user input
	//Use this when you want a new input
	UserInput reciveNewUserInput();

private:
	bool started;
	IRrecv irrecv;
	decode_results results;


	bool receivedNewIRsignal();

};





#endif

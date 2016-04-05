// UserCommunication.h

#ifndef _USERCOMMUNICATIONLIB_h
#define _USERCOMMUNICATIONLIB_h



enum UserInput {
	FORWARD,
	REVERSE,
	RIGHT,
	LEFT,
	START,
	STOP
};


#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


class UserCommunication
{
protected:
	unsigned int echoPin;
	//bool started;
	UserInput lastInput;

 public:

	 UserCommunication(unsigned int echoPin);
	 UserCommunication();
	 unsigned int getEchoPin() const;
	 void changeEchoPin(unsigned int newEchoPin);

	 //Returns the last recived user input
 	//does NOT recive a new input
 	//Use this when you want the last input
 	//but doesn't want to recive a new one
	 UserInput getLastInputFromUser() const;

	virtual UserInput reciveNewUserInput() = 0;
};

#endif

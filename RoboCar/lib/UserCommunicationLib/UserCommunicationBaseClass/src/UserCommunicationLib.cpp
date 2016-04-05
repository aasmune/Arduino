#include "UserCommunicationLib.h"

namespace
{
	enum RawUserInput {
		FORWARD = 0xFF629D,
		REVERSE = 0xFFA857,
		RIGHT = 0xFFC23D,
		LEFT = 0xFF22DD,
		START_STOP = 0xFF02FD,
		REPEATED = 0xFFFFFF
	};
}

UserCommunication::UserCommunication(unsigned int echoPin) : echoPin(0), lastInput(UserInput::STOP)
{
	this->echoPin = echoPin;
	pinMode(echoPin, INPUT);
}
/*
UserCommunication::UserCommunication():
{
	//EMPTY
}
*/

unsigned int UserCommunication::getEchoPin() const
{
	return (this->echoPin);
}

void UserCommunication::changeEchoPin(unsigned int newEchoPin)
{
	this->echoPin = newEchoPin;
	pinMode(newEchoPin, INPUT);
}

UserInput UserCommunication::getLastInputFromUser()  const
{
	return this->lastInput;
}

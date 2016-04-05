#include "KeyesRemoteIRLib.h"

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
/*
KeyesRemoteIR::KeyesRemoteIR() : UserCommunication(), started(false), irrecv(0)
{


}
*/
KeyesRemoteIR::KeyesRemoteIR(unsigned int echoPin) : UserCommunication(echoPin), started(false), irrecv(echoPin)
{
  pinMode(echoPin, INPUT);
	irrecv.enableIRIn();
}

/*
UserInput KeyesRemoteIR::getLastInputFromUser()
{
  return this->lastInput;
}
*/

UserInput KeyesRemoteIR::reciveNewUserInput()
{
  if (receivedNewIRsignal())
	{
		switch (results.value)
		{

		case static_cast<unsigned long>(RawUserInput::FORWARD):
		{
			this->lastInput = UserInput::FORWARD;
			break;
		}

		case static_cast<unsigned long>(RawUserInput::REVERSE) :
		{
			this->lastInput = UserInput::REVERSE;
			break;
		}

		case static_cast<unsigned long>(RawUserInput::RIGHT) :
		{
			this->lastInput = UserInput::RIGHT;
			break;
		}

		case static_cast<unsigned long>(RawUserInput::LEFT) :
		{
			this->lastInput = UserInput::LEFT;
			break;
		}

		case static_cast<unsigned long>(RawUserInput::START_STOP) :
		{
			if (!started)
			{
				started = true;
				this->lastInput = UserInput::START;
			}
			else
			{
				started = false;
				this->lastInput = UserInput::STOP;
			}
			break;
		}

		default:
			break;
		}

		irrecv.resume();
	}

	return (getLastInputFromUser());
}

bool KeyesRemoteIR::receivedNewIRsignal()
{
	return (irrecv.decode(&results));
}

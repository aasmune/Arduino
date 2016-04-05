/* YourDuino.com Example Software Sketch
 Brick Starter Set IR Remote Kit Test
http://yourduino.com/sunshop2/index.php?l=product_detail&p=364
 based on code by Ken Shirriff - http://arcfn.com
 Get Library at: https://github.com/shirriff/Arduino-IRremote
 Unzip folder into Libraries. RENAME folder IRremote
 terry@yourduino.com */

/*-----( Import needed libraries )-----*/

#include "IRremote.h"

/*-----( Declare Constants )-----*/
int receiver = 11; // pin 1 of IR receiver to Arduino digital pin 11

/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);           // create instance of 'irrecv'
decode_results results;            // create instance of 'decode_results'
/*-----( Declare Variables )-----*/


void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);
  Serial.println("YourDuino IR Receiver Button Decode Test");
  Serial.println("Questions: terry@yourduino.com");  
  irrecv.enableIRIn(); // Start the receiver

}/*--(end setup )---*/

enum UserInput {forward, reverse, turnRight, turnLeft, start, stopp, none};

UserInput getUserInputAndCalculateAction();



enum UserInput { FORWARD, REVERSE, RIGHT, LEFT, START, STOPP, NONE };


UserInput getUserInputAndCalculateAction()
{
  //static decode_results lastRecived;
  static bool STARTed = false;
  static bool STOPPed = true;
  UserInput actionToReturn = NONE;
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    //lastRecived = results.value;
    switch (results.value)
    {
      case 0xFF629D:
      {
        actionToReturn = UserInput::FORWARD;
        break;
      }
      case 0xFF22DD:
      {
        actionToReturn = UserInput::LEFT;
        break;
      }

    
      case 0xFF02FD:
      {
        actionToReturn = UserInput::START;
        break;

      }   

      case 0xFFC23D:
      {
        actionToReturn = UserInput::RIGHT;
        break;
      }

      case 0xFFA857:
      {
        actionToReturn = UserInput::REVERSE;
        break;
      }
      /*
      case 0xFFFFFFFF:
      {
        actionToReturn = lastRecived;
        break;
      }
      */
      default:
      {
        actionToReturn = UserInput::NONE;
      }
    
    }// End switch

    irrecv.resume(); // receive the next value

  }

  return actionToReturn;
}

void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  switch (getUserInputAndCalculateAction())
  {
    case FORWARD:
    {
      Serial.println("FORWARD");
      break;
    }

    case REVERSE:
    {
      Serial.println("REVERSE");
      break;
    }

    case LEFT:
    {
      Serial.println("LEFT");
      break;
    }

    case RIGHT:
    {
      Serial.println("RIGHT");
      break;
    }
  }
}/* --(end main loop )-- */


//Trigger and echo pin definition for Distancereader1, Left:
#define ECP1 23
#define TRP1 22

//Trigger and echo pin definition for Distancereader2, Middle:
#define ECP2 25
#define TRP2 24

//Trigger and echo pin definition for Distancereader3, Right:
#define ECP3 27
#define TRP3 26

#define MLFpos 32
#define MLFneg 31

#define MRFpos 37
#define MRFneg 36

#define MLBpos 41
#define MLBneg 40

#define MRBpos 47
#define MRBneg 46


//Must ble implemented
#define FORWARDTRESHHOLD 10
#define SIDETRESHHOLD 10

unsigned long prevMillis;

enum RobotState {Driving, Paused, Jammed};
enum Direction {FORWARDS, RIGHT, LEFT, BACKWARDS, STOP};

RobotState currentState;
Direction currentDirection;




Direction decideDirection()
{
  unsigned long fDist = readDistanceSensor(TRP2, ECP2);

  Serial.print("F: ");
  Serial.println(fDist);

  if (readDistanceSensor(TRP2, ECP2) > 10)
  {
    return Direction::FORWARDS;
  }
  else
  {
    unsigned long rDist = readDistanceSensor(TRP3, ECP3);
    Serial.print("R: ");
    Serial.println(rDist);

    unsigned long lDist = readDistanceSensor(TRP1, ECP1);
    Serial.print("L: ");
    Serial.println(lDist);

    if (rDist > 10 && lDist > 10)
    {
      if (rDist > lDist)
      {
        return Direction::RIGHT;
      }
      else
      {
        return Direction::LEFT;
      }
    }
    else
    {
      return Direction::BACKWARDS;
    }
  }
}


void readTheSensors()
{
  printDistanceSensor(TRP1, ECP1);
  delayMicroseconds(15);
  printDistanceSensor(TRP2, ECP2);
  delayMicroseconds(15);
  printDistanceSensor(TRP3, ECP3);
}

void printDistanceSensor(unsigned int triggerPin, unsigned int echoPin)
{
  unsigned long dist = readDistanceSensor(triggerPin, echoPin);
  Serial.print("Distance(");
  Serial.print(triggerPin);
  Serial.print(" , ");
  Serial.print(echoPin);
  Serial.print("): ");
  Serial.println(dist);

}

unsigned long readDistanceSensor(unsigned int triggerPin, unsigned int echoPin)
{
  //Code for triggering the sensor:
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(3);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(12);
  digitalWrite(triggerPin, LOW);

  //Code for getting the ultrasonic response:
  unsigned long duration = pulseIn(echoPin, HIGH);
  unsigned long dist = microsecondsToCentimeters(duration);
  return dist;

}

unsigned long microsecondsToCentimeters(unsigned long microseconds)
{
  return microseconds / (29 * 2);
}



void setMotorDirection(int positiveMotorPin, int negativeMotorPin, Direction state)
{
  switch (state)
  {
    case Direction::FORWARDS:
      digitalWrite(positiveMotorPin, HIGH);
      digitalWrite(negativeMotorPin, LOW);
      break;

    case Direction::BACKWARDS:
      digitalWrite(positiveMotorPin, LOW);
      digitalWrite(negativeMotorPin, HIGH);
      break;
    default:
      digitalWrite(positiveMotorPin, LOW);
      digitalWrite(negativeMotorPin, LOW);
      break;
  }
}

void driveMotors(Direction dir)
{
  switch (dir)
  {
    case Direction::FORWARDS:
      setMotorDirection(MLFpos, MLFneg, Direction::FORWARDS);
      setMotorDirection(MRFpos, MRFneg, Direction::FORWARDS);
      setMotorDirection(MLBpos, MLBneg, Direction::FORWARDS);
      setMotorDirection(MRBpos, MRBneg, Direction::FORWARDS);
      break;
    case Direction::RIGHT:
      setMotorDirection(MLFpos, MLFneg, Direction::FORWARDS);
      setMotorDirection(MRFpos, MRFneg, Direction::BACKWARDS);
      setMotorDirection(MLBpos, MLBneg, Direction::FORWARDS);
      setMotorDirection(MRBpos, MRBneg, Direction::BACKWARDS);
      break;
    case Direction::LEFT:
      setMotorDirection(MLFpos, MLFneg, Direction::BACKWARDS);
      setMotorDirection(MRFpos, MRFneg, Direction::FORWARDS);
      setMotorDirection(MLBpos, MLBneg, Direction::BACKWARDS);
      setMotorDirection(MRBpos, MRBneg, Direction::FORWARDS);
      break;
    case Direction::BACKWARDS:
      setMotorDirection(MLFpos, MLFneg, Direction::BACKWARDS);
      setMotorDirection(MRFpos, MRFneg, Direction::BACKWARDS);
      setMotorDirection(MLBpos, MLBneg, Direction::BACKWARDS);
      setMotorDirection(MRBpos, MRBneg, Direction::BACKWARDS);
      break;
    default:
      setMotorDirection(MLFpos, MLFneg, Direction::STOP);
      setMotorDirection(MRFpos, MRFneg, Direction::STOP);
      setMotorDirection(MLBpos, MLBneg, Direction::STOP);
      setMotorDirection(MRBpos, MRBneg, Direction::STOP);

  }
}




void setup() {
  currentState = RobotState::Driving;
  currentDirection = Direction::FORWARDS;

  //Millis for calculating deltatime
  prevMillis = millis();

  pinMode(ECP1, INPUT);
  pinMode(TRP1, OUTPUT);

  pinMode(ECP2, INPUT);
  pinMode(TRP2, OUTPUT);

  pinMode(ECP3, INPUT);
  pinMode(TRP3, OUTPUT);

  Serial.begin(9600);

}

void loop() {


  //Code for getting deltatime:
  unsigned long currentMillis = millis();
  unsigned long delta = currentMillis - prevMillis;
  prevMillis = currentMillis;

  Serial.println(delta);

  switch (currentState)
  {
    case RobotState::Paused:
      driveMotors(Direction::STOP);
      break;

    case RobotState::Driving:

      Direction dir = decideDirection();
      Serial.print("Direction: ");
      Serial.println(dir);

      switch (dir)
      {
        case Direction::BACKWARDS:
          driveMotors(Direction::BACKWARDS);
          delay(1000);
          driveMotors(Direction::RIGHT);
          delay(1000);
          break;
        default:
          driveMotors(dir);
          break;
      }

      break;

      //Make dangerous noise here!
  }


}


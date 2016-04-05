
#include<Servo.h>

//Trigger and echo pin definition for Distancereader1:
#define ECP1 2
#define TRP1 7

//Trigger and echo pin definition for Distancereader2:
#define ECP2 3
#define TRP2 6

//Trigger and echo pin definition for Distancereader3:
#define ECP3 4
#define TRP3 5

//ServoPin:

#define ServoP 8

#define FORWARDTRESHHOLD 10
#define SIDETRESHHOLD 10


enum Direction {FORWARD, RIGHT, LEFT, BACK};

unsigned long prevMillis;
Servo distServo;
unsigned int servoPos;

void setup() {
  // put your setup code here, to run once:
  prevMillis = millis();
  Serial.begin(9600);

  pinMode(ECP1, INPUT);
  pinMode(TRP1, OUTPUT);

  pinMode(ECP2, INPUT);
  pinMode(TRP2, OUTPUT);

  pinMode(ECP3, INPUT);
  pinMode(TRP3, OUTPUT);

  distServo.attach(ServoP);
  servoPos = 0;
}


void loop() {

  //Code for getting deltatime:
  unsigned long currentMillis = millis();
  unsigned long delta = currentMillis - prevMillis;
  prevMillis = currentMillis;
  //Serial.println(delta);

  //Serial.println("JALLA");


  //Serial.println(decideDirection());
  //readTheSensors();

setServoPosition(distServo);

  delay(1000);

}

void setServoPosition(Servo servo)
{
  servoPos += 18;

  servoPos %= 180;

  servo.write(servoPos);

  
}

Direction decideDirection()
{
  unsigned long fDist = readDistanceSensor(TRP2, ECP2);

  Serial.print("F: ");
  Serial.println(fDist);

  if (readDistanceSensor(TRP2, ECP2) > 10)
  {
    return Direction::FORWARD;
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
      return Direction::BACK;
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



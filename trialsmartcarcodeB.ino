#include <Adafruit_MotorShield.h>

AF_DCMotor  rightack(1);
AF_DCMotor  rightFront(2);
AF_DCMotor  leftFront(3);
AF_DCMotor  leftBack(4);

byte motorSpeed = 55; 
int motorOffset = 10; 
int turnSpeed = 50;

int obstacle = 6;
int obstacle_sense;

void setup() {
  // put your setup code here, to run once:
pinMode(obstacle, INPUT);  
Serial.begin(9600);
rightBack.setSpeed(motorSpeed);
rightFront.setSpeed(motorSpeed);
leftFront.setSpeed(motorSpeed);
leftBck.setSpeed(motorSpeed);
rightBack.run(RELEASE);
rightFront.run(RELEASE);
leftBack.run(RELEASE);
leftFront.run(RELEASE);
}

void loop() {
  // put your main code here, to run repeatedly:
obstacle_sense = digitalRead(obstacle);

if (obstacle_sense = HIGH)
{
  rightBack.setSpeed(motorSpeed);
  rightFront.setSpeed(motorSpeed);
  leftFront.setSpeed(motorSpeed);
  leftBck.setSpeed(motorSpeed);
  rightBack.run(FORWARD);
  rightFront.run(FORWARD);
  leftBack.run(RELEASE);
  leftFront.run(RELEASE);
  }
else if (obstacle_sense = LOW)
{
  rightBack.setSpeed(motorSpeed);
  rightFront.setSpeed(motorSpeed);
  leftFront.setSpeed(motorSpeed);
  leftBck.setSpeed(motorSpeed);
  rightBack.run(FORWARD);
  rightFront.run(FORWARD);
  leftBack.run(FORWARD);
  leftFront.run(FORWARD);
  }
}

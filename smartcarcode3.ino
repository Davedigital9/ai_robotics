#include <Adafruit_MotorShield.h>

AF_DCMotor  rightack(1);
AF_DCMotor  rightFront(2);
AF_DCMotor  leftFront(3);
AF_DCMotor  leftBack(4);

byte motorSpeed = 55; 
int motorOffset = 10; 
int turnSpeed = 50;    

void setup() {
  // put your setup code here, to run once:
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
//to move right

void moveForward()
{
  //to move forward
  rightBack.run(FORWARD);
  rightFront.run(FORWARD);
  leftFront.run(FORWARD);
  leftBack.run(FORWARD);
}








}

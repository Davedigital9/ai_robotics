#include <Adafruit_MotorShield.h>

AF_DCMotor = rightack(1);
AF_DCMotor = rightFront(2);
AF_DCMotor = leftFront(3);
AF_DCMotor = leftBack(4);

byte motorSpeed = 60; 
int motorOffset = 25; 
int turnSpeed = 45;    

int trg = 8;
int ech = 9;
float distance;

void setup() {
  // put your setup code here, to run once:

pinMode(trg, OUTPUT);
pinMode(ech, INPUT);
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
rightBack.setSpeed(motorSpeed);
rightFront.setSpeed(motorSpeed);
leftFront.setSpeed(motorSpeed);
leftBck.setSpeed(motorSpeed);

rightBack.run(FORWARD);
rightFront.run(FORWARD);
leftBack.run(FORWARD);
leftFront.run(FORWARD);

digitalWrite(trg, LOW);
delayMicroseconds (2);
digitalWrite(trg, HIGH);
delayMicroseconds (10);
digitalWrite(trg, LOW);
delayMicroseconds (2);

distance = pulseIn(ech, HIGH) / 58.8;
Serial.println(distance);

if (distance <= 20)
{
  rightBack.setSpeed(motorOffset);
  rightFront.setSpeed(motorOffset);
  leftFront.setSpeed(motorOffset);
  leftBck.setSpeed(motorOffset);
  rightBack.run(FORWARD);
  rightFront.run(FORWARD);
  leftBack.run(BACKWARD);
  leftFront.run(FORWARD);
  delay(10000)
  rightBack.setSpeed(motorSpeed);
  rightFront.setSpeed(motorSpeed);
  leftFront.setSpeed(motorSpeed);
  leftBck.setSpeed(motorSpeed);
  rightBack.run(FORWARD);
  rightFront.run(FORWARD);
  leftBack.run(FORWARD);
  leftFront.run(FORWARD);  
  
}
else if (distance > 20)
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

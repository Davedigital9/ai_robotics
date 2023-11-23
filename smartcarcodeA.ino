#include <Servo.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *rightback = AFMS.getMotor(1);
Adafruit_DCMotor *rightfront = AFMS.getMotor(2);
Adafruit_DCMotor *leftback = AFMS.getMotor(3);
Adafruit_DCMotor *leftfront = AFMS.getMotor(4);

byte motorSpeed = 55; 
int motorOffset = 20; 
int turnSpeed = 45;

int trg = 2;
int ech = 3;
int servoPin = 4 ;
float distance;

int obstacle = 5;
int obstacle_sense; 

Servo servo;

void setup() {
  // put your setup code here, to run once:
AFMS.begin();
servo.attach(servoPin);  
Serial.begin(9600);

rightback->setSpeed(motorSpeed);
rightfront->setSpeed(motorSpeed); 
leftfront->setSpeed(motorSpeed);
leftback->setSpeed(motorSpeed);
rightback->run(RELEASE);
rightfront->run(RELEASE);
leftback->run(FORWARD);
leftfront->run(FORWARD);

pinMode(trg, OUTPUT);
pinMode(ech, INPUT);
pinMode(obstacle, INPUT);
pinMode(servoPin, OUTPUT);
servo.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
rightback->setSpeed(motorSpeed);
rightfront->setSpeed(motorSpeed);
leftfront->setSpeed(motorSpeed);
leftback->setSpeed(motorSpeed);

rightback->run(FORWARD);
rightfront->run(FORWARD);
leftback->run(FORWARD);
leftfront->run(FORWARD);

servo.write(180);
digitalWrite(trg, LOW);
delayMicroseconds (2);
digitalWrite(trg, HIGH);
delayMicroseconds (10);
digitalWrite(trg, LOW);
delayMicroseconds (2);
distance = pulseIn(ech, HIGH) / 58.8;
Serial.println(distance);


if (distance <= 35)
{
  Serial.print("close distance");

  servo.write(180);
  rightback->setSpeed(motorSpeed);
  rightfront->setSpeed(motorSpeed);
  leftfront->setSpeed(motorSpeed);
  leftback->setSpeed(motorSpeed);
  rightback->run(FORWARD);
  rightfront->run(FORWARD);
  leftback->run(BACKWARD);
  leftfront->run(FORWARD);
  
  rightback->setSpeed(motorSpeed);
  rightfront->setSpeed(motorSpeed);
  leftfront->setSpeed(motorSpeed);
  leftback->setSpeed(motorSpeed);
  
  rightback->run(FORWARD);
  rightfront->run(FORWARD);
  leftback->run(FORWARD);
  leftfront->run(FORWARD);  
  
}
else if (distance > 35)
  {
  Serial.println("far distance");

  servo.write(0);
  rightback->setSpeed(motorSpeed);
  rightfront->setSpeed(motorSpeed);
  leftfront->setSpeed(motorSpeed);
  leftback->setSpeed(motorSpeed);
  
  
  rightback->run(FORWARD);
  rightfront->run(FORWARD);
  leftback->run(FORWARD);
  leftfront->run(FORWARD);  
  }

obstacle_sense = digitalRead(obstacle);

if (obstacle_sense = HIGH)
{
  Serial.print("close distance");
  rightback->setSpeed(motorSpeed);
  rightfront->setSpeed(motorSpeed);
  leftfront->setSpeed(motorSpeed);
  leftback->setSpeed(motorSpeed);
  
  rightback->run(FORWARD);
  rightfront->run(FORWARD);
  leftback->run(RELEASE);
  leftfront->run(RELEASE);
  }
else if (obstacle_sense = LOW)
{
  Serial.print("far distance");
  rightback->setSpeed(motorSpeed);
  rightfront->setSpeed(motorSpeed);
  leftfront->setSpeed(motorSpeed);
  leftback->setSpeed(motorSpeed);
  
  rightback->run(FORWARD);
  rightfront->run(FORWARD);
  leftback->run(FORWARD);
  leftfront->run(FORWARD);
  }

}

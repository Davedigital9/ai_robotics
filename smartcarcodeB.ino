#include <Servo.h>
#include <NewPing.h>
#include <AFMotor.h>

#define TRIG_PIN A0 // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN A1 // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters)
#define MAX_SPEED 150 
#define MAX_SPEED_OFFSET 20

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

Servo servo;

int distanceR;
int distanceL;
float distance;
boolean goesForward;
byte speedSet;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  servo.attach(10);
  servo.write(115); 
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(distance<=15)
  {
    moveStop();
    delay(100);
    moveBackward();
    delay(300);
    moveStop();
    delay(200);
    distanceR = lookRight();
    delay(200);
    distanceL = lookLeft();
    delay(200);
  
      if(distanceR>=distanceL)  //this means that if the distance of the obstacle from distanceR is the same as the distance from distanceL it should change direction
    {
        turnRight();
        moveStop();
    } else
    {
        turnLeft();
        moveStop();
    }
   }
  else    // this is for the frist if, that is, if there is nothing in front of the sensor it should continue moving forward.
 {
  moveForward();
 }
 distance = readPing();
}



int lookRight()   // for the servo to look left to earch for obstacle
{
    servo.write(50); 
    delay(500);
    int distance = readPing();
    delay(100);
    servo.write(115); 
    return distance;
}

int lookLeft()    //for the servo to look right to search for obstacle
{
    servo.write(170); 
    delay(500);
    int distance = readPing();
    delay(100);
    servo.write(115); 
    return distance;
    delay(100);
}


int readPing() { //for the ultrasonic sensor to read the ping
  delay(70);
  int cm = sonar.ping_cm(); //Send a ping and get the distance in whole centimeters.
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}




void moveStop() {
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  } 
  
void moveForward() {

 if(!goesForward)
  {
    goesForward=true;
    motor1.run(FORWARD);      
    motor2.run(FORWARD);
    motor3.run(FORWARD); 
    motor4.run(FORWARD);     
   for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
   {
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    delay(5);
   }
  }
}

void moveBackward() {
    goesForward=false;
    motor1.run(BACKWARD);      
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);  
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
  {
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    delay(5);
  }
}  

void turnRight() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);     
  delay(500);
  motor1.run(FORWARD);      
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);      
} 
 
void turnLeft() {
  motor1.run(BACKWARD);     
  motor2.run(BACKWARD);  
  motor3.run(FORWARD);
  motor4.run(FORWARD);   
  delay(500);
  motor1.run(FORWARD);     
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

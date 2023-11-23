char bluetooth;
int fan = 6;
int led = 8;
int channel_1 = 6;
int channel_2 = 8; //the number is the pin we plugged it into

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(fan, OUTPUT);   //status of my fan
pinMode(led, OUTPUT);   //status of my light
pinMode(channel_1, OUTPUT);
pinMode(channel_2, OUTPUT);
digitalWrite(channel_1, LOW);
digitalWrite(channel_2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  
if(Serial.available())  //main if statement. first condition
{
  bluetooth = Serial.read();    //first action
  digitalWrite(channel_1, HIGH);
  digitalWrite(channel_2, HIGH);

if (bluetooth == 'F')
{
  digitalWrite(fan, LOW);
  }
if (bluetooth == 'R')
{
  digitalWrite(fan, HIGH);
  }
if (bluetooth == 'G')
 {
  digitalWrite(led, LOW);
  }
  else
  {
    digitalWrite(led, HIGH);
    }
  }

/
what is the required weight for the drone
there is a difference btw the drone for the car and the drone
you need a dc motor with a high rpm. the higher the rpm the more the force 
to lift the drone. 
the dc motor has clockwise abd anti clockwise.
coreless dc motor they came with wires to identify positive and negative.
the wires are red and blue for the clockwise dc motor
white and black wires for the anti clockwise dc motor
brushless dc motor - the heavy ones for a bigger drones
the propellers has clockwise and anti clockwise.
alphabet a1-a4 is clockwise
b1-b4 is anti clockwise
use potentiometeer to control the up and down of the drone.

FOR THE CAR
infrared obstacle sensor has the ground, signal and power pins. 
it has two led
the white led is to emmit light. when there is any obstacles obstructing the light
it sends a message the black led to tell it to 
the black led is to trasmit light. it is the trandmitter. 
unltrasonic sensor
it has transmit (T) and receive (R) 
it transmit high frequency waves. 
the receiver listens to any sound the transmitter sends out. once there is an echo
the receiver is to send a signal for a command. 
*/






 
}

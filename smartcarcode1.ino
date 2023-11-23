// code for infrared sensor
int obstacle = 6; // to connect the infrared to the board
//default led on the board is on pin 13
int obstacle_sense;   // to read information from the infrared

void setup() {
  // put your setup code here, to run once:
pinMode(obstacle, INPUT);   //status of the pin
Serial.begin(9600);   //open monitor

}

void loop() {
  // put your main code here, to run repeatedly:
obstacle_sense = digitalRead(obstacle);

if (obstacle_sense = HIGH)
{
  Serial.print("Detected");// writing to monitor
  Serial.println("/n");
  delay(10000);
  }
else if (obstacle_sense = LOW)
{
  Serial.print("NOT DETECTED"); 
  Serial.println("/n");
  delay(1000);
  }
}

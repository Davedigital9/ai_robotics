/*it has trigger pin to send the waves
it has the echo pin to listen to the result of the waves sent
it has the ground pin
it has the vcc pin*/

int trg = 8;
int ech = 9;
float distance;
void setup() {
  // put your setup code here, to run once:
pinMode(trg, OUTPUT);
pinMode(ech, INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trg, LOW);
delayMicroseconds (2);
digitalWrite(trg, HIGH);
delayMicroseconds (10);
digitalWrite(trg, LOW);
delayMicroseconds (2);
distance = pulseIn(ech, HIGH) / 58.8;
//distance = (pulseIn(ech, HIGH) * 0.034)/2;
//the pulseIn is the readig from our echo pin and in this case the velocity. 58.8 is a fixed time
Serial.println(distance);

if (distance <= 20)
  {Serial.print("close distance");}

if (distance > 20)
  {Serial.print("far distance");}

}
/*for the dc motor
we will be using the dc motor controller shield
it has from M1-M4. 
we will be using a library called Adafruit. 
Adafruit Motor Shield V2 Library

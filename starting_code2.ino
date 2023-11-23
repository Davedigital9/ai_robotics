char bluetooth;
int channel_1 = 9;
int channel_4 = 10;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(channel_1, OUTPUT);
pinMode(channel_4, OUTPUT);
digitalWrite(channel_1, LOW);
digitalWrite(channel_4, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available())  //main if statement. first condition
{
  bluetooth = Serial.read();    //first action
if (bluetooth == 'F')
{
  digitalWrite(channel_1, LOW);
  }
if (bluetooth == 'R')
{
  digitalWrite(channel_1, HIGH);
  }
if (bluetooth == 'G')
 {
  digitalWrite(channel_4, LOW);
  }
if (bluetooth == 'D')
  {
    digitalWrite(channel_4, HIGH);
    }
  }
}

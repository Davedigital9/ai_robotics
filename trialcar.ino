char bluetooth;
int channel_1 = 3;
int channel_2 = 4;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); //began the serial number
pinMode(channel_1, OUTPUT);
pinMode(channel_2, OUTPUT);
digitalWrite(channel_1, LOW);
digitalWrite(channel_2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()   // checking if the serial monitor is available
)
{
  bluetooth = Serial.read(); // after checking its availability it is reading what is written in it
  if (bluetooth == '1')
  {
    digitalWrite(channel_1, HIGH); //writing what the fan is to do when clicked
    }
    if (bluetooth == '3')
    {
      digitalWrite(channel_2, HIGH); //writing what the light is to do when clicked
    }
    if (bluetooth == '0')
    {
      digitalWrite(channel_2, LOW);
      }
  if (bluetooth == '2')
  {
   digitalWrite(channel_1, LOW); //writing what the fan is to do when clicked
  }
}  
} 

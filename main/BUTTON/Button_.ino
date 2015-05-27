

  const int TouchPin=2;


void setup() {
pinMode(TouchPin, INPUT);
 Serial.begin(9600);

} 
 
void loop() {
int sensorValue = digitalRead(TouchPin);
if(sensorValue==1)
{
Serial.print(1);
}
else
{
Serial.print(0);
}
}

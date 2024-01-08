void setup() 
{
    Serial.begin(9600);
}
 
void loop() 
{
  int sensor_value = analogRead(A0);
  Serial.println("Noise: " + sensor_value);

  delay(1000);
}
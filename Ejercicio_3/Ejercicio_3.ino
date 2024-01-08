const int LASER_PIN = 13;

void setup()
{
  pinMode(LASER_PIN, OUTPUT);
}

void loop()
{
  digitalWrite(LASER_PIN, HIGH);
  delay(5000);
  digitalWrite(LASER_PIN, LOW);
  delay(1000);
}
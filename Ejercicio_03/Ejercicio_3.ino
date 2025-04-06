// Pin al que está conectado el láser
const int LASER_PIN = 13;

void setup()
{
  // Configura el pin como salida
  pinMode(LASER_PIN, OUTPUT);
}

void loop()
{
  // Enciende el láser 5 segundos
  digitalWrite(LASER_PIN, HIGH);
  delay(5000);

  // Apaga el láser 1 segundo
  digitalWrite(LASER_PIN, LOW);
  delay(1000);
}
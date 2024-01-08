const int RED_PIN = 15;
const int GREEN_PIN = 13;
const int BLUE_PIN = 12;

void setup() 
{
  // Inicializamos pines.
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() 
{
  for (int r = 0; r < 2; r++) {
    for (int g = 0; g < 2; g++) {
      for (int b = 0; b < 2; b++) {
        // Se enciende el LED con un color específico.
        digitalWrite(RED_PIN, r);
        digitalWrite(GREEN_PIN, g);
        digitalWrite(BLUE_PIN, b);

        delay(1000);
      }
    }
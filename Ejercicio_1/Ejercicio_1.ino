const int LED_PIN = 13;

// Función auxiliar para simular un parpadeo del LED.
void blink(const int _current_value)
{
  if (_current_value == HIGH)
    digitalWrite(led_pin, LOW);
  else
    digitalWrite(led_pin, HIGH);
}

void setup() 
{
  pinMode(LED_PIN, OUTPUT); // Se define el pin como salida.
}

void loop() 
{
  blink(digitalRead(LED_PIN));  // Se lee el valor actual del LED y se le pasa a la función.
  delay(1000);  // Espera de un segundo.
}
}
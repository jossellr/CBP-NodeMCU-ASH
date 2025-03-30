const int PIN_BUTTON = 15;  // Pin para recoger la lectura del botón.
const int PIN_LED = 13;     // Pin para interaccionar con el LED.

void setup() 
{  
  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_LED, OUTPUT);
}

void loop() 
{
    digitalWrite(PIN_LED, digitalRead(PIN_BUTTON));
}
const int SENSOR_PIN = 13;
const int LED_PIN = 15;
 
void setup() 
{
    Serial.begin(9600);
    
    // Inicialización.
    pinMode(SENSOR_PIN, INPUT);
    digitalWrite(SENSOR_PIN, LOW);
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
}
 
void loop() 
{
    // Si no hay suficiente luz (por ejemplo, a partir de las 21:00h)...
    if (digitalRead(sensor_pin) == LOW) {
        digitalWrite(LED_PIN, HIGH);   
        Serial.print("It's time to turn on the light!") 
    }
    else
        digitalWrite(LED_PIN, LOW);
}
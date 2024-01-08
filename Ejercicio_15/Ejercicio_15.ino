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
    // Si encuentra un obstáculo...
    if (digitalRead(SENSOR_PIN) == LOW) {
        digitalWrite(LED_PIN, HIGH); 
        Serial.print("Obstacle detected!");
    }
    else
        digitalWrite(LED_PIN, LOW);
}

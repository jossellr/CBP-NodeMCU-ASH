const int SENSOR_PIN = 13;
const int LED_PIN = 15;
 
void setup() 
{
    Serial.begin(9600);
    
    // Inicialización.
    pinMode(SENSOR_PIN, INPUT);
    digitalWrite(SENSOR_PIN, LOW);
    pinMode(LED_PIN, OUTPUT);
}
 
void loop() 
{
    // Si pasa el umbral detecta movimiento.
    if (digitalRead(SENSOR_PIN) == HIGH) {
        digitalWrite(LED_PIN, HIGH); 
        Serial.println("Hey, you're drinking from the cup");
    }else
        digitalWrite(LED_PIN, LOW);

    delay(500);
}
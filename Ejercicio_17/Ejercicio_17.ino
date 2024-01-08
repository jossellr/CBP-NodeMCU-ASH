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
    // El sensor detecta negro.
    if (digitalRead(SENSOR_PIN) == HIGH)
        digitalWrite(LED_PIN, HIGH);   
    else  // El sensor detecta blanco.
        digitalWrite(LED_PIN, LOW);     
}
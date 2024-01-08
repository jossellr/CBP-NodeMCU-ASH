const int LED_PIN = 15;   
const int SENSOR_PIN = 13;
 
void setup() 
{
   Serial.begin(9600);
   
   // Inicialización.
   pinMode(LED_PIN, OUTPUT); 
   pinMode(SENSOR_PIN, INPUT);
   digitalWrite(LED_PIN, LOW);
   digitalWrite(SENSOR_PIN, LOW);
}
 
void loop()
{
  // Si detectamos movimiento...
   if (digitalRead(SENSOR_PIN) == HIGH) {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("Intruder detected!");
   }
   else  
      digitalWrite(LED_PIN, LOW);
}
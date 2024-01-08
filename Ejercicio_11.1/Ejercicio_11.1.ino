void setup() 
{
  Serial.begin(9600);  
}

void loop() 
{
  int sensor_value = analogRead(A0);  # Valor de voltaje en crudo.

  // Conversión a PPM básica.
  int old_range = (1024 - 0);    // Intrvalo de voltaje.
  int new_range = (10000 - 300); // Intervalo de PPM.
  int new_value = (((sensor_value - 0) * new_range) / old_range) + 300;
  
  Serial.println("RAW data: " + sensor_value);
  Serial.println("PPM: " + new_value);
  delay(1000);
}
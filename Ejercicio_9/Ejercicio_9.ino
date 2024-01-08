#include "DHT.h"

DHT sensor(13, DHT11);  // Gestión del sensor.

void setup() 
{
  Serial.begin(9600);
  sensor.begin(); // Inicialización del sensor.
}

void loop() 
{
  delay(2000);

  // Obtenemos los valores del sensor.
  float humidity = sensor.readHumidity();
  float temperature = sensor.readTemperature();

  // Comprobamos si hay valores inválidos.
  if(isnan(humidity) || isnan(temperature))
  {
    Serial.println("Something wrong with sensor!!");
    return;
  }

  // Finalmente, mostramos la información.
  Serial.println("Humidity: ");
  Serial.print(humidity); Serial.print("%.");
  Serial.print(" - Temperature: ");
  Serial.print(temperature); Serial.print(" *C");
}
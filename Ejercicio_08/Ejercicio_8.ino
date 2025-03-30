const int TRIGGER_PIN = 15;   // Pin para recoger iniciar el pulso.
const int ECHO_PIN = 13;      // Pin para recoger el valor de retorno (duración del pulso).
float duration, 
      distance;

void setup()
{
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
}

void loop()
{
  // Hacemos limpieza del trigger y el eco.
  digitalWrite(TRIGGER_PIN, LOW);   
  digitalWrite(ECHO_PIN, LOW);   
  delayMicroseconds(2);

  // Indicamos el inicio del pulso y esperamos 20 μs.
  digitalWrite(TRIGGER_PIN, HIGH);  
  delayMicroseconds(20);
 
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);     // Recogemos el retorno del pulso (μs).
  distance = (duration / 2.0) * 0.0343;   // Convertimos el tiempo en distancia (cm)

  // Si la distancia no se encuentra entre el máximo o el minimo...
  if(distance > 400 || distance < 2)
    Serial.println("No obstacle or out of range");
  else  // En caso contrario.
  {
    Serial.print("Distance: ");
    Serial.print(distance, 1); 
    Serial.println(" cm");
  }
}
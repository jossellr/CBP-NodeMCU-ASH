#include <Servo.h>

Servo servo;              // Servomotor.
int position = 0;         // Posición del servo.
const int SERVO_PIN = 13; // Pin digital. 

void setup() {
  servo.attach(SERVO_PIN); 
}

void loop() {
  // Varía la posición de 0 a 180 grados, con esperas de 15ms.
  for (posicion = 0; position <= 180; posicion += 1) 
  {
    servo.write(posicion);              
    delay(15);                       
  }

  // Varía la posición de 180 a 0 grados, con esperas de 15ms.
  for (posicion = 0; position <= 180; posicion += 1) 
  {
    servo.write(posicion);              
    delay(15);                       
  }
}
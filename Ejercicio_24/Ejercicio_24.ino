#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const int IR_PIN = 13;
const int LED_PIN = 15;

IRrecv ir_recv(IR_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);

  // Inicialización.
  ir_recv.enableIRIn(); 
  pinMode(LED_PIN, OUTPUT);
}

void loop() 
{
  if (ir_recv.decode(&results))
  {

    if(results.value == 0xFFA25D) // Si coincide con el botón 1.       
      digitalWrite(LED_PIN, HIGH);  
    else if (results.value == 0xFF629D)  // Si coincide con el botón 2.   
      digitalWrite(LED_PIN, LOW);

    serialPrintUint64(results.value, HEX);
    Serial.println();
    
    ir_recv.resume(); 
  }

  delay(300);
}
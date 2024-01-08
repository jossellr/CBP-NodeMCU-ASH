#include <RCSwitch.h>

const int LED_CODE = 1011;
const int DATA_PIN = 15;
const int BUTTON_PIN = 13;

RCSwitch channel = RCSwitch();
bool centinel = false;  // Sirve para enviar una única vez la acción.
 
void setup()
{
    // Inicialización
    pinMode(BUTTON_PIN, INPUT);
    channel.enableTransmit(DATA_PIN);
}
 
void loop()
{
    // Si todavía no se ha enviado y se está pulsando...
    if(!centinel && digitalRead(BUTTON_PIN) == HIGH)
    {
        centinel = true;
        channel.send(LED_CODE, 24);
    }
    else
      centinel = false;
}

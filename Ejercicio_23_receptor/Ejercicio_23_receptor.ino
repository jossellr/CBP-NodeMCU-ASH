#include <RCSwitch.h>

#define LED_CODE 1011

const int DATA_PIN = 15;
const int LED_PIN = 13;

RCSwitch channel = RCSwitch();

void setup() {
  Serial.println(9600);

  // Inicialización.
  channel.enableReceive(DATA_PIN);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  if (channel.available()) {
    Serial.println(channel.getReceivedValue());

    // Si recibimos el código de la acción...
    if (channel.getReceivedValue() == LED_CODE) {
      if (digitalRead(LED_PIN) == LOW)
        digitalWrite(LED_PIN, HIGH);
      else
        digitalWrite(LED_PIN, LOW);
    }

    channel.resetAvailable();
  }
}
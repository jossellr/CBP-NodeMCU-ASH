const int PIN_BUZZER = 13;  // Pin donde está conectado el zumbador

// Array de frecuencias (notas musicales)
const int melody[] = {
  440, 440, 440, 349, 523, 440, 349, 523, 440,   
  659, 659, 659, 698, 523, 415, 349, 523, 440,   
  349, 415, 349, 440, 349, 523, 440             
};

// Array de duraciones (en milisegundos)
const int noteDurations[] = {
  500, 500, 500, 350, 150, 500, 350, 150, 650,
  500, 500, 500, 350, 150, 500, 350, 150, 650,
  250, 500, 375, 125, 500, 375, 650
};

const int numNotes = sizeof(melody) / sizeof(melody[0]);

void setup() {
  // Nada que configurar
}

void loop() {
  for (int i = 0; i < numNotes; i++) {
    tone(PIN_BUZZER, melody[i], noteDurations[i]);    // Emite la nota
    delay(noteDurations[i] * 1.3);                    // Espera entre notas
    noTone(PIN_BUZZER);                               // Detiene el tono
  }

  delay(3000);  // Pausa entre repeticiones
}
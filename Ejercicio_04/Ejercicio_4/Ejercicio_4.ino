#include "LiquidCrystal_I2C.h"  // Biblioteca de terceros.

LiquidCrystal_I2C lcd(0x27, 16, 2); 

byte HUMAN_CHAR [] = 
{
  B01110,
  B01110,
  B00100,
  B11111,
  B00100,
  B01110,
  B01010,
  B01010
};

byte HUMAN_CHAR_2 [] = 
{
  B01110,
  B01110,
  B10101,
  B01110,
  B00100,
  B00100,
  B01010,
  B10001
};

void setup()
{
  // Inicialización del LCD.
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // Definimos caracteres especiales.
  lcd.createChar(0, HUMAN_CHAR);
  lcd.createChar(1, HUMAN_CHAR_2);

  // Printeamos el texto.
  lcd.setCursor(0, 0);
  lcd.print("Hola");
  lcd.setCursor(2, 1);
  lcd.print("mundo!");
}

// Cambiamos entre los dos caracteres especiales cada segundo.
void loop()
{
  lcd.setCursor(0, 1);
  lcd.write(0);
  delay(1000);
  
  lcd.setCursor(0, 1);
  lcd.write(1);
  delay(1000);
}
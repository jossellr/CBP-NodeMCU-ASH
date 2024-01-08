#include <Wire.h>
#define Addr 0x1C

void setup() {
  // Inicialización.
  Wire.begin();
  Serial.begin(9600);

  // Calibración inicial.
  Wire.beginTransmission(Addr);
  Wire.write(0x2A);
  Wire.write((byte)0x00);
  Wire.endTransmission();

  Wire.beginTransmission(Addr);
  Wire.write(0x2A);
  Wire.write(0x01);
  Wire.endTransmission();

  Wire.beginTransmission(Addr);
  Wire.write(0x0E);
  Wire.write((byte)0x00);
  Wire.endTransmission();

  delay(300);
}

void loop() {
  unsigned int data[7];

  Wire.requestFrom(Addr, 7);

  // Lectura de 7 bytes, donde cada bit es: 
  // status, xAccl lsb, xAccl msb, yAccl lsb, yAccl msb, zAccl lsb, zAccl msb
  if (Wire.available() == 7)
  {
    data[0] = Wire.read();
    data[1] = Wire.read();
    data[2] = Wire.read();
    data[3] = Wire.read();
    data[4] = Wire.read();
    data[5] = Wire.read();
    data[6] = Wire.read();
  }

  // Convertimos cada byte a 12 bits.
  int xAccl = ((data[1] * 256) + data[2]) / 16;
  if (xAccl > 2047) {
    xAccl -= 4096;
  }

  int yAccl = ((data[3] * 256) + data[4]) / 16;
  if (yAccl > 2047) {
    yAccl -= 4096;
  }

  int zAccl = ((data[5] * 256) + data[6]) / 16;
  if (zAccl > 2047) {
    zAccl -= 4096;
  }

  // Mostramos por pantalla la acelración en cada uno de sus ejes.
  Serial.print("Acceleration in X-Axis : ");
  Serial.println(xAccl);
  Serial.print("Acceleration in Y-Axis : ");
  Serial.println(yAccl);
  Serial.print("Acceleration in Z-Axis : ");
  Serial.println(zAccl);
  
  delay(500);
}
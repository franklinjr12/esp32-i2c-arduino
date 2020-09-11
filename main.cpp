/*
 * Example of esp32 i2c Master with arduino
 * as slave.
 * A bidirectional logic level converter is used.
 * Obs: Esp32 on 11/09/2020 doenst support slave mode.
 */

#include <Arduino.h>
#include <Wire.h>

unsigned int t;
unsigned int t2;

void setup()
{
  Serial.begin(9600);
  Wire.begin(21, 22, 100000);
  t = millis();
  t2 = millis();
  Serial.println("\nSetup ok");
}

void loop()
{
  if (millis() - t2 > 1500)
  {
    t2 = millis();
    // Serial.println("Esp32 requesting from arduino");
    Wire.requestFrom(8, strlen("Arduino->Esp32"));

    while (Wire.available())
    {
      Serial.print(((char)Wire.read()));
    }
    Serial.println();
  }
  if (millis() - t > 1000)
  {
    t = millis();
    Serial.println("\nEsp32 sending");
    String s = "Esp32->Arduino";
    Wire.beginTransmission(8);
    // Wire.writeTransmission()
    Wire.write(s.c_str());
    // for (int i = 0; i < s.length(); i++)
    // Wire.write(s[i]);
    Wire.endTransmission();
  }
}
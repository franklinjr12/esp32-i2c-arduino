/*
 * Example of esp32 i2c Master with arduino
 * as slave.
 * A bidirectional logic level converter is used.
 * Obs: Esp32 on 11/09/2020 doenst support slave mode.
 */
#include <Arduino.h>
#include <Wire.h>

void receive(int n)
{
  while (Wire.available())
  {
    Serial.print(((char)Wire.read()));
  }
  Serial.println();
}

void request()
{
  Serial.println("Arduino sending");
  Wire.write("Arduino->Esp32");
}

void setup()
{
  Serial.begin(9600);
  Wire.begin(8);
  Wire.onReceive(receive);
  Wire.onRequest(request);
  Serial.println("\nSetup ok");
}

void loop()
{
  // put your main code here, to run repeatedly:
}
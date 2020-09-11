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

  if (millis() - t > 1000)
  {
    t = millis();

    String s = "minute";
    Wire.beginTransmission(8);
    Wire.write(s.c_str());
    Wire.endTransmission();
    int n = 0;
    Wire.requestFrom(8, 1);
    n = Wire.read();
    Serial.println("M= " + String(n));

    s = "second";
    Wire.beginTransmission(8);
    Wire.write(s.c_str());
    Wire.endTransmission();
    Wire.requestFrom(8, 1);
    n = Wire.read();
    Serial.println("S= " + String(n));

    s = "hello";
    Wire.beginTransmission(8);
    Wire.write(s.c_str());
    Wire.endTransmission();
    Wire.requestFrom(8, 1);
    n = Wire.read();
    delay(1);
    Wire.beginTransmission(8);
    Wire.write("send");
    Wire.endTransmission();
    s = "";
    Wire.requestFrom(8, n);
    while (Wire.available())
      s += ((char)(Wire.read()));
    Serial.println("Got: " + s);
  }
}
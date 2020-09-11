#include <Arduino.h>
#include <Wire.h>

String send;
String receive;
String command;
int l;
int m;
int s;
bool b;
void i2c_receive(int n)
{
  command = "";
  while (Wire.available())
  {
    command += ((char)Wire.read());
  }
}

void i2c_request()
{
  if (b)
  {
    Wire.write(send.c_str());
    b = false;
  }
  else
  {
    Wire.write(l);
  }
}

void setup()
{
  Serial.begin(9600);
  Wire.begin(8);
  Wire.onReceive(i2c_receive);
  Wire.onRequest(i2c_request);
  l = 0;
  send = "";
  receive = "";
  command = "";
  m = 1;
  s = 30;
  b = false;
  Serial.println("\nSetup ok");
}

void loop()
{
  if (command == "minute")
  {
    command = "";
    l = m;
  }
  else if (command == "second")
  {
    command = "";
    l = s;
  }
  else if (command == "hello")
  {
    command = "";
    send = "hello";
    l = send.length();
  }
  else if (command == "send")
  {
    command = "";
    b = true;
  }
}
#include <Arduino.h> //libaries need to run the program
#include <WiFi.h>
#include <AsyncUDP.h>
#include "JoyStick.h"
#include "ChangeColor.h"

//inputs need to run the program
int interval = 1000;
unsigned long currentMillis;
unsigned long previosMillis = 0;
JoyStick joyStick(39, 36, 14);
button Button(23);

const char *ssid = "";     //input name of network
const char *password = ""; //input the password for the network

void setup()
{
  Serial.begin(9600);         // the program begins
  WiFi.mode(WIFI_STA);        // to connects to the Wifi
  WiFi.begin(ssid, password); // checks if the WiFi name and password
}

//set currentMillis to millis if currentMillis - previosMillis is longer then the interval run the code
void loop()
{
  currentMillis = millis();
  if (currentMillis - previosMillis > interval)
  {
    joyStick.PixelMovement();
    Button.changeColor();
    previosMillis = currentMillis;
  }
}
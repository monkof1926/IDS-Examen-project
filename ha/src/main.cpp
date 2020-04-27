#include <Arduino.h>
#include <WiFi.h> //liberys need to run the program
#include <AsyncUDP.h>
#include "JoyStick.h"
#include "ChangeColor.h"

int interval = 1000;
unsigned long currentMillis;
unsigned long previosMillis = 0;
JoyStick joyStick (39,36,14);
button Button(23);


const char *ssid = "NETGEAR74-5G";      //input name of network
const char *password = "sweetchair444"; //input the password for the network


void setup()
{
  Serial.begin(9600);                // the program begins
  WiFi.mode(WIFI_STA);               // to connects to the Wifi
  WiFi.begin(ssid, password);        // checks if the WiFi name and password
}


void loop()
{
  currentMillis = millis();
  if(currentMillis - previosMillis > interval){
  joyStick.PixelMovement();
  Button.changeColor();
  previosMillis = currentMillis;
  }
}
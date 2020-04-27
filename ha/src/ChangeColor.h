#include <Arduino.h>
#include <WiFi.h>
#include <AsyncUDP.h> 

class button{
 int PushButton;
 AsyncUDP UDP;
int port = 7000;

public:

button(int PushButton){
    this -> PushButton = PushButton;
    pinMode(this -> PushButton,INPUT);
}

bool ButtonChange()
        {
            if (digitalRead(PushButton) == LOW)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

 void changeColor(){
     if(ButtonChange() == true){
       UDP.broadcastTo("color 255 8 127", port);
     }
 }
};
#include <Arduino.h> //libaries need to run the program
#include <WiFi.h>
#include <AsyncUDP.h>

/*creates a button class that changes the color of the pixel */
class button
{
    int PushButton;  // the pin for the button
    AsyncUDP UDP;    // creates an AsyncUDP object
    int port = 7000; // assign a port to broadcast to

public:
    //creates a constrotur for the button and set the pinMode for the button
    button(int PushButton)
    {
        this->PushButton = PushButton;
        pinMode(this->PushButton, INPUT);
    }
    // see if the button have been pressed
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
    // change the color to pink if the button has pressed
    void changeColor()
    {
        if (ButtonChange() == true)
        {
            UDP.broadcastTo("color 255 8 127", port);
        }
    }
};
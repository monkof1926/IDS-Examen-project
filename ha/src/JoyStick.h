#include <Arduino.h>
#include <WiFi.h>
#include <AsyncUDP.h> 



class JoyStick
{

public:
    int pinX;       //the pin for the x
    int pinY;       //the pin for the y
    int buttonPres; // the pin for the button
    int valX;
    int valY;
    int Button;      
    AsyncUDP UDP; // creates an AsyncUDP object
    int port = 7000; // assign a port to broadcast yo
    
 

    JoyStick(int pinX, int pinY, int Button){
        this->pinX = pinX;
        pinMode(this->pinX, INPUT);
        this->pinY = pinY;
        pinMode(this->pinY, INPUT);
        this->Button = Button;
        pinMode(this->Button, INPUT_PULLUP);
    }

    int hasChangedX()
    {
        valX = analogRead(pinX);
        if (valX < 500)
        {
            return -1;
        }
        else if (valX > 4000)
        {
            return 1;
        }
        else
            return 0;
    }
    int hasChangedY()
    {
        valY = analogRead(pinY);
        if (valY < 500)
        {
            return -1;
        }
        else if (valY > 4000)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
        bool Press()
        {
            if (digitalRead(buttonPres) == LOW)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        void PixelMovement()
        {           
            if (hasChangedX() == -1)
            {
                UDP.broadcastTo("moveright", port);
                Serial.println("moveright");
            }
            else if (hasChangedX() == 1)
            {
                UDP.broadcastTo("moveleft", port);
                Serial.println("moveleft");
            }
            if (hasChangedY() == -1)
            {
                UDP.broadcastTo("moveup", port);
                Serial.println("moveup");
            }
            else if (hasChangedY() == 1)
            {
                UDP.broadcastTo("movedown", port);
                Serial.println("movedown");
            }
            if (Press() == true)
            {
                UDP.broadcastTo("init 5 5 ", port);
            }
        }
};
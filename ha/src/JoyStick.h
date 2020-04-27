#include <Arduino.h> //libaries need to run the program
#include <WiFi.h>
#include <AsyncUDP.h>

/*creates a JoyStick class that moves the pixel */
class JoyStick
{

public:
    int pinX;        //pin for the x
    int pinY;        //pin for the y
    int buttonPres;  // pin for the button
    int valX;        // temporary value for the x
    int valY;        // temporary value for the y
    int Button;      // pin for button on the joystick
    AsyncUDP UDP;    // creates an AsyncUDP object
    int port = 7000; // assign a port to broadcast to

    //creates a constrotur for the JoyStick and set the pinMode for the x, y and button
    JoyStick(int pinX, int pinY, int Button)
    {
        this->pinX = pinX;
        pinMode(this->pinX, INPUT);
        this->pinY = pinY;
        pinMode(this->pinY, INPUT);
        this->Button = Button;
        pinMode(this->Button, INPUT_PULLUP);
    }
    // see if the x axis hase change and what direction the pixel moves
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
    // see if the y axis hase change and what direction the pixel moves
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
    // see if the button have been pressed
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
    //moves the pixel if x and y axes have change and if the button has been pressed
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
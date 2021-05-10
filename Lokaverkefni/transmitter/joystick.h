/*
    Sveinn Oli, G.
    Joystick library used to interact with the joystick and return directional control.
*/

#ifndef Joystick_h
#define Joystick_h

#include "Arduino.h"


class Joystick
{
    public:
        Joystick(int x, int y, bool button_state);
        void print_data();
    private:
        int _x;
        int _y;
        int _button_state;
};

#endif
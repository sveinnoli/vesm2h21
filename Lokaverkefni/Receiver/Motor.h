/*
    Sveinn Oli, G.
    Motor library used to control motors
*/

#ifndef Motor_h
#define Motor.h

#include "Arduino.h"

class Motor
{
    public:
        Motor(uint8_t *motorcontrols);
    private:
        uint8_t *motorcontrols;
        int _x;
        int _y;
};

#endif

/*
    Sveinn Oli, G.
    Motor library used to control motors
*/
#include "Arduino.h"
#include "Motor.h"

Motor::Motor(uint8_t *motorcontrols)
{
    _x = motorcontrols[1];
    _y = motorcontrols[0];
    

}
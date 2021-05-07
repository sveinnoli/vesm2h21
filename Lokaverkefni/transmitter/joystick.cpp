/*
    Sveinn Oli, G.
    Joystick library used to interact with the joystick and return directional control.
*/

#include "Arduino.h"
#include "Joystick.h"

Joystick::Joystick(int x, int y, bool button_state)
{
    _x = x;
    _y = y;
    _button_state = button_state;
}

void Joystick::update(new_x, new_y, new_button_state) {
    _x = new_x;
    _y = new_y;
    _button_state = new_button_state;
}

void Joystick::print_data() {
    Serial.print(_x);
    Serial.print(_y);
    Serial.print(_button_state);
}

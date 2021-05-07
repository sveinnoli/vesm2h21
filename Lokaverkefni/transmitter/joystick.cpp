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

void Joystick::update_data(int new_x, int new_y, bool new_button_state) {
    _x = new_x;
    _y = new_y;
    _button_state = new_button_state;
}

void Joystick::debug() {
  Serial.println(_x);  
  Serial.println(_y);
  Serial.println(_button_state);
}

int* Joystick::ret_array(int *arr) {
    int *arr;
    arr[0] = _x;
    arr[1] = _y;
    arr[2] = _button_state;
    return arr;
}

/*
    Sveinn Oli, G.
    Position library used to interact with devices that return positional data and gives directional control.
*/

#include "Arduino.h"
#include "Position.h"

Position::Position(int x, int y, bool button_state)
{
    _x = x;
    _y = y;
    _button_state = button_state;
}

void Position::update_data(int new_x, int new_y, bool new_button_state) {
    _x = new_x;
    _y = new_y;
    _button_state = new_button_state;
}

void Position::debug() {
  Serial.println(_x);  
  Serial.println(_y);
  Serial.println(_button_state);
}

int* Position::ret_array(int *arr) {
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    return arr;
}

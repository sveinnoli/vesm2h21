/*
    Sveinn Oli, G.
    Coordinate library used to interact with devices that return Coordinal data and gives directional control.
*/

#include "Arduino.h"
#include "Coordinate.h"

Coordinate::Coordinate(int x, int y, bool button_state, uint8_t orientation)
{
    _x = x;
    _y = y;
    _button_state = button_state;
    _orientation = orientation;
}

void Coordinate::set_orientation(uint8_t new_orientation) {
    _orientation = new_orientation;
}

void Coordinate::update_data(int new_x, int new_y, bool new_button_state) {
    _x = new_x;
    _y = new_y;
    _button_state = new_button_state;
}

void Coordinate::debug() {
  Serial.println(_x);  
  Serial.println(_y);
  Serial.println(_button_state);
}

int* Coordinate::ret_array(int *arr) {
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    return arr;
}

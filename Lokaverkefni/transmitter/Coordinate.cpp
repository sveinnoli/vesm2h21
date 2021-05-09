/*
    Sveinn Oli, G.
    Coordinate library used to interact with devices that return Coordinal data and gives directional control.
*/

#include "Arduino.h"
#include "Coordinate.h"

Coordinate::Coordinate(int x, int y, uint8_t *arr, uint8_t orientation, bool button_state)
{
    _x = x;
    _y = y;
    _arr = arr;
    _button_state = button_state;
    _orientation = orientation;
}

void Coordinate::set_orientation(uint8_t new_orientation) {
    _orientation = new_orientation;
}

void Coordinate::correct_orientation() {
    if (_orientation != 1) {
        // Axis is rotated 90° Clockwise
        if (_orientation == 2) {
            _x = _x*-1;
            _x = _x + _y;
            _y = _x - _y;
            _x = _x - _y;
        } 
        // Axis is rotated 180° 
        else if (_orientation == 3) {
            _x = _x*-1;
            _y = _y*-1;
        }
        // Axis is rotated 90° counterclockwise
        else if (_orientation == 4) {
            _x = _x + _y;
            _y = _x - _y;
            _x = _x - _y;
            _x = _x*-1;
        }
    }
}

void Coordinate::update_data(int new_x, int new_y, bool new_button_state) {
    _x = new_x;
    _y = new_y;
    _button_state = new_button_state;
}

void Coordinate::debug() {
  Serial.print("X: ");  
  Serial.println(_x);  
  Serial.print("Y: ");  
  Serial.println(_y);
  Serial.print("Button State: ");  
  Serial.println(_button_state);
}

uint8_t* Coordinate::get_positional_data(uint8_t to_max, int a_max, int f_max, int b_max, int r_max, int l_max ) {
    correct_orientation();
    //Forward
    if (_y >= 0) {
        _y = map(_y, 0, a_max*f_max, 0, to_max);
        _arr[2] = 0;
        _arr[0] = _y;
    } 
    //Backwards
    else if (_y < 0) {
        _y = map(_y*-1, 0, a_max*b_max, 0, to_max);
        _arr[2] = 1;
        _arr[0] = _y;
    } 

    //Right
    if (_x >= 0) {
        _x = map(_x, 0, a_max*r_max, 0, to_max);
        _arr[3] = 0;
        _arr[1] = _x;
    } 
    //Left
    else if (_x < 0) {
        _x = map(_x*-1, 0, a_max*l_max, 0, to_max);
        _arr[3] = 1;
        _arr[1] = _x;
    }
    return _arr;
}

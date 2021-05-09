/*
    Sveinn Oli, G.
    Coordinate library used to interact with devices that return Coordinal data and gives directional control.
*/

#include "Arduino.h"
#include "Coordinate.h"

Coordinate::Coordinate(float x, float y, bool button_state, uint8_t orientation)
{
    _x = x;
    _y = y;
    _button_state = button_state;
    _orientation = orientation;
}

void Coordinate::set_orientation(uint8_t new_orientation) {
    _orientation = new_orientation;
}

void Coordinate::correct_orientation(void) {
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
            _x = -_x;
        }
    }
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

uint8_t* Coordinate::get_directions(uint8_t *arr, int center_offset, int max_value, uint8_t max_speed) {
    correct_orientation();
    //Forward
    if (_y >= 0) {
        arr[2] = 0;
    } 
    //Backwards
    else if (_y < 0) {
        arr[2] = 1;
    } 

    //Right
    if (_x >= 0) {
        arr[3] = 0;
    } 
    //Left
    else if (_x < 0) {
        arr[3] = 1;
    }
    return arr;
}

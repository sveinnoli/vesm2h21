/*
    Sveinn Oli, G.
    Coordinate library used to interact with the Coordinate and return directional control.
*/

#ifndef Coordinate_h
#define Coordinate_h

#include "Arduino.h"


class Coordinate
{
    public:
        Coordinate(int x, int y, bool button_state);
        void update_data(int new_x, int new_y, bool new_button_state);
        void debug();
        int* ret_array(int* arr);
        int* direction(char[15] direction, int pos, int center_offset, int max_value, uint8_t max_speed);
    private:
        int _x;
        int _y;
        int _button_state;
};

#endif

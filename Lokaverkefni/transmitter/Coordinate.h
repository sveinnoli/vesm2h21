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
        Coordinate(int x, int y, uint8_t *arr, uint8_t orientation=1,  bool button_state=true);
        void set_orientation(uint8_t orientation);
        void correct_orientation();
        void update_data(int new_x, int new_y, bool new_button_state=1);
        void debug();
        uint8_t* get_positional_data(uint8_t to_max=255, int a_max=255, int f_max=1, int b_max=1, int r_max=1, int l_max=1);
    private:
        int _x;
        int _y;
        int _button_state;
        uint8_t _arr;
        uint8_t _orientation;
};

#endif

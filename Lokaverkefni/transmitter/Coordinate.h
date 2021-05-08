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
        Coordinate(float x, float y, bool button_state, uint8_t orientation);
        void set_orientation(uint8_t orientation);
        void update_data(int new_x, int new_y, bool new_button_state=1);
        void debug();
        int* ret_array(int* arr);
        uint8_t* get_directions(int* arr ,int center_offset, int max_value, uint8_t max_speed);
    private:
        float _x;
        float _y;
        int _button_state;
        uint8_t _orientation;
};

#endif

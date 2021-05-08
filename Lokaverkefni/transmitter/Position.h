/*
    Sveinn Oli, G.
    Position library used to interact with the Position and return directional control.
*/

#ifndef Position_h
#define Position_h

#include "Arduino.h"


class Position
{
    public:
        Position(int x, int y, bool button_state);
        void update_data(int new_x, int new_y, bool new_button_state);
        void debug();
        int* ret_array(int* arr);
        
    private:
        int _x;
        int _y;
        int _button_state;
};

#endif

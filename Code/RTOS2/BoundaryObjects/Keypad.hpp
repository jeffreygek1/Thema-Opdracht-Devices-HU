#ifndef KEYPAD_HPP
#define KEYPAD_HPP

#include "hwlib.hpp"

class Keypad{
private:
    hwlib::keypad<16> keypad_IO;
public:
    Keypad(hwlib::keypad<16> keypad_IO);
    char get();
};

#endif // KEYPAD_HPP

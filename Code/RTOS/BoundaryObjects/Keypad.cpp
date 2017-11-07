#include "Keypad.hpp"

Keypad::Keypad(hwlib::keypad<16> keypad_IO):
    keypad_IO(keypad_IO)
    {}
    
char Keypad::get(){
    return keypad_IO.getc();
    }



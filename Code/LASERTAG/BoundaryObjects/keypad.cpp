/// \file keypad.cpp
/// The keypad file,
/// contains the keypad boundary object implementation
/// Date file created:
/// \date 06-11-2017
/// Date last modified:
/// \date 08-11-2017

#include "keypad.hpp"

keypad::keypad(
	hwlib::keypad<16> keypadIO
):
    keypadIO(keypadIO)
{}

char keypad::get(){
    return keypadIO.getc();
}
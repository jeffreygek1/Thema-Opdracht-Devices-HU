/// \file irLed.cpp
/// The irLed file,
/// contains the IR LED boundary object implementation
/// Date file created:
/// \date 06/11/2017
/// Date last modified:
/// \date 08/11/2017

#include "irLed.hpp"

irLed::irLed(
	hwlib::target::d2_36kHz & irLed1
): 
	irLed1(irLed1)
{
    hwlib::wait_ms(500);
}

void irLed::set(int value){
    irLed1.set(value);
}

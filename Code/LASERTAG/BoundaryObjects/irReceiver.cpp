/// \file irReceiver.cpp
/// The irReceiver file,
/// contains the IR receiver boundary object implementation
/// Date file created:
/// \date 06-11-2017
/// Date last modified:
/// \date 08-11-2017

#include "irReceiver.hpp"

irReceiver::irReceiver(
	hwlib::target::pin_in & tsopSignal, 
	hwlib::target::pin_out & tsopGnd, 
	hwlib::target::pin_out & tsopVdd
):
	tsopSignal(tsopSignal),
	tsopGnd(tsopGnd),
	tsopVdd(tsopVdd)
{
	hwlib::wait_ms(100);
	setup();
}
    
bool irReceiver::get(){
    return tsopSignal.get();
}

void irReceiver::setup(){
    hwlib::wait_ms(10);
    tsopGnd.set(0);
    tsopVdd.set(1);
}

/// \file keyPadTaskInit.cpp
/// The keyPadTaskInit file,
/// contains the keypad controller object definition (for the gameleader)
/// Date file created:
/// \date 06-11-2017
/// Date last modified:
/// \date 08-11-2017

#include "keyPadTaskInit.hpp"

keyPadController2::keyPadController2(keypad & keypad2, initGameController & initGame):
        task(4, "KeyPadTask_init"),
        keypad2(keypad2),
        initGame(initGame),
        keyInputDelayTimer2(this, "KeyInputDelayTimer2")
{}



/// \file keyPadTask.hpp
/// The keyPadTask file,
/// contains the keypad controller object definition
/// Date file created:
/// \date 06-11-2017
/// Date last modified:
/// \date 08-11-2017


#include "keyPadTask.hpp"

keyPadController::keyPadController(keypad & keypad1, runGameController & runGame):
        task(4, "KeyPadTask"),
        keypad1(keypad1),
        runGame(runGame),
        keyInputDelayTimer(this, "KeyInputDelayTimer")
{}


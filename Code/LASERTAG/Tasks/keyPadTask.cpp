#include "keyPadTask.hpp"

keyPadController::keyPadController(keypad & keypad1, runGameController & runGame):
        task(4, "KeyPadTask"),
        keypad1(keypad1),
        runGame(runGame),
        keyInputDelayTimer(this, "KeyInputDelayTimer")
{}


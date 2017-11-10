#include "keyPadTaskInit.hpp"

keyPadController2::keyPadController2(keypad & keypad2, initGameController & initGame):
        task(4, "KeyPadTask_init"),
        keypad2(keypad2),
        initGame(initGame),
        keyInputDelayTimer2(this, "KeyInputDelayTimer2")
{}


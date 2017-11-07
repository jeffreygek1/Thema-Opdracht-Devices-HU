#include "KeyPadTask.hpp"

keyPad_Controller::keyPad_Controller(Keypad & keypad1, Run_Game_Controller & run_game):
        task(4, "KeyPadTask"),
        keypad1(keypad1),
        run_game(run_game),
        KeyInputDelayTimer(this, "KeyInputDelayTimer")
{}


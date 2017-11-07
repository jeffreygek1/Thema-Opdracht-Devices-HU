#include "KeyPadTask_init.hpp"

keyPad_Controller2::keyPad_Controller2(Keypad & keypad2, Init_Game_Controller & init_game):
        task(4, "KeyPadTask_init"),
        keypad2(keypad2),
        init_game(init_game),
        KeyInputDelayTimer2(this, "KeyInputDelayTimer2")
{}


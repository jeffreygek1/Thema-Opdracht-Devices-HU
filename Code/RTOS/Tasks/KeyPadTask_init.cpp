#include "KeyPadTask_init.hpp"

keyPadListener2::keyPadListener2(Keypad & keypad2, Init_Game_Controller & init_game):
        task(4, "KeyPadTask_init"),
        keypad2(keypad2),
        init_game(init_game),
        KeyInputDelayTimer2(this, "KeyInputDelayTimer2")
{}


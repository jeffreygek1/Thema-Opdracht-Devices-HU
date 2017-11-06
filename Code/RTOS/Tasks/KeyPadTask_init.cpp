#include "KeyPadTask_init.hpp"

KeyPad_Init_Controller::KeyPad_Init_Controller( hwlib::target::pin_in & sw_test, Init_Game_Controller & run_game ):
    task(4, "KeyPadTask_init"),
    sw_test(sw_test),
    run_game(run_game),
    KeyInputDelayTimer(this, "KeyInputDelayTimer2")
    {}





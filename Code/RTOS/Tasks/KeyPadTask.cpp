#include "KeyPadTask.hpp"

KeyPad_Controller::KeyPad_Controller( hwlib::target::pin_in & sw_test, Run_Game_Controller & run_game ):
    task(4, "KeyPadTask"),
    sw_test(sw_test),
    run_game(run_game)
{}





#include "KeyPadTask_init.hpp"

<<<<<<< HEAD
KeyPad_Init_Controller::KeyPad_Init_Controller( hwlib::target::pin_in & sw_test, Init_Game_Controller & run_game ):
    task(4, "KeyPadTask_init"),
    sw_test(sw_test),
    run_game(run_game),
    KeyInputDelayTimer(this, "KeyInputDelayTimer2")
=======
KeyPad_Controller::KeyPad_Controller( hwlib::target::pin_in & sw_test, Init_Game_Controller & run_game ):
    task(4, "KeyPadTask_init"),
    sw_test(sw_test),
    run_game(run_game),
    KeyInputDelayTimer(this, "KeyInputDelayTimer")
>>>>>>> 278e1268952af882dbe5fd3f63f1412ac2be92de
{}





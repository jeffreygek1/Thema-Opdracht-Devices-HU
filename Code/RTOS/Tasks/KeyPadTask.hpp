#ifndef KEYPADTASK_HPP
#define KEYPADTASK_HPP

#include "RunGameTask.hpp"
#include "bmptk.h"
#include "hwlib.hpp"
#include "rtos.hpp"

class KeyPad_Controller: public rtos::task<>
{
private:
    hwlib::target::pin_in & sw_test;
    Run_Game_Controller & run_game;
    rtos::timer KeyInputDelayTimer;
public:
    KeyPad_Controller( hwlib::target::pin_in & sw_test, Run_Game_Controller & run_game );


    void main() {
        for(;;){
            KeyInputDelayTimer.set(50'000);
            if (!sw_test.get() ){
                run_game.setKeyValueChannel('*');
                run_game.setKeyPressedFlag();
            }
            wait(KeyInputDelayTimer);
            
        }
        
    }
};

#endif // KEYPADTASK_HPP

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
public:
    KeyPad_Controller( hwlib::target::pin_in & sw_test, Run_Game_Controller & run_game );


    void main() {
        for(;;){
            if (!sw_test.get() ){
                run_game.setKeyValueChannel('*');
                run_game.setKeyPressedFlag();
            }
            
            hwlib::wait_us(300);
            
        }
        
    }
};

#endif // KEYPADTASK_HPP

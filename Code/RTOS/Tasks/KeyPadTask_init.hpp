#ifndef KEYPADTASK_INIT_HPP
#define KEYPADTASK_INIT_HPP

#include "InitTask.hpp"
#include "bmptk.h"
#include "hwlib.hpp"
#include "rtos.hpp"

<<<<<<< HEAD
class KeyPad_Init_Controller: public rtos::task<>
{
private:
    hwlib::target::pin_in & sw_test;
    Init_Game_Controller & run_game;
    rtos::timer KeyInputDelayTimer;
public:
    KeyPad_Init_Controller( hwlib::target::pin_in & sw_test, Init_Game_Controller & run_game );
=======
class KeyPad_Controller: public rtos::task<>
{
private:
    hwlib::target::pin_in & sw_test;
    Run_Game_Controller & run_game;
    rtos::timer KeyInputDelayTimer;
public:
    KeyPad_Controller( hwlib::target::pin_in & sw_test, Init_Game_Controller & run_game );
>>>>>>> 278e1268952af882dbe5fd3f63f1412ac2be92de


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
<<<<<<< HEAD
    
=======
>>>>>>> 278e1268952af882dbe5fd3f63f1412ac2be92de
};

#endif // KEYPADTASK_INIT_HPP

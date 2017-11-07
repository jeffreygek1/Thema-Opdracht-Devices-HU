#ifndef KEYPAD_INIT_CONTROLLER_HPP
#define KEYPAD_INIT_CONTROLLER_HPP

#include "rtos.hpp"
#include "Keypad.hpp"
#include "InitTask.hpp"

class keyPad_Controller2 : public rtos::task<> {
private:
    Keypad & keypad2;
    Init_Game_Controller & init_game;
    rtos::timer KeyInputDelayTimer2;
    char c;
    
    
public: 
    keyPad_Controller2(Keypad & keypad2, Init_Game_Controller & init_game);
    
    void main() override{
        for(;;){
            KeyInputDelayTimer2.set(50'000);
            c = keypad2.get();
            init_game.setKeyValueChannel(c);
            init_game.setKeyPressedFlag();
            wait(KeyInputDelayTimer2);
        }
    }
};

#endif // KEYPAD_INIT_CONTROLLER_HPP

#ifndef KEYPADLISTENER_HPP
#define KEYPADLISTENER_HPP

#include "rtos.hpp"
#include "Keypad.hpp"
#include "RunGameTask.hpp"

class keyPad_Controller : public rtos::task<> {
private:
    Keypad & keypad1;
    Run_Game_Controller & run_game;
    rtos::timer KeyInputDelayTimer;
    char c;
    
    
public: 
    keyPad_Controller(Keypad & keypad1, Run_Game_Controller & run_game);
    
    void main() override{
        for(;;){
            KeyInputDelayTimer.set(50'000);
            c = keypad1.get();
            run_game.setKeyValueChannel(c);
            run_game.setKeyPressedFlag();
            wait(KeyInputDelayTimer);
        }
    }
};

#endif // KEYPADLISTENER_HPP

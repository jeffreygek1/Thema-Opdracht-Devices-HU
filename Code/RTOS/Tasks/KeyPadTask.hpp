#ifndef KEYPADLISTENER_HPP
#define KEYPADLISTENER_HPP

#include "rtos.hpp"
#include "Keypad.hpp"
#include "RunGameTask.hpp"

class keyPadListener : public rtos::task<> {
private:
    Keypad & keypad1;
    Run_Game_Controller & run_game;
    rtos::timer KeyInputDelayTimer;
    char c;
    
    
public: 
    keyPadListener(Keypad & keypad1, Run_Game_Controller & run_game);
    
    void main() override{
        for(;;){
            KeyInputDelayTimer.set(50'000);
            c = keypad1.get();
            switch(c){
                case 'A':
                    run_game.setKeyValueChannel('A');
                    run_game.setKeyPressedFlag();
                    break;
                case 'B':
                    run_game.setKeyValueChannel('B');
                    run_game.setKeyPressedFlag();
                    break;
                case 'C':
                    run_game.setKeyValueChannel('C');
                    run_game.setKeyPressedFlag();
                    break;
                case '*':
                    run_game.setKeyValueChannel('*');
                    run_game.setKeyPressedFlag();
                    break;
                case '#':
                    run_game.setKeyValueChannel('#');
                    run_game.setKeyPressedFlag();
                    break;
                default:
                    run_game.setKeyValueChannel(c);
                    run_game.setKeyPressedFlag();
                    break;
            }
            wait(KeyInputDelayTimer);
        }
    }
};

#endif // KEYPADLISTENER_HPP

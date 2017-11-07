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
            switch(c){
                case 'A':
                    init_game.setKeyValueChannel('A');
                    init_game.setKeyPressedFlag();
                    break;
                case 'B':
                    init_game.setKeyValueChannel('B');
                    init_game.setKeyPressedFlag();
                    break;
                case 'C':
                    init_game.setKeyValueChannel('C');
                    init_game.setKeyPressedFlag();
                    break;
                case '*':
                    init_game.setKeyValueChannel('*');
                    init_game.setKeyPressedFlag();
                    break;
                case '#':
                    init_game.setKeyValueChannel('#');
                    init_game.setKeyPressedFlag();
                    break;
                default:
                    init_game.setKeyValueChannel(c);
                    init_game.setKeyPressedFlag();
                    break;
            }
            wait(KeyInputDelayTimer2);
        }
    }
};

#endif // KEYPAD_INIT_CONTROLLER_HPP

/// \file keyPadTaskInit.hpp
/// The keyPadTaskInit file,
/// contains the keypad controller object declaration (for the gameleader)
/// Date file created:
/// \date 06-11-2017
/// Date last modified:
/// \date 08-11-2017

#ifndef KEYPAD_INIT_CONTROLLER_HPP
#define KEYPAD_INIT_CONTROLLER_HPP

#include "rtos.hpp"
#include "keypad.hpp"
#include "initTask.hpp"

/**
 * @author Arsalan Anwari
 * @author Leon Zhang
 * @author Frank Tamer
 * @date 08/11/2017
 * 
 * @brief This control object handles the keypad (of the gameleader)
 * 
 * This object is used by the init game task 
 */
class keyPadController2 : public rtos::task<> {
private:
    keypad & keypad2;
    initGameController & initGame;
    rtos::timer keyInputDelayTimer2;
    char c;
    
    
public: 
    keyPadController2(keypad & keypad2, initGameController & initGame);
    
    void main() override{
        for(;;){
            keyInputDelayTimer2.set(50'000);
            c = keypad2.get();
            initGame.setKeyValueChannel(c);
            initGame.setKeyPressedFlag();
            wait(keyInputDelayTimer2);
        }
    }
};

#endif // KEYPAD_INIT_CONTROLLER_HPP

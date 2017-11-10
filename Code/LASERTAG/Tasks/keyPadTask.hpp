/// \file keyPadTask.hpp
/// The keyPadTask file,
/// contains the keypad controller object declaration
/// Date file created:
/// \date 06-11-2017
/// Date last modified:
/// \date 08-11-2017

#ifndef KEYPADLISTENER_HPP
#define KEYPADLISTENER_HPP

#include "rtos.hpp"
#include "keypad.hpp"
#include "runGameTask.hpp"

/**
 * @author Arsalan Anwari
 * @author Leon Zhang
 * @author Frank Tamer
 * @date 08/11/2017
 * 
 * @brief This control object handles the keypad 
 * 
 * This object is used by the run game task 
 */
class keyPadController : public rtos::task<> {
private:
    keypad & keypad1;
    runGameController & runGame;
    rtos::timer keyInputDelayTimer;
    char c;
    
    
public: 
    keyPadController(keypad & keypad1, runGameController & runGame);
    
    void main() override{
        for(;;){
            keyInputDelayTimer.set(50'000);
            c = keypad1.get();
            runGame.setKeyValueChannel(c);
            runGame.setKeyPressedFlag();
            wait(keyInputDelayTimer);
        }
    }
};

#endif // KEYPADLISTENER_HPP

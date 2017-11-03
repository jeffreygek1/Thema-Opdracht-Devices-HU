#ifndef BEEPER_TASK_HPP
#define BEEPER_TASK_HPP

#include "bmptk.h"
#include "hwlib.hpp"
#include "rtos.hpp"
#include "Beeper.hpp"

class Beeper_Controller: public rtos::task<>{
private:
    Beeper beeper;
    rtos::pool<int> SoundType;
    rtos::mutex SoundMutex;
    rtos::flag SoundFlag;
public: 
    Beeper_Controller(Beeper & beeper);
    
    void setSoundType(int value);
    int getSoundType();
    void resetSoundType();
    
    void setPlaySound();
    void setSoundFlag();
    
    void shootSound();
    void gameOverSound();
    void hitSound();
    
    void main() override{
        int s;
        for(;;){
            wait(SoundFlag);
            s = getSoundType();
            switch(s){
                case 0:
                    break;
                case 1:
                    shootSound();
                    resetSoundType();
                    break;
                case 2:
                    gameOverSound();
                    resetSoundType();
                    break;
                case 3:
                    hitSound();
                    resetSoundType();
                    break;
                default:
                    break;
            }
            hwlib::wait_us(500);

            
        }
        
        
    }
    
};





#endif //BEEPER_TASK_HPP 
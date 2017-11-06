#ifndef BEEPER_TASK_HPP
#define BEEPER_TASK_HPP

#include "bmptk.h"
#include "hwlib.hpp"
#include "rtos.hpp"
#include "Beeper.hpp"

class Beeper_Controller: public rtos::task<>{
private:
    Beeper beeper;
    rtos::pool<int> SoundPool;
    rtos::mutex SoundMutex;
    rtos::flag SoundFlag;
    rtos::timer SoundTimer;
public: 
    Beeper_Controller(Beeper & beeper);
    
    void setSoundPool(int value);
    int getSoundPool();
    void resetSoundPool();
    
    void setSoundFlag();
    
    void shootSound();
    void gameOverSound();
    void hitSound();
    
    void main() override{
        int sound;
        for(;;){
            wait(SoundFlag);
            sound = getSoundPool();
            switch(sound){
                case 0:
                    break;
                case 1:
                    shootSound();
                    resetSoundPool();
                    break;
                case 2:
                    gameOverSound();
                    resetSoundPool();
                    break;
                case 3:
                    hitSound();
                    resetSoundPool();
                    break;
                default:
                    break;
            }

            
        }
        
        
    }
    
};





#endif //BEEPER_TASK_HPP 
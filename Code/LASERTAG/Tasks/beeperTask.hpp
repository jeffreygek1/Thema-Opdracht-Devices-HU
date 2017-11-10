/// \file beeperTask.hpp
/// The beeperTask file,
/// contains the beeper controller object declaration
/// Date file created:
/// \date 06-11-2017
/// Date last modified:
/// \date 08-11-2017

#ifndef BEEPER_TASK_HPP
#define BEEPER_TASK_HPP

#include "bmptk.h"
#include "hwlib.hpp"
#include "rtos.hpp"
#include "beeper.hpp"

/**
 * @author Arsalan Anwari
 * @author Frank Tamer
 * @author Leon Zhang
 * @date 08/11/2017
 * 
 * @brief This beeper object handles what sounds have to be played
 * 
 * This object is used by the run game task 
 */
class beeperController: public rtos::task<>{
private:
    beeper beeper1;
    rtos::pool<int> soundPool;
    rtos::mutex soundMutex;
    rtos::flag soundFlag;
    rtos::timer soundTimer;
public: 
    beeperController(beeper & beeper1);
    
	/**
	 * @brief This function can be used to write to the soundPool channel
	 * @param value: int
	 */
    void setSoundPool(int value);
	/**
	 * @brief This function is used to retrieved the head of the channel
	 * @return int
	 */
    int getSoundPool();
	/**
	 * @brief This function is used to 'reset' the pool by writing a 0 to it.
	 */
    void resetSoundPool();
    /**
     * @brief This function can be used to set the soundFlag event flag
     */
    void setSoundFlag();
    
	/**
	 * @brief This function will play the weapon sound
	 */
    void shootSound();
	/**
	 * @brief This function wil play the end game sound
	 */
    void gameOverSound();
	/**
	 * @brief This function will play a sound when the player is hit
	 */
    void hitSound();
    
    void main() override{
        int sound;
        for(;;){
            wait(soundFlag);
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
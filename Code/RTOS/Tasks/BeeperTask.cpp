/// \file BeeperTask.cpp
/// The BeeperTask file
/// contains the Beepercontroller task
/// Date file created:
/// \date 03-11-2017
/// Date last update:
/// 
/// \date 03-11-2017

#include "BeeperTask.hpp"

Beeper_Controller::Beeper_Controller(Beeper& beeper):
    task(2, "BeeperTask"),
    beeper(beeper),
    SoundPool("SoundPool"),
    SoundMutex("SoundMutex"),
    SoundFlag(this, "SoundFlag"),
    SoundTimer(this, "SoundTimer")
{}

void Beeper_Controller::setSoundPool(int value){
    SoundMutex.wait();
    SoundPool.write(value);
    SoundMutex.signal();
}

int Beeper_Controller::getSoundPool(){
    SoundMutex.wait();
    int n = SoundPool.read();
    SoundMutex.signal();
    
    return n;
}

void Beeper_Controller::resetSoundPool(){
    SoundMutex.wait();
    SoundPool.write(0);
    SoundMutex.signal();
}

void Beeper_Controller::shootSound(){
    beeper.beep(20000, 200000, 990);
}

void Beeper_Controller::gameOverSound(){
    for (int i = 1000; i < 2000; i*=1.02) { 
        beeper.beep(i, 10000); 
    } 
    for (int i = 2000; i > 1000; i*=0.98) {
        beeper.beep(i, 10000);
    }
    for (int i = 1000; i < 1244; i*=1.01) { 
        beeper.beep(i, 10000); 
    } 
    hwlib::wait_us(30000);
    for (int i = 1244; i > 1108; i*= 0.99) {
        beeper.beep(i, 10000);
    }
}

void Beeper_Controller::hitSound(){
    for (int i = 0; i < 2; i++ ){
        SoundTimer.set(20'000);
        beeper.beep(1000, 50000);
        wait(SoundTimer);
   }
}

void Beeper_Controller::setSoundFlag(){
    SoundFlag.set();
}
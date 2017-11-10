#include "beeperTask.hpp"

beeperController::beeperController(beeper & beeper1):
        task(2, "BeeperTask"),
        beeper1(beeper1),
        soundPool("SoundPool"),
        soundMutex("SoundMutex"),
        soundFlag(this, "SoundFlag"),
        soundTimer(this, "SoundTimer")
    {}

void beeperController::setSoundPool(int value){
    soundMutex.wait();
    soundPool.write(value);
    soundMutex.signal();
}

int beeperController::getSoundPool(){
    soundMutex.wait();
    int n = soundPool.read();
    soundMutex.signal();
    return n;
}

void beeperController::resetSoundPool(){
    soundMutex.wait();
    soundPool.write(0);
    soundMutex.signal();
}


void beeperController::shootSound(){
    beeper1.beep( 20000, 200000, 990 );
}

void beeperController::gameOverSound(){
   for (int i=1000; i<2000; i*=1.02) { 
      beeper1.beep(i,10000); 
   } 
   for (int i=2000; i>1000; i*=0.98) {
      beeper1.beep(i,10000);
   }
   for (int i=1000; i<1244; i*=1.01) { 
      beeper1.beep(i,10000); 
   } 
   hwlib::wait_us( 30000 );
   for (int i=1244; i>1108; i*=0.99) {
      beeper1.beep(i,10000);
   }
}

void beeperController::hitSound(){
    for( int i = 0; i < 2; i++ ){
       soundTimer.set(20'000);
       beeper1.beep( 1000, 50000 );
       wait(soundTimer);
   }
}

void beeperController::setSoundFlag(){
    soundFlag.set();
}
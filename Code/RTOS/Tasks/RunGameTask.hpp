#ifndef RUN_GAME_TASK_HPP
#define RUN_GAME_TASK_HPP

#include "bmptk.h"
#include "hwlib.hpp"
#include "rtos.hpp"
#include "BeeperTask.hpp"
#include "IRSendTask.hpp"

class Run_Game_Controller: public rtos::task<>{
private:
    Beeper_Controller & beeper;
    IR_Send_Controller & ir_send;
    enum class states{ init, rungame };
    rtos::flag GameStarted;
public: 
    Run_Game_Controller( Beeper_Controller & beeper, IR_Send_Controller & ir_send );
    
    void setGameStarted();
    
    void main() override{
        auto evt = wait(GameStarted); 
        for (;;){
            
            switch(states){
                case states::init:
                    
                    if(evt == GameStarted){ states = states::rungame; }
                    break;
                case states::rungame:
                
                
                    break;
                
            }
            
            
            hwlib::wait_ms(1000);
            
            
        }
        
    }
    
    
    
    
};







#endif //RUN_GAME_TASK_HPP
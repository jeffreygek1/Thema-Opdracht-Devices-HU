#ifndef RUN_GAME_TASK_HPP
#define RUN_GAME_TASK_HPP

#include "bmptk.h"
#include "hwlib.hpp"
#include "rtos.hpp"
#include "BeeperTask.hpp"
#include "IRSendTask.hpp"
#include "OLEDTask.hpp"
#include "Register_entity.hpp"

class Run_Game_Controller: public rtos::task<>{
private:
    Beeper_Controller & beeper;
    IR_Send_Controller & ir_send;
    OLED_Controller & oled;
    Register_entity & reg;
    int state = 0;
//    rtos::flag GameStarted;
public: 
    Run_Game_Controller( Beeper_Controller & beeper, IR_Send_Controller & ir_send, OLED_Controller & oled, Register_entity & reg );
    
    void setGameStarted();
    // countDown();
    int timePassed(int timeStamp);
    
    void main() override{
//        auto evt = wait(GameStarted);
        int remainTime;
        int timeStamp = hwlib::now_us();
        oled.clear();
        for (;;){
            remainTime = timePassed(timeStamp);
            switch(state){
                case 0:
                    char c = hwlib::cin.getc();
                    switch(c){
                        case 'a':
                            ir_send.setMessageFlag();
                            ir_send.setMessageChannel(0);
                            beeper.setSoundFlag();
                            beeper.setSoundType(1);
                            oled.setTimePool(remainTime);
                            oled.setUpdateFlag();
                            oled.updateDisplay();
                            break;
                    }
                    //if(evt == GameStarted){ states = states::rungame; }
                    break;
                
            }
            hwlib::wait_ms(2);
            
            
        }
        
    }
    
    
    
    
};







#endif //RUN_GAME_TASK_HPP
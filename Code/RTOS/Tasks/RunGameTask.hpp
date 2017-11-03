#ifndef RUN_GAME_TASK_HPP
#define RUN_GAME_TASK_HPP

#include "bmptk.h"
#include "hwlib.hpp"
#include "rtos.hpp"
#include "BeeperTask.hpp"
#include "IRSendTask.hpp"
#include "OLED_Controller.hpp"
#include "Register_entity.hpp"

class Run_Game_Controller: public rtos::task<>{
private:
    Beeper_Controller & beeper;
    IR_Send_Controller & ir_send;
    OLED_Controller & oled;
    Register_entity & reg;
    HP_entity & hp;
    int state = 0;
//    rtos::flag GameStartedFlag;
public: 
    Run_Game_Controller( Beeper_Controller & beeper, IR_Send_Controller & ir_send, OLED_Controller & oled, Register_entity & reg, HP_entity & hp);
    
    //void setGameStartedFlag();
    // void countDown(int dur);
    int timePassed(int timeStamp);
    
    void main() override{
//        auto evt = wait(GameStartedFlag);
        int remainTime;
        int timeStamp = hwlib::now_us();
        oled.printPlayerNumber( reg.getPN() );
        oled.printHP( hp.getHP() );
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
                            oled.printTime( remainTime );
                            break;
                    }
                break;    
                }
                //if(evt == GameStarted){ states = states::rungame; }
            hwlib::wait_ms(500);   
            }
    }
    
    
    
    
};







#endif //RUN_GAME_TASK_HPP
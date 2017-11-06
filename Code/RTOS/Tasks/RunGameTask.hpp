#ifndef RUN_GAME_TASK_HPP
#define RUN_GAME_TASK_HPP

#include "bmptk.h"
#include "hwlib.hpp"
#include "rtos.hpp"
#include "BeeperTask.hpp"
#include "IRSendTask.hpp"
#include "OLED_Controller.hpp"
#include "Register_entity.hpp"
#include "HP_entity.hpp"

class Run_Game_Controller: public rtos::task<>{
private:
    Beeper_Controller & beeper;
    IR_Send_Controller & ir_send;
    OLED_Controller & oled;
    Register_entity & reg;
    HP_entity & hp;
    int state = 0;
//    rtos::flag GameStartedFlag;
    rtos::channel< char, 10 > KeyValueChannel;
    rtos::channel<int, 10> MessageChannelPN;
    rtos::channel<int, 10> MessageChannelData;
    rtos::flag KeyPressedFlag;
    rtos::flag ReceiveFlag;
public: 
    Run_Game_Controller( Beeper_Controller & beeper, IR_Send_Controller & ir_send, OLED_Controller & oled, Register_entity & reg, HP_entity & hp);
    
    //void setGameStartedFlag();
    // void countDown(int dur);
    char getKeyValueChannel();
    void setKeyValueChannel(char key);
    void setKeyPressedFlag();
    
    int getMessageChannelPN();
    void setMessageChannelPN(int pn);
    int getMessageChannelData();
    void setMessageChannelData(int data);
    void setReceiveFlag();
    
    int timePassed(int timeStamp);
    
    void main() override{
        int remainTime;
        int timeStamp = hwlib::now_us();
        char key;
        int pn;
        int data;
        oled.printPlayerNumber( reg.getPN() );
//        oled.printHP( hp.getHP() );
//        oled.printTime( reg.getDU() );
        oled.printHP(hp.getHP(), reg.getDU());
        oled.flush();
        for (;;){
            remainTime = timePassed(timeStamp);
            switch(state){
                case 0:
                    if(remainTime <= 0){
                        hwlib::cout << 'e';
                    }
                    const rtos::event & evt = wait();
                    if (evt == ReceiveFlag){
                        pn = getMessageChannelPN();
                        data = getMessageChannelData();
                        hwlib::cout << 'r';
                        hp.setHP( hp.getHP() - data );
                   }else if (evt == KeyPressedFlag){
                        key = getKeyValueChannel();
                        switch(key){
                            case '*':
                                ir_send.setSendFlag();
                                ir_send.setSendChannel(0);
                                beeper.setSoundFlag();
                                beeper.setSoundPool(1);
//                                oled.printHP( hp.getHP() );
//                                oled.printTime( remainTime );
//                                oled.flush();
                                oled.printHP(hp.getHP(), remainTime);
                                oled.flush();
                                //hwlib::wait_ms( 50'000 );
                                break;
                        }
                    }
                    
                    break;    
                }
            }
    }
    
    
    
    
};







#endif //RUN_GAME_TASK_HPP
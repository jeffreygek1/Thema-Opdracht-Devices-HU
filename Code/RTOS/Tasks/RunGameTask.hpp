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
    int playerNumberSize = 0;
    int firePowerSize = 0;
    rtos::channel< char, 10 > KeyValueChannel;
    rtos::channel<int, 10> MessageChannelPN;
    rtos::channel<int, 10> MessageChannelData;
    rtos::flag KeyPressedFlag;
    rtos::flag ReceiveFlag;
public: 
    Run_Game_Controller( Beeper_Controller & beeper, IR_Send_Controller & ir_send, OLED_Controller & oled, Register_entity & reg, HP_entity & hp);
    
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
    
    bool arrayIsEmpty(int arg);
    int charArrayToInt(char arr[3], int len);
    void clearArray(char arr[3], int len);
    
    void main() override{
        int remainTime;
        int timeStamp = hwlib::now_us();
        char key;
        int pn;
        int data;
        bool hasBeenInit = false;
    char playerNumber[4] = {' ', ' ', ' ', '\0'};
        char firePower[4] = {' ', ' ', ' ', '\0'};
        int i = 1;
        for (;;){
            switch(state){
                case 0:
                    wait(KeyPressedFlag);
                        key = getKeyValueChannel();
                        if (key == 'A'){
                            oled.printIndicator('A');
                            oled.printPlayerNumberSetup();
                            oled.flush();
                            
                            while(i == 1){
                                    while( key != 'B' ){
                                        wait(KeyPressedFlag);
                                        key = getKeyValueChannel();
                                            if (key >= '0' && key <= '9'){
                                                playerNumber[playerNumberSize++] = key;
                                                oled.printIndicator(playerNumber[0], playerNumber[1]);
                                                oled.flush();
                                            }else{
//                                                clearArray(playerNumber, playerNumberSize);
//                                                playerNumberSize = 0;
                                            }
                                        
                                    }
                                reg.setPN(charArrayToInt(playerNumber, playerNumberSize));
                                hwlib::cout << "pn: " << reg.getPN(); 
                                oled.printFirePowerSetup();
                                oled.flush();
                                key = ' ';
                                    while( key != 'B' ){
                                        wait(KeyPressedFlag);
                                        key = getKeyValueChannel();
                                            if (key >= '0' && key <= '9'){
                                                firePower[firePowerSize++] = key;
                                                oled.printIndicator(firePower[0], firePower[1]);
                                                oled.flush();
                                            }else{
//                                                clearArray(firePower, firePowerSize);
//                                                firePowerSize = 0;
                                            }
                                    }
                                reg.setFP(charArrayToInt(firePower, firePowerSize));
                                hwlib::cout << "fp: " << reg.getFP();
                                
                                hwlib::cout << "waiting for gameleader";
                                    while(pn != 0){
                                        wait(ReceiveFlag);
                                        data = getMessageChannelData();
                                        pn = getMessageChannelPN();
                                    }
                                reg.setDU(data*60);
                                hwlib::cout << "du: " << reg.getDU();
                                
                                pn = 10;
                                data = 10;
                                
                                while(pn != 0 && data != 0){
                                    wait(ReceiveFlag);
                                    pn = getMessageChannelPN();
                                    data = getMessageChannelData();
                                }
                                state = 1;
                                hwlib::cout << "Game started";
                                i = 0;
                            }
                        }    
                    break;
                
                case 1:
                remainTime = timePassed(timeStamp);
                    if ( hasBeenInit == false ){
                        oled.printPlayerNumber( reg.getPN() );
                        oled.printHP_DU(hp.getHP(), reg.getDU());
                        oled.flush();
                        hasBeenInit = true;
                    }
                    
                    if(remainTime <= 0){
                        hwlib::cout << 'e';
                    }
                    const rtos::event & evt_rungame = wait();
                    if (evt_rungame == ReceiveFlag){
                        pn = getMessageChannelPN();
                        data = getMessageChannelData();
                        hp.setHP( hp.getHP() - data );
                    }else if (evt_rungame == KeyPressedFlag){
                        key = getKeyValueChannel();
                        switch(key){
                            case '*':
                                ir_send.setSendChannel(0);
                                ir_send.setSendFlag();
                                hwlib::wait_ms(100);
                                beeper.setSoundPool(1);
                                beeper.setSoundFlag();
                                oled.printHP_DU(hp.getHP(), remainTime);
                                oled.flush();
                                break;
                        }
                    }
                    break;    
                
                
                }
            }
    }
    
    
    
    
};







#endif //RUN_GAME_TASK_HPP
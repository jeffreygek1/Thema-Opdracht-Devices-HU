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
        char playerNumber[4];
        char firePower[4];
        for (;;){
            remainTime = timePassed(timeStamp);
            switch(state){
                case 0:
                    wait(KeyPressedFlag);
                        key = getKeyValueChannel();
                        if (key == 'A'){
                            oled.printIndicator('A');
                            oled.flush();
                            while(true){
                                wait(KeyPressedFlag);
                                    key = getKeyValueChannel();
                                    while( key != 'B' && arrayIsEmpty(playerNumberSize) ){
                                        wait(KeyPressedFlag);
                                        key = getKeyValueChannel();
                                            if (key >= '0' && key <= '9' && charArrayToInt(playerNumber, playerNumberSize) < 32 ){
                                                playerNumber[playerNumberSize++] = key;
                                                if(playerNumberSize > 1){
                                                    oled.printIndicator(playerNumber[0], playerNumber[1]);
                                                    oled.flush();
                                                }else{
                                                    oled.printIndicator(playerNumber[0]);
                                                    oled.flush();
                                                }
                                            }else{
                                                clearArray(playerNumber, playerNumberSize);
                                                playerNumberSize = 0;
                                            }
                                    }
                                reg.setPN(charArrayToInt(playerNumber, playerNumberSize));
                                wait(KeyPressedFlag);
                                    key = getKeyValueChannel();
                                    while( key != 'B' && arrayIsEmpty(firePowerSize) ){
                                        wait(KeyPressedFlag);
                                        key = getKeyValueChannel();
                                            if (key >= '0' && key <= '9' && charArrayToInt(firePower, firePowerSize) < 32 ){
                                                firePower[firePowerSize++] = key;
                                                if(playerNumberSize > 1){
                                                    oled.printIndicator(firePower[0], firePower[1]);
                                                    oled.flush();
                                                }else{
                                                    oled.printIndicator(firePower[0]);
                                                    oled.flush();
                                                }
                                            }else{
                                                clearArray(firePower, firePowerSize);
                                                firePowerSize = 0;
                                            }
                                    }
                                reg.setFP(charArrayToInt(firePower, firePowerSize));
                                wait(ReceiveFlag);
                                    pn = getMessageChannelPN();
                                    data = getMessageChannelData();
                                    while(pn != 0 && data == 0){
                                        wait(ReceiveFlag);
                                        pn = getMessageChannelPN();
                                        data = getMessageChannelData();
                                    }
                                reg.setDU(data*60);
                                while(pn != 0 && data != 0){}
                                state = 1;
                                break;
                            }
                        }    
                    break;
                
                case 1:
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
                        hwlib::cout << 'r';
                        hp.setHP( hp.getHP() - data );
                    }else if (evt_rungame == KeyPressedFlag){
                        key = getKeyValueChannel();
                        switch(key){
                            case '*':
                                ir_send.setSendFlag();
                                ir_send.setSendChannel(0);
                                beeper.setSoundFlag();
                                beeper.setSoundPool(1);
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
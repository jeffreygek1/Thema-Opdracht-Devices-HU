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
    
    void countDown(int dur);
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
        int timeStamp;
		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GameParameters STD : Initializing Register sequence
//	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
        char key;
        int pn;
        int data;
        bool hasBeenInit = false;
		char playerNumber[4] = {' ', ' ', ' ', '\0'};
        char firePower[4] = {' ', ' ', ' ', '\0'};
        int i = 1;
        for (;;){
            switch(state){
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GameParameters STD : Initializing Player sequence
//	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                case 0:
				
                    oled.printStartInit();
                    oled.flush();
                    wait(KeyPressedFlag);
                        key = getKeyValueChannel();
                        if (key == 'A'){
                            oled.clear();
                            oled.printIndicator(' ');
                            oled.printPlayerNumberSetup();
                            oled.flush();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GameParameters STD : Registering Player Number
//	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                            
                            while(i == 1){
                                    while( key != 'B' ){
                                        wait(KeyPressedFlag);
                                        key = getKeyValueChannel();
                                            if (key >= '0' && key <= '9'){
                                                playerNumber[playerNumberSize++] = key;
                                                oled.printIndicator(playerNumber[0], playerNumber[1]);
                                                oled.flush();
                                            }else{}
                                        
                                    }
                                reg.setPN(charArrayToInt(playerNumber, playerNumberSize));
                                oled.printFirePowerSetup();
                                oled.printIndicator(' ');
                                oled.flush();
								
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GameParameters STD : Registering Fire Power
//	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
                                key = ' ';
                                    while( key != 'B' ){
                                        wait(KeyPressedFlag);
                                        key = getKeyValueChannel();
                                            if (key >= '0' && key <= '9'){
                                                firePower[firePowerSize++] = key;
                                                oled.printIndicator(firePower[0], firePower[1]);
                                                oled.flush();
                                            }else{}
                                    }
                                reg.setFP(charArrayToInt(firePower, firePowerSize));
                                 oled.clear();
                                oled.printWaitingForCommand();
                                oled.flush();
                                    while(pn != 0){
                                        wait(ReceiveFlag);
                                        data = getMessageChannelData();
                                        pn = getMessageChannelPN();
                                    }
                                reg.setDU(data*60);
                                pn = 10;
                                data = 10;
                                oled.clear();
                                oled.printWaitingForCommand();
                                oled.flush();
                                while(pn != 0 && data != 0){
                                    wait(ReceiveFlag);
                                    pn = getMessageChannelPN();
                                    data = getMessageChannelData();
                                }
                                oled.clear();
                                state = 1;
                                countDown(5);
                                timeStamp = hwlib::now_us();
                                i = 0;
                                
                            }
                        }    
                    break;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GameParameters STD : End
//	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	                
                
				
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// RunGame STD : Start
//	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////					
				case 1:
                    remainTime = timePassed(timeStamp);
                    if ( hasBeenInit == false ){
                        oled.printPlayerNumber( reg.getPN() );
                        oled.printHP_DU(hp.getHP(), reg.getDU());
                        oled.flush();
                        hasBeenInit = true;
                    }
                    
                    if(remainTime <= 0 || hp.getHP() <= 0){
                        oled.clear();
                        oled.printGameOver();
                        oled.flush();
                        beeper.setSoundPool(2);
                        beeper.setSoundFlag();
                        while(1==1){}
                    }else{
                        const rtos::event & evt_rungame = wait();
                        if (evt_rungame == ReceiveFlag){
                            pn = getMessageChannelPN();
                            data = getMessageChannelData();
                            hp.setHP( hp.getHP() - data );
                            beeper.setSoundPool(3);
                            beeper.setSoundFlag();
                            oled.printHP_DU(hp.getHP(), remainTime);
                            oled.flush();
                        }else if (evt_rungame == KeyPressedFlag){
                            key = getKeyValueChannel();
                            
                            switch(key){
                                case '*':
                                    ir_send.setSendChannel(0);
                                    ir_send.setSendFlag();
                                    hwlib::wait_ms(100);
                                    beeper.setSoundPool(1);
                                    beeper.setSoundFlag();
                                    break;
                            }
                            
                        }
                    }
                    break; 
                }
            }
    }
    
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// RunGame STD : End
//	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	    
    
    
};







#endif //RUN_GAME_TASK_HPP
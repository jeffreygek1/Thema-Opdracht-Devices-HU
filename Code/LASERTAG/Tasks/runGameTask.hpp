/// \file runGameTask.hpp
/// The runGameTask file,
/// contains the run game controller object declaration
/// Date file created:
/// \date 06-11-2017
/// Date last modified:
/// \date 08-11-2017
#ifndef RUN_GAME_TASK_HPP
#define RUN_GAME_TASK_HPP

#include "bmptk.h"
#include "hwlib.hpp"
#include "rtos.hpp"
#include "beeperTask.hpp"
#include "irSendTask.hpp"
#include "oledController.hpp"
#include "registerEntity.hpp"
#include "hpEntity.hpp"

/**
 * @author Arsalan Anwari
 * @author Leon Zhang
 * @date 08/11/2017
 * 
 * @brief This Cpntrol object handles all the communication between other control objects
 * 
 * This object is like a mother task 
 */
class runGameController: public rtos::task<>{
private:
    beeperController & beeperControl;
    irSendController & irSend;
    oledController & oledControl;
    registerEntity & reg;
    hpEntity & hp;
    int state = 0;
    int playerNumberSize = 0;
    int firePowerSize = 0;
    rtos::channel< char, 10 > keyValueChannel;
    rtos::channel<int, 10> messageChannelPN;
    rtos::channel<int, 10> messageChannelData;
    rtos::flag keyPressedFlag;
    rtos::flag receiveFlag;
    rtos::timer coolDownTimer;
public: 
    runGameController( beeperController & beeperControl, irSendController & irSend, oledController & oledControl, registerEntity & reg, hpEntity & hp);
    
    void countDown(int dur);
    void showPlayersHitBy();
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
				
                    oledControl.printStartInit();
                    oledControl.flush();
                    wait(keyPressedFlag);
                        key = getKeyValueChannel();
                        if (key == 'A'){
                            oledControl.clear();
                            oledControl.printIndicator(' ');
                            oledControl.printPlayerNumberSetup();
                            oledControl.flush();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GameParameters STD : Registering Player Number
//	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                            
                            while(i == 1){
                                    while( key != 'B' ){
                                        wait(keyPressedFlag);
                                        key = getKeyValueChannel();
                                            if (key >= '0' && key <= '9'){
                                                playerNumber[playerNumberSize++] = key;
                                                oledControl.printIndicator(playerNumber[0], playerNumber[1]);
                                                oledControl.flush();
                                            }else{}
                                        
                                    }
                                reg.setPN(charArrayToInt(playerNumber, playerNumberSize));
                                oledControl.printFirePowerSetup();
                                oledControl.printIndicator(' ');
                                oledControl.flush();
								
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GameParameters STD : Registering Fire Power
//	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
                                key = ' ';
                                    while( key != 'B' ){
                                        wait(keyPressedFlag);
                                        key = getKeyValueChannel();
                                            if (key >= '0' && key <= '9'){
                                                firePower[firePowerSize++] = key;
                                                oledControl.printIndicator(firePower[0], firePower[1]);
                                                oledControl.flush();
                                            }else{}
                                    }
                                reg.setFP(charArrayToInt(firePower, firePowerSize));
								oledControl.clear();
                                oledControl.printWaitingForCommand();
                                oledControl.flush();
                                    while(pn != 0){
                                        wait(receiveFlag);
                                        data = getMessageChannelData();
                                        pn = getMessageChannelPN();
                                    }
                                reg.setDU(data*60);
                                pn = 10;
                                data = 10;
                                oledControl.clear();
                                oledControl.printWaitingForCommand();
                                oledControl.flush();
                                while(pn != 0 && data != 0){
                                    wait(receiveFlag);
                                    pn = getMessageChannelPN();
                                    data = getMessageChannelData();
                                }
                                oledControl.clear();
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
                        oledControl.printPlayerNumber( reg.getPN() );
                        oledControl.printHPDu(hp.getHP(), reg.getDU());
                        oledControl.flush();
                        hasBeenInit = true;
                    }
                    
                    if(remainTime <= 0 || hp.getHP() <= 0){
                        oledControl.clear();
                        oledControl.printGameOver();
                        oledControl.flush();
                        beeperControl.setSoundPool(2);
                        beeperControl.setSoundFlag();
                        showPlayersHitBy();
                        while(1==1){}
                    }else{
                        const rtos::event & evtRungame = wait();
                        if (evtRungame == receiveFlag){
                            pn = getMessageChannelPN();
                            reg.playerReg[reg.playerRegSize++] = pn;
                            data = getMessageChannelData();
                            hp.setHP( hp.getHP() - data );
                            beeperControl.setSoundPool(3);
                            beeperControl.setSoundFlag();
                            oledControl.printHPDu(hp.getHP(), remainTime);
                            oledControl.flush();
                            coolDownTimer.set(3'000'000);
                            wait(coolDownTimer);
                        }else if (evtRungame == keyPressedFlag){
                            key = getKeyValueChannel();
                            
                            switch(key){
                                case '*':
                                    irSend.setSendChannel(0);
                                    irSend.setSendFlag();
                                    hwlib::wait_ms(100);
                                    beeperControl.setSoundPool(1);
                                    beeperControl.setSoundFlag();
                                    coolDownTimer.set(reg.getFP() * 100'000 );
                                    wait(coolDownTimer);
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
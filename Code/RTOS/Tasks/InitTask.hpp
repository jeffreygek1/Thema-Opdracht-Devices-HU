#ifndef INITTASK_HPP
#define INITTASK_HPP

#include "bmptk.h"
#include "hwlib.hpp"
#include "rtos.hpp"
#include "IRSendTask.hpp"
#include "OLED_Controller.hpp"

class Init_Game_Controller: public rtos::task<>{
private:
    IR_Send_Controller & ir_send;
    OLED_Controller & oled;
    int state = 0;
    int command, key_int;
//    rtos::flag GameStartedFlag;
    rtos::channel< char, 10 > KeyValueChannel;
    rtos::flag KeyPressedFlag;
public: 
    Init_Game_Controller( IR_Send_Controller & ir_send, OLED_Controller & oled);
    
    //void setGameStartedFlag();
    char getKeyValueChannel();
    void setKeyValueChannel(char key);
    void setKeyPressedFlag();
    int KeyToInt(char key);
    
    void main() override{
        char key;
        for (;;){
            wait(KeyPressedFlag);
            if( getKeyValueChannel() == 'c' ){
                command = 0;
                for(;;){
                    oled.printCommand(command);
                    oled.flush();
                    wait(KeyPressedFlag);
                    key = getKeyValueChannel();
                    if( key == '#' && command >= 0 && command <= 15){
                        for(;;){
                            wait(KeyPressedFlag);
                            key = getKeyValueChannel();
                            if(key == '#'){
                                ir_send.setSendFlag();
                                ir_send.setSendChannel(command);
                                for(;;){
                                    //ir_send.setSendFlag();
                                    //ir_send.setSendChannel(command);
                                    wait(KeyPressedFlag);
                                    key = getKeyValueChannel();
                                    if( key == '*'){
                                        oled.printCommand(0);
                                        oled.flush();
                                        for(;;){
                                            wait(KeyPressedFlag);
                                            key = getKeyValueChannel();
                                            if(key == '*'){
                                                oled.printCommand(0);
                                                oled.flush();
                                            }
                                        }
                                    }
                                    else if (key == '#'){
                                        ir_send.setSendFlag();
                                        ir_send.setSendChannel(command);
                                    }
                                }
                            }
                        }
                    }
                    else if (key >= '0' && key <= '9'){
                        key_int = KeyToInt(key);
                        command = command * 10 + key_int;
                    }
                }
            }
        }
    }
};


#endif // INITTASK_HPP

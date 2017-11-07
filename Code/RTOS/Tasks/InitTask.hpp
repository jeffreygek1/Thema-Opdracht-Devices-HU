#ifndef INIT_GAME_CONTROLLER_HPP
#define INIT_GAME_CONTROLLER_HPP

#include "bmptk.h"
#include "hwlib.hpp"
#include "rtos.hpp"
#include "IRSendTask.hpp"
#include "OLED_Controller.hpp"

class Init_Game_Controller: public rtos::task<>{
private:
    IR_Send_Controller & ir_send;
    OLED_Controller & oled;
    int command, key_int;
    char key;
    rtos::channel< char, 10 > keyValueChannel;
    rtos::flag keyPressedFlag;
public: 
    Init_Game_Controller( IR_Send_Controller & ir_send, OLED_Controller & oled);
    
    char getKeyValueChannel();
    void setKeyValueChannel(char key);
    void setKeyPressedFlag();
    int keyToInt(char key);
    
    void main() override{
        hwlib::cout<< "Started";
        oled.printGameleader();
        oled.printCmd(0);
        oled.flush();
        for (;;){
            wait(keyPressedFlag);
            if( getKeyValueChannel() =='C' ){
                command = 0;
                for(;;){
                    oled.printCmd(command);
                    oled.flush();
                    wait(keyPressedFlag);
                    key = getKeyValueChannel();
                    if( key == '#' && command >= 0 && command <= 15){
                        for(;;){
                            if(key == '#'){
                                ir_send.setSendFlag();
                                ir_send.setSendChannel(command);
                                hwlib::wait_ms(100);
                                oled.printSend(command);
                                oled.flush();
                                hwlib::wait_ms(2000);
                                oled.printCmd(command);
                                oled.flush();
                                for(;;){
                                    wait(keyPressedFlag);
                                    key = getKeyValueChannel();
                                    if( key == '*'){
                                        oled.printCmd(0);
                                        oled.flush();
                                        ir_send.setSendFlag();
                                        ir_send.setSendChannel(0);
                                        hwlib::wait_ms(2000);
                                        oled.printSend(0);
                                        oled.flush();
                                        for(;;){
                                            wait(keyPressedFlag);
                                            key = getKeyValueChannel();
                                            if(key == '*'){
                                                oled.printCmd(0);
                                                oled.flush();
                                                ir_send.setSendFlag();
                                                ir_send.setSendChannel(0);
                                                hwlib::wait_ms(2000);
                                                oled.printSend(0);
                                                oled.flush();
                                            }
                                        }
                                    }
                                    else if (key == '#'){
                                        ir_send.setSendFlag();
                                        ir_send.setSendChannel(command);
                                        hwlib::wait_ms(100);
                                        oled.printSend(command);
                                        oled.flush();
                                        hwlib::wait_ms(2000);
                                        oled.printCmd(command);
                                        oled.flush();
                                    }
                                }
                            }
                        }
                    }
                    else if (key >= '0' && key <= '9'){
                        key_int = keyToInt(key);
                        command = command * 10 + key_int;
                    }
                }
            }
        }
    }
};

#endif // INIT_GAME_CONTROLLER_HPP

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
    int state = 0;
    int Command, key_int;
    rtos::channel< char, 10 > KeyValueChannel;
    rtos::flag KeyPressedFlag;
public: 
    Init_Game_Controller( IR_Send_Controller & ir_send, OLED_Controller & oled);
    
    char getKeyValueChannel();
    void setKeyValueChannel(char key);
    void setKeyPressedFlag();
    int KeyToInt(char key);
    
    void main() override{
        char key;
        hwlib::cout<< "Started";
        oled.printGameleader();
        oled.printCmd(0);
        oled.flush();
        
        for (;;){
            wait(KeyPressedFlag);
            if( getKeyValueChannel() =='C' ){
                Command = 0;
                for(;;){
                    oled.printCmd(Command);
                    oled.flush();
                    wait(KeyPressedFlag);
                    key = getKeyValueChannel();
                    if( key == '#' && Command >= 0 && Command <= 15){
                        for(;;){
                            if(key == '#'){
                                ir_send.setSendFlag();
                                ir_send.setSendChannel(Command);
                                hwlib::wait_ms(100);
                                oled.printSend(Command);
                                oled.flush();
                                hwlib::wait_ms(2000);
                                oled.printCmd(Command);
                                oled.flush();
                                for(;;){
                                    wait(KeyPressedFlag);
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
                                            wait(KeyPressedFlag);
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
                                        ir_send.setSendChannel(Command);
                                        hwlib::wait_ms(100);
                                        oled.printSend(Command);
                                        oled.flush();
                                        hwlib::wait_ms(2000);
                                        oled.printCmd(Command);
                                        oled.flush();
                                    }
                                }
                            }
                        }
                    }
                    else if (key >= '0' && key <= '9'){
                        key_int = KeyToInt(key);
                        Command = Command * 10 + key_int;
                    }
                }
            }
        }
    }
};

#endif // INIT_GAME_CONTROLLER_HPP

/// \file initTask.hpp
/// The initTask file,
/// contains the init control object declaration
/// Date file created:
/// \date 06-11-2017
/// Date last modified:
/// \date 08-11-2017

#ifndef INIT_GAME_CONTROLLER_HPP
#define INIT_GAME_CONTROLLER_HPP

#include "bmptk.h"
#include "hwlib.hpp"
#include "rtos.hpp"
#include "irSendTask.hpp"
#include "oledController.hpp"

/**
 * @author Jeffrey van der Waal
 * @author Leon Zhang
 * @author Arsalan Anwari
 * @date 08/11/2017
 * 
 * @brief This control object is used by the game leader to start the game
 * 
 */
class initGameController: public rtos::task<>{
private:
    irSendController & irSend;
    oledController & oledControl;
    int command, keyInt;
    char key;
    rtos::channel< char, 10 > keyValueChannel;
    rtos::flag keyPressedFlag;
public: 
    initGameController( irSendController & irSend, oledController & oledControl);
    
	/**
	 * @brief This function returns the head of the keyValueChannel
	 * @return char
	 */
    char getKeyValueChannel();
    /**
     * @brief This function is used to write to the keyValueChannel 
     * @param key: char
     */
	void setKeyValueChannel(char key);
	/**
	 * @brief This function can be used to set the keyPressedFlag
	 */
    void setKeyPressedFlag();
	/**
	 * @brief This function converts a key value(char) to an int
	 * @param key: char
	 * @return int
	 */
    int keyToInt(char key);
    
    void main() override{
        oledControl.printGameleader();
        oledControl.printCmd(0);
        oledControl.flush();
        for (;;){
            wait(keyPressedFlag);
            if( getKeyValueChannel() =='C' ){
                command = 0;
                for(;;){
                    oledControl.printCmd(command);
                    oledControl.flush();
                    wait(keyPressedFlag);
                    key = getKeyValueChannel();
                    if( key == '#' && command > 0 && command <= 15){
                        for(;;){
                            if(key == '#'){
                                irSend.setSendFlag();
                                irSend.setSendChannel(command);
                                hwlib::wait_ms(100);
                                oledControl.printSend(command);
                                oledControl.flush();
                                hwlib::wait_ms(2000);
                                oledControl.printCmd(command);
                                oledControl.flush();
                                for(;;){
                                    wait(keyPressedFlag);
                                    key = getKeyValueChannel();
                                    if( key == '*'){
                                        oledControl.printCmd(0);
                                        oledControl.flush();
                                        irSend.setSendFlag();
                                        irSend.setSendChannel(0);
                                        hwlib::wait_ms(2000);
                                        oledControl.printSend(0);
                                        oledControl.flush();
                                        for(;;){
                                            wait(keyPressedFlag);
                                            key = getKeyValueChannel();
                                            if(key == '*'){
                                                oledControl.printCmd(0);
                                                oledControl.flush();
                                                irSend.setSendFlag();
                                                irSend.setSendChannel(0);
                                                hwlib::wait_ms(2000);
                                                oledControl.printSend(0);
                                                oledControl.flush();
                                            }
                                        }
                                    }
                                    else if (key == '#'){
                                        irSend.setSendFlag();
                                        irSend.setSendChannel(command);
                                        hwlib::wait_ms(100);
                                        oledControl.printSend(command);
                                        oledControl.flush();
                                        hwlib::wait_ms(2000);
                                        oledControl.printCmd(command);
                                        oledControl.flush();
                                    }
                                }
                            }
                        }
                    }
                    else if (key >= '0' && key <= '9'){
                        keyInt = keyToInt(key);
                        command = command * 10 + keyInt;
                    }
                }
            }
        }
    }
};

#endif // INIT_GAME_CONTROLLER_HPP

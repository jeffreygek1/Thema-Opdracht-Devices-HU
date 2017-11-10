/// \file irSendTask.hpp
/// The irSendTask file,
/// contains the ir send controller object declaration
/// Date file created:
/// \date 06-11-2017
/// Date last modified:
/// \date 08-11-2017
#ifndef IR_SEND_CONTROLLER_HPP
#define IR_SEND_CONTROLLER_HPP

#include "irLed.hpp"
#include "registerEntity.hpp"
#include "bmptk.h"
#include "rtos.hpp"
#include "hwlib.hpp"

/**
 * @author Arsalan Anwari
 * @date 08/11/2017
 * 
 * @brief This control object handles the ir led to send encoded messages
 * 
 * This object is used by the run game task 
 */
class irSendController : public rtos::task<> 
{
private:
	irLed & irLed1;
    registerEntity & reg;
    rtos::channel< int, 10 > sendChannel;
    rtos::flag sendFlag;
    int message;
    int checksum;
    int send;
    int signal;
public:
    irSendController(irLed & irLed1, registerEntity & reg);
    
	/**
	 * @brief This function is used to send a encoded message by turining the ir led on and off in a certain pattern
	 * @param signal: int
	 */
	void sendSignal(int signal);
    /**
     * @brief This function is used to encoded a message that can be send by the sendSignal operation
     * @param message: int
     * @return int 
     */
	int encodeSignal(int message);
    
	/**
	 * @brief This function is used to write in the sendChannel
	 * @param value: int
	 */
    void setSendChannel(int value);
    /**
     * @brief This function returns the head of the sendChannel
     * @return int
     */
	int getSendChannel();
    /**
     * @brief This function is used to set the sendFlag. 
     */
	void setSendFlag();
    
    void main() override{
        for(;;){
            wait(sendFlag);
            signal = encodeSignal(getSendChannel());
            for(send = 0; send < 2; send++){
                sendSignal(signal);
            }
        }
    }
};

#endif // IR_SEND_CONTROLLER_HPP
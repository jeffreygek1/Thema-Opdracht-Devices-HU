#ifndef IR_SEND_CONTROLLER_HPP
#define IR_SEND_CONTROLLER_HPP

#include "IR_LED.hpp"
#include "Register_entity.hpp"
#include "bmptk.h"
#include "rtos.hpp"
#include "hwlib.hpp"

class IR_Send_Controller : public rtos::task<> 
{
private:
	IR_LED & ir_led;
    Register_entity & reg;
    rtos::channel< int, 10 > sendChannel;
    rtos::flag sendFlag;
    int message;
    int checksum;
    int send;
    int signal;
public:
    IR_Send_Controller(IR_LED & ir_led, Register_entity & reg);
    void sendSignal(int signal);
    int encodeSignal(int message);
    
    void setSendChannel(int value);
    int getSendChannel();
    void setSendFlag();
    
    void main() override{
        for(;;){
            wait(sendFlag);
            signal = encodeSignal(getSendChannel());
            //hwlib::cout << signal;
            for(send = 0; send < 2; send++){
                sendSignal(signal);
            }
        }
    }
};

#endif // IR_SEND_CONTROLLER_HPP
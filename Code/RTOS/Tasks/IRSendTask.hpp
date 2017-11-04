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
    rtos::channel< int, 10 > SendChannel;
    rtos::flag SendFlag;
    int Message;
    int checksum;
public:
    IR_Send_Controller(IR_LED & ir_led, Register_entity & reg);
    void send_signal(int signal);
    int encode_signal(int Message);
    
    void setSendChannel(int value);
    int getSendChannel();
    void setSendFlag();
    
    void main() override{
         int signal;
        for(;;){
                wait(SendFlag);
                    signal = encode_signal(getSendChannel());
                    send_signal(signal);
                    //hwlib::cout << "send: " << signal << "\n";
                    //send_signal(signal);
                //hwlib::wait_us(100);
            }
        
    }
};

#endif // IR_SEND_CONTROLLER_HPP
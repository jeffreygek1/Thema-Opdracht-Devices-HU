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
    Register_entity & register_entity;
    rtos::channel< int, 10 > MessageChannel;
    rtos::flag MessageFlag;
    rtos::timer IRTimer;
    int Message;
    int checksum;
public:
    IR_Send_Controller(IR_LED & ir_led, Register_entity & register_entity);
    void send_signal(int signal);
    int encode_signal(int Message);
    
    void setMessageChannel(int value);
    int getMessageChannel();
    void setMessageFlag();
    
    void main() override{
         int signal;
        for(;;){
                wait(MessageFlag);
                    signal = encode_signal(getMessageChannel());
                    send_signal(signal);
                    hwlib::cout << signal << "\n";
                    //send_signal(signal);
                hwlib::wait_us(50);
            }
        
    }
};

#endif // IR_SEND_CONTROLLER_HPP
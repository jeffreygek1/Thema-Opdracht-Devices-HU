#ifndef IR_SEND_CONTROLLER_HPP
#define IR_SEND_CONTROLLER_HPP

#include "IR_LED.hpp"
#include "Register_entity.hpp"

class IR_Send_Controller

{
private:
	IR_LED & ir_led;
    int Message;
    int checksum;
public:
    IR_Send_Controller(IR_LED & ir_led):ir_led(ir_led){}
    void send_signal(int signal);
    int encode_signal(int & data, Register_entity & register_entity);
};

#endif // IR_SEND_CONTROLLER_HPP

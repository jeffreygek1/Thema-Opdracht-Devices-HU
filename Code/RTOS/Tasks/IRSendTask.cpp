#include "IRSendTask.hpp"

IR_Send_Controller::IR_Send_Controller(IR_LED & ir_led, Register_entity & reg):
    task(1, "IRSendTask"),
    ir_led(ir_led),
    reg(reg),
    SendChannel( this, "SendChannel" ),
    SendFlag(this, "SendFlag")
{}

void IR_Send_Controller::send_signal( int signal )
{
    for (int i=0; i<16; ++i)
    {
        if (signal & 0x8000)
        {
            ir_led.set(1);
            hwlib::wait_us(1600);
            ir_led.set(0);
            hwlib::wait_us(800);
        } 
        else
        {
            ir_led.set(1);
            hwlib::wait_us(800);
            ir_led.set(0);
            hwlib::wait_us(1600);
        }
        signal = signal << 1;
    }
}
/// \brief This function encodes the signal
//
/// \details This function takes the checksum from the previous function and constructs the signal according
/// to the IR protocol assigned to this assignment. This value is returned for further use. 
int IR_Send_Controller::encode_signal(int Message)
{
    if(reg.getPN() != 0){
        Message = reg.getFP();
    }
    int checksum = (reg.getPN()^Message);
    return ((1<<15)|(reg.getPN()<<10)|(Message<<5)|checksum);
}

void IR_Send_Controller::setSendChannel(int value){
    SendChannel.write(value);
}

int IR_Send_Controller::getSendChannel(){
    int value = SendChannel.read();
    return value;
}

void IR_Send_Controller::setSendFlag(){
    SendFlag.set();
}
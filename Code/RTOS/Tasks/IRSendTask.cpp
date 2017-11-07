#include "IRSendTask.hpp"

IR_Send_Controller::IR_Send_Controller(IR_LED & ir_led, Register_entity & reg):
    task(1, "IRSendTask"),
    ir_led(ir_led),
    reg(reg),
    sendChannel( this, "SendChannel" ),
    sendFlag(this, "SendFlag")
{}

void IR_Send_Controller::sendSignal( int signal )
{
    for (int bitsSend=0; bitsSend<16; ++bitsSend)
    {
        if (signal & 0x8000)
        {
            //hwlib::cout << '1';
            ir_led.set(1);
            hwlib::wait_us(1600);
            ir_led.set(0);
            hwlib::wait_us(800);
        } 
        else
        {
            //hwlib::cout << '0';
            ir_led.set(1);
            hwlib::wait_us(800);
            ir_led.set(0);
            hwlib::wait_us(1600);
        }
        signal = signal << 1;
    }
}

int IR_Send_Controller::encodeSignal(int message)
{
    if(reg.getPN() != 0){
        message = reg.getFP();
    }
    int checksum = (reg.getPN()^message);
    return ((1<<15)|(reg.getPN()<<10)|(message<<5)|checksum);
}

void IR_Send_Controller::setSendChannel(int value){
    sendChannel.write(value);
}

int IR_Send_Controller::getSendChannel(){
    int value = sendChannel.read();
    return value;
}

void IR_Send_Controller::setSendFlag(){
    sendFlag.set();
}
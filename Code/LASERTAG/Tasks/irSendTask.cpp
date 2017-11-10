
/// \file irSendTask.cpp
/// The irSendTask file,
/// contains the ir send controller object definition
/// Date file created:
/// \date 06-11-2017
/// Date last modified:
/// \date 08-11-2017

#include "irSendTask.hpp"

irSendController::irSendController(irLed & irLed1, registerEntity & reg):
    task(1, "IRSendTask"),
    irLed1(irLed1),
    reg(reg),
    sendChannel( this, "SendChannel" ),
    sendFlag(this, "SendFlag")
{}

void irSendController::sendSignal( int signal )
{
    for (int bitsSend=0; bitsSend<16; ++bitsSend)
    {
        if (signal & 0x8000)
        {
            irLed1.set(1);
            hwlib::wait_us(1600);
            irLed1.set(0);
            hwlib::wait_us(800);
        } 
        else
        {
            irLed1.set(1);
            hwlib::wait_us(800);
            irLed1.set(0);
            hwlib::wait_us(1600);
        }
        signal = signal << 1;
    }
}

/**
 * @author Jeffrey de Waal
 */
int irSendController::encodeSignal(int message)
{
    if(reg.getPN() != 0){
        message = reg.getFP();
    }
    int checksum = (reg.getPN()^message);
    return ((1<<15)|(reg.getPN()<<10)|(message<<5)|checksum);
}

void irSendController::setSendChannel(int value){
    sendChannel.write(value);
}

int irSendController::getSendChannel(){
    int value = sendChannel.read();
    return value;
}

void irSendController::setSendFlag(){
    sendFlag.set();
}
#include "IR_Receiver.hpp"

IR_Receiver::IR_Receiver(hwlib::target::pin_in & tsopSignal, hwlib::target::pin_out  & tsopGnd, hwlib::target::pin_out & tsopVdd):
    tsopSignal(tsopSignal),
    tsopGnd(tsopGnd),
    tsopVdd(tsopVdd)
    {
        hwlib::wait_ms(100);
        setup();
    }
    
bool IR_Receiver::get(){
    return tsopSignal.get();
}


void IR_Receiver::setup(){
    hwlib::wait_ms(10);
    tsopGnd.set( 0 );
    tsopVdd.set( 1 );
}

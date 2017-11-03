#include "ir_receiver.hpp"

ir_receiver::ir_receiver(hwlib::target::pin_in & tsop_signal, hwlib::target::pin_out  & tsop_gnd, hwlib::target::pin_out & tsop_vdd):
    tsop_signal(tsop_signal),
    tsop_gnd(tsop_gnd),
    tsop_vdd(tsop_vdd)
    {
        hwlib::wait_ms(500);
        setup();
    }
    
bool ir_receiver::get(){
    return tsop_signal.get();
}


void ir_receiver::setup(){
    hwlib::wait_ms(10);
    tsop_gnd.set( 0 );
    tsop_vdd.set( 1 );
}
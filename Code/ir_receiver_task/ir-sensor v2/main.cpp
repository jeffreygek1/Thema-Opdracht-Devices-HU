#include "hwlib.hpp"
#include "ir_receiver.hpp"
#include "IR_Receiver_Controller.hpp"
#include "rtos.hpp"

int main( void ){	
    
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    auto tsop_signal = hwlib::target::pin_in( hwlib::target::pins::d8 );
    auto tsop_gnd    = hwlib::target::pin_out( hwlib::target::pins::d9 );
    auto tsop_vdd    = hwlib::target::pin_out( hwlib::target::pins::d10 );
    // wait for the PC terminal to start
    hwlib::wait_ms( 500 );
    
    ir_receiver receiver(tsop_signal, tsop_gnd, tsop_vdd);
    IR_Receiver_Controller Receiver_Controller(receiver);
    rtos::run();
}


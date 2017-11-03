#ifndef IR_RECEIVER_HPP
#define IR_RECEIVER_HPP

#include "hwlib.hpp"

class ir_receiver
{
private:
    hwlib::target::pin_in   & tsop_signal;
    hwlib::target::pin_out  & tsop_gnd;
    hwlib::target::pin_out  & tsop_vdd;
public:
    ir_receiver(hwlib::target::pin_in & tsop_signal , hwlib::target::pin_out & tsop_gnd, hwlib::target::pin_out & tsop_vdd);
    
    void setup();    
    bool get();

};

#endif //IR_RECEIVER_HPP
#ifndef IR_RECEIVER_HPP
#define IR_RECEIVER_HPP

#include "hwlib.hpp"

class IR_Receiver
{
private:
    hwlib::target::pin_in   & tsop_signal;
    hwlib::target::pin_out  & tsop_gnd;
    hwlib::target::pin_out  & tsop_vdd;
public:
    IR_Receiver(hwlib::target::pin_in & tsop_signal , hwlib::target::pin_out & tsop_gnd, hwlib::target::pin_out & tsop_vdd);
    
    void setup();    
    bool get();

};

#endif // IR_RECEIVER_HPP

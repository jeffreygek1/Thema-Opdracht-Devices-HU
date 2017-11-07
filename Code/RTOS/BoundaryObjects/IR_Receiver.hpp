#ifndef IR_RECEIVER_HPP
#define IR_RECEIVER_HPP

#include "hwlib.hpp"

class IR_Receiver
{
private:
    hwlib::target::pin_in   & tsopSignal;
    hwlib::target::pin_out  & tsopGnd;
    hwlib::target::pin_out  & tsopVdd;
public:
    IR_Receiver(hwlib::target::pin_in & tsopSignal , hwlib::target::pin_out & tsopGnd, hwlib::target::pin_out & tsopVdd);
    
    void setup();    
    bool get();

};

#endif // IR_RECEIVER_HPP

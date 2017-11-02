#ifndef IR_LED_HPP
#define IR_LED_HPP

#include "hwlib.hpp"
class IR_LED
{
private:
    hwlib::target::d2_36kHz &ir_led;
public: 
    IR_LED( hwlib::target::d2_36kHz &ir_led );
	void set(int Value);
};

#endif // IR_LED_HPP

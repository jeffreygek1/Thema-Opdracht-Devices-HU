#include "IR_LED.hpp"

IR_LED::IR_LED( hwlib::target::d2_36kHz &ir_led ): ir_led(ir_led)
{
    hwlib::wait_ms(500);
}

void IR_LED::set(int Value)
{
    ir_led.set( Value );
}

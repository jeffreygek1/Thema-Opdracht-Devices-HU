#include "IR_Send_Controller.hpp"
#include "Register_entity.hpp"

int main(int argc, char **argv)
{
// kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   // wait for the PC terminal to start
   hwlib::wait_ms( 500 );
   
   auto ir_led =  hwlib::target::d2_36kHz();
   
   IR_LED ir_send(ir_led);
   IR_Send_Controller ir_control(ir_send);
   Register_entity register_entity(1,1,0);
   int value = 5524;
   
   hwlib::wait_ms( 500 );
   for(int i = 0; i < 1; i++)
    {
            ir_control.send_signal(ir_control.encode_signal(value, register_entity)); 
            hwlib::cout << ir_control.encode_signal(value, register_entity) << "\n";
            hwlib::wait_ms(1000);
    }
   
}
